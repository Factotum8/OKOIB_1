#include "wrfile.h"

WRFile::WRFile(QString nameFile)
{
    QDomDocument domDoc;

    QFile file(nameFile);

    if (file.open(QIODevice::ReadOnly)){
        if(domDoc.setContent(&file)){

            QDomElement domElement = domDoc.documentElement();

            count_ir = calculate_count_ir(domElement);

            ir = new IR [count_ir];

            traverseNode(domElement);
        }
        file.close();
    }
}

int WRFile::calculate_count_ir (const QDomNode& node)
{
    int count_ir=0;

    QDomNode domNode = node.firstChild();
    while(!domNode.isNull()) {
        if(domNode.isElement()) {
            QDomElement domElement = domNode.toElement();
            if(!domElement.isNull()) {
                if(domElement.tagName() == "ir") {

                    count_ir = domElement.attribute("number", "").toInt();

                }

            }
        }
        calculate_count_ir(domNode);
        domNode = domNode.nextSibling();
    }

    return count_ir;
}

void WRFile::traverseNode(const QDomNode& node)
{
    int i=0;

    bool* flag= new bool;

    QMetaEnum metaEnum;

    QDomNode domNode = node.firstChild();

    while(!domNode.isNull()) {

        if(domNode.isElement()) {

            QDomElement domElement = domNode.toElement();

            if(!domElement.isNull())

            { // tag = metaEnum.keyToValue( domElement.tagName().toStdString().c_str(), flag );
                //tag =  domElement.tagName().toStdString().c_str();
//                tag = name;

//                switch (tag) {
//                case info_resource:
//                    i = domElement.attribute("number", "").toInt();
//                    break;

//                case name:
//                    ir[i].set_name(domElement.text());
//                    break;

//                case first_year:

//                    ir[i].set_first_year(QDate (domElement.text().toInt(),1,1));
//                    break;

//                case 7:

//                    break;
//                default:
//                    break;
//                }
            }
        }


        traverseNode(domNode);
        domNode = domNode.nextSibling();
    }
}


const QString WRFile::tag() const
{
    const QMetaObject &mo = WRFile::staticMetaObject;
    int index = mo.indexOfEnumerator("Type");
    QMetaEnum metaEnum = mo.enumerator(index);

    return metaEnum.valueToKey(tag);
}

void WRFile::setType(const QString &tag)
{
    const QMetaObject &mo = WRFile::staticMetaObject;

    int index = mo.indexOfEnumerator("Tag");
    QMetaEnum metaEnum = mo.enumerator(index);
    int value = metaEnum.keyToValue(qPrintable(tag));

    tag = static_cast<Tag>(value);
}
