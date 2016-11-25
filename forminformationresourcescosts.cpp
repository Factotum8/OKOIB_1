#include "forminformationresourcescosts.h"
#include "ui_forminformationresourcescosts.h"




FormInformationResourcesCosts::FormInformationResourcesCosts(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormInformationResourcesCosts)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->move(10,10);

    this->setFixedHeight(525);

    this->setFixedWidth(390);

    ui->tableResultCost->setRowCount(count_ir);

    ui->tableResultCost->setColumnCount(2);

    for (int i=0;i<count_ir;i++){

        int result_cost=0;

        ui->tableResultCost->setItem(0,i,new QTableWidgetItem (ir[i].get_name()));

        result_cost=ir[i].get_val_acquire()?ir[i].cost_acquire():0 +ir[i].get_val_develop()?ir[i].cost_development():0
                                                                                            +ir[i].get_val_maintain()?ir[i].cost_maintain():0 +ir[i].get_val_profit()?ir[i].profit.profit:0;

        QString str= QString::number(result_cost);

        ui->tableResultCost->setItem(1,i,new QTableWidgetItem(str));
    }
}

FormInformationResourcesCosts::~FormInformationResourcesCosts()
{
    delete ui;

    delete ir;

    delete c_index;
}

void FormInformationResourcesCosts::on_butt_writef_file_clicked()
{

}
