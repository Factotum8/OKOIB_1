#include "wrfile.h"

WRFile::WRFile(QString nameFile)
{
    const QMetaObject &mo = staticMetaObject;
    int idx = mo.indexOfEnumerator("Tag");
    tags = mo.enumerator(idx);

    qDebug()<<"\n"<<nameFile;

    QDomDocument domDoc;

    QFile file(nameFile);

    if (file.open(QIODevice::ReadOnly)){
        if(domDoc.setContent(&file)){

            QDomElement domElement = domDoc.documentElement();

            count_ir = calculate_count_ir(domElement);

            qDebug()<<"\ncount_ir: "<<count_ir;

            ir = new IR [count_ir];

            traverseNode(domElement);
        }
        file.close();
    }
    else
    {
    ErrorForm::showerror();
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
                if(domElement.tagName() == "info_resource") {

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
    static int i=0,m=0,n=0;

    QDomNode domNode = node.firstChild();

    while(!domNode.isNull()) {

        if(domNode.isElement()) {

            QDomElement domElement = domNode.toElement();

            if(!domElement.isNull())
            {
                cout<<"\ndomElement.tagName(): "<<domElement.tagName().toStdString();
                switch (this->get_numb_tag(domElement.tagName())) {

                case 0:
                    qDebug()<<"\ncase 0 domElement.attribute: "<<domElement.attribute("number","").toInt();
                    i = domElement.attribute("number").toInt()-1;
                    qDebug()<<"\ncase 0 i: "<<i;
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
                    qDebug()<<"\n case 6 years_develop = "<<ir[i].develop->get_years_develop();
                    break;

                case 7:

                    ir[i].develop->init_number_employees(domElement.text().toInt(),ir[i].develop->get_years_develop());
                    break;

                case 8:
//                    qDebug()<<"\n  case 8 domElement.attribute: "<<domElement.attribute("number", "").toInt();
                    n = domElement.attribute("number", "").toInt()-1;
                    qDebug()<<"\n  case 8 domElement.attribute: "<<n;
                    break;

                case 9:

                    m = domElement.attribute("number", "").toInt()-1;
                    qDebug()<<"\n  case 9 m="<<m<<" n= "<<n;
                    ir[i].develop->get_number_employees()[m][n].salory = domElement.text().toInt();
                    break;

                case 10:

                    ir[i].profit.profit =domElement.text().toInt();
                    qDebug()<<"\ncase 10 domElement.text "<<ir[i].profit.profit;
                    break;

                case 11:
                    ir[i].set_this_year(QDate(domElement.text().toInt(),1,1));
                    break;
                default:

                     qDebug()<<"\nInknow tag: "<<domElement.tagName();
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


QString WRFile::regexp_numb(QString pnumb){

//    cout<<"\nStdstring"<<pnumb.toStdString();
        return pnumb.remove('\"');
}
