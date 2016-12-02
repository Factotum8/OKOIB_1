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

    this->setFixedWidth(1250);

    ui->tableResultCost->setRowCount(count_ir);

    ui->tableResultCost->setColumnCount(6);

    ui->tableResultCost->setColumnWidth(0,450);

    ui->tableResultCost->horizontalHeader()->setStretchLastSection(true); // авто подгон последней колонки

    ui->tableResultCost->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Наименование ИР")));

    ui->tableResultCost->setHorizontalHeaderItem(1,new QTableWidgetItem(tr("Приобретённые")));

    ui->tableResultCost->setHorizontalHeaderItem(2,new QTableWidgetItem(tr("Разрабатываемый")));

    ui->tableResultCost->setHorizontalHeaderItem(3,new QTableWidgetItem(tr("Обслуживаемый")));

    ui->tableResultCost->setHorizontalHeaderItem(4,new QTableWidgetItem(tr("Прибыльный")));

    ui->tableResultCost->setHorizontalHeaderItem(5, new QTableWidgetItem(tr("Cтоимость")));

    ui->tableResultCost->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    ui->tableResultCost->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

    ui->tableResultCost->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);

//    ui->tableResultCost->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);

    for (int i=0;i<count_ir;i++){

        int result_cost=0;

        ui->tableResultCost->setItem(i,0,new QTableWidgetItem (ir[i].get_name()));

        qDebug()<<"\nname: "<<ir[i].get_name();

        ui->tableResultCost->setItem(  i,1,new QTableWidgetItem(QString::number(ir[i].get_val_acquire()?ir[i].cost_acquire():0))  );

        ui->tableResultCost->setItem( i,2,new QTableWidgetItem(QString::number(ir[i].get_val_develop()?ir[i].cost_development():0)));

        ui->tableResultCost->setItem( i,3,new QTableWidgetItem(QString::number(ir[i].get_val_maintain()?ir[i].cost_maintain():0)));

        ui->tableResultCost->setItem( i,4,new QTableWidgetItem(QString::number(ir[i].get_val_profit()?ir[i].profit.profit:0)));

//        ui->tableResultCost

        result_cost=( (ir[i].get_val_acquire()?ir[i].cost_acquire():0) +(ir[i].get_val_develop()?ir[i].cost_development():0) +(ir[i].get_val_maintain()?ir[i].cost_maintain():0) +(ir[i].get_val_profit()?ir[i].profit.profit:0) );

        QString str= QString::number(result_cost);

        ui->tableResultCost->setItem(i,5,new QTableWidgetItem(str));
    }
}

FormInformationResourcesCosts::~FormInformationResourcesCosts()
{
    delete ui;

    delete [] ir;

    delete [] c_index;
}

void FormInformationResourcesCosts::on_butt_writef_file_clicked()
{
    QFile file ("resalt.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){

        ErrorForm::showerror();

        return;
    }

    QTextStream writeStream(&file);

    for (int i=0;i<count_ir;i++){

        qDebug()<<"\n item №"<<i;
        qDebug()<<"\n name:"<<ui->tableResultCost->item(i,0)->text();
        qDebug()<<"\n values:"<<ui->tableResultCost->item(i,1)->text();

        writeStream<<ui->tableResultCost->item(i,0)->text()<<"  ";
        writeStream<<ui->tableResultCost->item(i,5)->text()<<"\n";
    }

    file.close();
    this->close();
}

void FormInformationResourcesCosts::on_exit_clicked()
{
    this->close();
}
