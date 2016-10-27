#include "formconsumablesdev.h"
#include "ui_formconsumablesdev.h"

FormConsumablesDev::FormConsumablesDev(int element,int count_years,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormConsumablesDev)
{
    ui->setupUi(this);

    this->element=element;
    this->count_years=count_years;

//    ir[element].develop->get_consumables() = new int [count_years];

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

}
