#include "formconsumablesdev.h"
#include "ui_formconsumablesdev.h"

FormConsumablesDev::FormConsumablesDev(int element,int count_years,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormConsumablesDev)
{
    ui->setupUi(this);

    this->element=element;
    this->count_years=count_years;
    this->flagbutt=0;

    ir[element].develop->set_consumables(count_years);

    ui->tableConsumables->setModel(new QStandardItemModel (1,count_years,parent));

    ui->tableConsumables->setItemDelegate(new ItemDelegateFloat(parent));

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->move(10,10);

}
FormConsumablesDev::FormConsumablesDev(int flagbutt,int element,int employees,QWidget *parent):
    QWidget(parent),
    ui(new Ui::FormConsumablesDev)
{
    ui->setupUi(this);

    this->element=element;
    this->count_employees=employees;
    this->flagbutt=flagbutt;

    delta_years=ir[element].get_this_year().year()-ir[element].get_first_year().year();

    ui->tableConsumables->setModel(new QStandardItemModel (1,employees,parent));

    ui->tableConsumables->setItemDelegate(new ItemDelegateFloat(parent));

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->move(10,10);

}

FormConsumablesDev::FormConsumablesDev (int flagbutt,QWidget *parent):
    QWidget(parent),
    ui(new Ui::FormConsumablesDev)
{
    ui->setupUi(this);

    this->flagbutt=flagbutt;

    qDebug()<<"\nconstructor count_cost_index :"<< count_cost_index;

    ui->tableConsumables->setModel(new QStandardItemModel (1,count_cost_index,parent));

    (flagbutt == 4)?ui->tableConsumables->setItemDelegate(new itemDelegateCostIndex(parent)):ui->tableConsumables->setItemDelegate(new ItemDelegateFloat(parent));

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->move(10,10);

}

FormConsumablesDev::~FormConsumablesDev()
{
    delete ui;
}

void FormConsumablesDev::on_ButtonExit_clicked()
{
    close();
}

void FormConsumablesDev::on_ButtonSave_clicked()
{
    if (flagbutt!=0){

        filling_mantain();

        return;
    }

    for (int i=0;i<count_years;i++){

        if (!isnull(i)){

            ir[element].develop->get_consumables()[i] = ui->tableConsumables->model()->data( ui->tableConsumables->model()->index(0,i,QModelIndex())  ).toInt();

        }else{

            ErrorForm::showerror ();

            return;

        }

    }
    close();
}


bool FormConsumablesDev::isnull (int j){

    return ui->tableConsumables->model()->data(ui->tableConsumables->model()->index(0,j,QModelIndex())).isNull();
}

void FormConsumablesDev::filling_mantain(){

    switch (flagbutt) {
    //    case 1:

    //        for (int i=0;i<delta_years;i++){

    //            if (!isnull(i)){

    //                ir[element].maintain->consumables[i] = ui->tableConsumables->model()->data(ui->tableConsumables->model()->index(0,i,QModelIndex())).toInt();

    //                qDebug()<<"\n tax "<<ir[element].maintain->consumables[i];


    //            }else {

    //                ErrorForm::showerror();

    //                return;
    //            }
    //        }

    //        break;
    case 2:

        for (int i=0;i<count_employees;i++){

            if (!isnull(i)){

                ir[element].maintain->tax[i] = ui->tableConsumables->model()->data(ui->tableConsumables->model()->index(0,i,QModelIndex())).toInt();

                qDebug()<<"\n filling_mantain tax "<<ir[element].maintain->tax[i];

            }else {

                ErrorForm::showerror();

                return;
            }

        }

        break;
    case 3:

        for (int i=0;i<count_employees;i++){

            if (!isnull(i)){

                ir[element].maintain->salory[i] = ui->tableConsumables->model()->data(ui->tableConsumables->model()->index(0,i,QModelIndex())).toInt();

                qDebug()<<"\n filling_mantain salory "<<ir[element].maintain->salory[i];

            }else {

                ErrorForm::showerror();

                return;
            }

        }
        break;
    case 4:

        qDebug()<<"\n filling_mantain count_cost_index: "<<count_cost_index;

        for (int i=0;i<count_cost_index;i++){

            if (!isnull(i)){

                c_index[i].index = ui->tableConsumables->model()->data(ui->tableConsumables->model()->index(0,i,QModelIndex())).toString().replace(",",".").toDouble();

                //                c_index[i].index = 1.1;
                //                qDebug()<<"\n filling_mantain c_index[i] "<<c_index->index;

                //                cout<<"\n filling_mantain from form "<<ui->tableConsumables->model()->data(ui->tableConsumables->model()->index(0,i,QModelIndex())).toString().replace(",",".").toDouble();

                qDebug()<<"\n filling_mantain c_index["<<i<<"]: "<<c_index[i].index;

            }else {

                ErrorForm::showerror();

                return;
            }

        }
        break;

    default:
        ErrorForm::showerror();

        return;

        break;
    }

    close();
}
