#include "tableir.h"


TableIr::TableIr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableIr)
{
    ui->setupUi(this);

    ui->tablewidIR->setColumnCount(COLUMNCOUNT);
    ui->tablewidIR->setRowCount(count_ir);
    ui->tablewidIR->setColumnWidth(0,175);
    ui->tablewidIR->setColumnWidth(1,295);
    ui->tablewidIR->setColumnWidth(2,215);
    ui->tablewidIR->setColumnWidth(3,265);
    ui->tablewidIR->setColumnWidth(4,135);
    ui->tablewidIR->setColumnWidth(5,145);
    ui->tablewidIR->setColumnWidth(6,145);
    ui->tablewidIR->setColumnWidth(7,145);


    ui->tablewidIR->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Наименование ИР")));
    ui->tablewidIR->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Первый календарный г. эксплуатации")));
    ui->tablewidIR->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Текущий г. эксплуатации")));
    ui->tablewidIR->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Планируемый срок эксплуатации")));
    ui->tablewidIR->setHorizontalHeaderItem(4, new QTableWidgetItem(tr("Приобретённый")));
    ui->tablewidIR->setHorizontalHeaderItem(5, new QTableWidgetItem(tr("Разработанный")));
    ui->tablewidIR->setHorizontalHeaderItem(6, new QTableWidgetItem(tr("Обслуживаемый")));
    ui->tablewidIR->setHorizontalHeaderItem(7, new QTableWidgetItem(tr("Приносящий")));

    //QTableWidgetItem * QTableWidget::item ( int row, int column ) const

    //ui->tablewidIR->item(1,1)->text();

}

TableIr::~TableIr()
{
    delete ui;
}

void TableIr::on_save_butt_clicked()
{
    ui->tablewidIR->item(1,1)->text();
    ui->tablewidIR->setItem(2,2, ui->tablewidIR->item(1,1));

}


void TableIr::on_exit_butt_clicked()
{

    return;
}
