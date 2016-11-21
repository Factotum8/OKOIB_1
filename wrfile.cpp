#include "wrfile.h"

WRFile::WRFile(QString nameFile)
{
    const QMetaObject &mo = staticMetaObject;
    int idx = mo.indexOfEnumerator("Tag");
    tags = mo.enumerator(idx);

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

    /*   enum Tag {
        info_resource=0,         //0
        name =1,         //1
        first_year =2, //0
        planned_year =3,       //1
        develop =4,
        start_year =5,
        years_develop =6,
        year =7, // скорее всего переделаешь на year_develop
        employees =8,
        profit =9
    };*/

    QDomNode domNode = node.firstChild();

    while(!domNode.isNull()) {

        if(domNode.isElement()) {

            QDomElement domElement = domNode.toElement();

            if(!domElement.isNull())
            {
                switch (this->get_numb_tag(domElement.tagName())) {
                case 0:
                    i = domElement.attribute("number", "").toInt();
                    break;

                case 1:
                    ir[i].set_name(domElement.text());
                    break;

                case 2:

                    ir[i].set_first_year(QDate (domElement.text().toInt(),1,1));
                    break;
                case 3:
                    ir[i].set_planned_year(QDate(domElement.text().toInt(),1,1));
                    break;
                case 4:
                    ir[i].set_val_develop(true);
                    ir[i].develop = new Develop(0);
                    break;
                case 5:
                    ir[i].develop->set_first_year(domElement.text().toInt());
                    break;
                case 6:
                    ir[i].develop->set_years_develop(domElement.text().toInt());
                    break;
                case 7:

                    break;
                case 7:

                    break;
                case 7:

                    break;
                case 7:

                    break;

                case 7:

                    break;
                default:
                    break;
                }
            }
        }


        traverseNode(domNode);
        domNode = domNode.nextSibling();
    }
}


int WRFile::get_numb_tag(QString str)
{
    return  this->tags.keyToValue(str.toLocal8Bit().data());
}
