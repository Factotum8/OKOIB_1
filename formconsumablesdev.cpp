#include "formconsumablesdev.h"
#include "ui_formconsumablesdev.h"

FormConsumablesDev::FormConsumablesDev(int element,int count_years,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormConsumablesDev)
{
    ui->setupUi(this);

    this->element=element;
    this->count_years=count_years;

    ir[element].develop->set_consumables(count_years);

    ui->tableConsumables->setModel(new QStandardItemModel (1,count_years));

    ui->tableConsumables->setItemDelegate(new ItemDelegateFloat);

    this->setAttribute(Qt::WA_DeleteOnClose);

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
    for (int i=0;i<count_years;i++){

        if (!isnull(i)){

            ir[element].develop->get_consumables()[i] = ui->tableConsumables->model()->data( ui->tableConsumables->model()->index(0,i,QModelIndex())  ).toInt();

//            qDebug()<<"\n consumables "<<ir[element].develop->get_consumables()[i];

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
