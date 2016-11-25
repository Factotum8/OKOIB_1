#include "wrfile.h"


WRFile::WRFile(QString nameFile, bool* flag)
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

            count_ir = calculate_count_ir_and_indexs(domElement);

            qDebug()<<"\ncount_ir: "<<count_ir;

            ir = new IR [count_ir];

            traverseNode(domElement);
        }
        file.close();
    }
    else
    {
        //    ErrorForm::showerror();
        *flag = 1;
    }
}

int WRFile::calculate_count_ir_and_indexs (const QDomNode& node)
{
    int count_ir=0;
    count_cost_index = 0;
    QString str;

    QDomNode domNode = node.firstChild();
    while(!domNode.isNull()) {
        if(domNode.isElement()) {
            QDomElement domElement = domNode.toElement();
            if(!domElement.isNull()) {
                if(domElement.tagName() == "info_resource") {

                    count_ir = domElement.attribute("number", "").toInt();

                }
                if(domElement.tagName() == "cost_index")
                {
                    count_cost_index++;
                }

            }
        }
        calculate_count_ir_and_indexs(domNode);
        domNode = domNode.nextSibling();
    }

    return count_ir;
}

void WRFile::traverseNode(const QDomNode& node)
{
    static int i=0,m=0,n=0,element_mass_index=0;

    QDomNode domNode = node.firstChild();

    while(!domNode.isNull()) {

        if(domNode.isElement()) {

            QDomElement domElement = domNode.toElement();

            if(!domElement.isNull())
            {
//                qDebug()<<"\ndomElement.tagName(): "<<domElement.tagName().toStdString();
                switch (this->get_numb_tag(domElement.tagName())) {

                case 0:
                    qDebug()<<"\nnumber ir: "<<domElement.attribute("number","").toInt();
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
                    ir[i].develop->set_consumables(ir[i].develop->get_years_develop());
                    break;

                case 8:

                    n = domElement.attribute("number", "").toInt()-1;
                    qDebug()<<"\n  case 8 year develop: "<<n;
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

                case 12:

                    m = domElement.attribute("number", "").toInt()-1;
                    ir[i].develop->get_number_employees()[m][n].tax = domElement.text().toInt();
                    qDebug()<<"\ndevelop employees tax"<<ir[i].develop->get_number_employees()[m][n].tax;
                    break;

                case 13:
                    ir[i].develop->get_consumables()[n] = domElement.text().toInt();
                    qDebug()<<"\nconsumables develop: "<<ir[i].develop->get_consumables()[n];
                    break;

                case 14:

                    ir[i].set_val_maintain(true);
                    ir[i].maintain = new Maintain;
                    break;

                case 15:

                    ir[i].maintain->count_employees=domElement.text().toInt();
                    ir[i].maintain->salory = new int[ir[i].maintain->count_employees];
                    ir[i].maintain->tax = new int[ir[i].maintain->count_employees];
                    qDebug()<<"maintain count employees: "<<ir[i].maintain->count_employees;
                    break;

                case 16:

                    ir[i].maintain->salory[domElement.attribute("number","").toInt()-1] = domElement.text().toInt();
                    break;

                case 17:

                    ir[i].maintain->tax[domElement.attribute("number","").toInt()-1] = domElement.text().toInt();
                    break;

                case 18:

                    ir[i].maintain->consumables = domElement.text().toInt();
                    break;

                case 19:

                    ir[i].set_val_acquire(true);
                    break;

                case 20:

                    ir[i].acquire.cost_first_year = domElement.text().toDouble();
                    qDebug()<<"\nacquire cost first year: "<<ir[i].acquire.cost_first_year ;
                    break;

                case 21:

                    c_index = new struct cost_index [count_cost_index];
                    qDebug()<<"\ncost cost index: "<<count_cost_index;
                    break;

                case 22:

                    c_index[element_mass_index].year.setDate(domElement.attribute("year","").toInt(),1,1);
                    c_index[element_mass_index].index = domElement.text().toInt();
                    qDebug()<<"\n year index: "<<c_index[element_mass_index].year.year()<<"  index: "<<c_index[element_mass_index].index;
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
