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

    ui->tableConsumables->setModel(new QStandardItemModel (1,count_years));

    ui->tableConsumables->setItemDelegate(new ItemDelegateFloat);

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

    if (ir[element].maintain->salory== NULL){

        ir[element].maintain->salory = new int[employees];

    }

    if (ir[element].maintain->consumables== NULL){

        ir[element].maintain->consumables = new int[delta_years];

    }

    if (ir[element].maintain->tax== NULL){

        ir[element].maintain->tax = new int[employees];

    }

    ui->tableConsumables->setModel(new QStandardItemModel (1,employees));

    ui->tableConsumables->setItemDelegate(new ItemDelegateFloat);

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->move(10,10);

}

FormConsumablesDev::FormConsumablesDev (int flagbutt,QWidget *parent)
{
    this->flagbutt=flagbutt;

    qDebug()<<"\ncount_cost_index :"<< count_cost_index;

    ui->tableConsumables->setModel(new QStandardItemModel (1,count_cost_index));

    ui->tableConsumables->setItemDelegate(new ItemDelegateFloat);

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
    case 1:

        for (int i=0;i<delta_years;i++){

            if (!isnull(i)){

                ir[element].maintain->consumables[i] = ui->tableConsumables->model()->data(ui->tableConsumables->model()->index(0,i,QModelIndex())).toInt();

                qDebug()<<"\n tax "<<ir[element].maintain->consumables[i];


            }else {

                ErrorForm::showerror();

                return;
            }
        }

        break;
    case 2:

        for (int i=0;i<count_employees;i++){

            if (!isnull(i)){

                ir[element].maintain->tax[i] = ui->tableConsumables->model()->data(ui->tableConsumables->model()->index(0,i,QModelIndex())).toInt();

                qDebug()<<"\n tax "<<ir[element].maintain->tax[i];

            }else {

                ErrorForm::showerror();

                return;
            }

        }

        break;
//    case 3:

//        for (int i=0;i<count_employees;i++){

//            if (!isnull(i)){

//                ir[element].maintain->salory[i] = ui->tableConsumables->model()->data(ui->tableConsumables->model()->index(0,i,QModelIndex())).toInt();

//                qDebug()<<"\n salory "<<ir[element].maintain->salory[i];

//            }else {

//                ErrorForm::showerror();

//                return;
//            }

//        }
//        break;
//    case 4:
//        for (int i=0;i<count_cost_index;i++){

//            if (!isnull(i)){

//                c_index->index = ui->tableConsumables->model()->data(ui->tableConsumables->model()->index(0,i,QModelIndex())).toInt();

//            }else {

//                ErrorForm::showerror();

//                return;
//            }

//        }
//        break;
    default:
        ErrorForm::showerror();

        return;

        break;
    }

    close();
}
