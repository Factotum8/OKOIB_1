#include "tableir.h"

//extern TabWidgetIr *twi;


TableIr::TableIr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableIr)
{
    ui->setupUi(this);

    ui->tablewidIR->setColumnCount(COLUMNCOUNT);
    ui->tablewidIR->setRowCount(count_ir);
    // Включаем сетку
   //ui->tablewidIR->setShowGrid(true);
    // Разрешаем выделение только одного элемента
    //ui->tablewidIR->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    //ui->tablewidIR->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем заголовки колонок
//    ui->tablewidIR->setHorizontalHeaderLabels(headers);
    // Растягиваем последнюю колонку на всё доступное пространство
    ui->tablewidIR->horizontalHeader()->setStretchLastSection(true);
    // Скрываем колонку под номером 0
//    ui->tablewidIR->hideColumn(0);

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

//    QTableWidgetItem *pitem4 = new QTableWidgetItem();
//    QTableWidgetItem *pitem5 = new QTableWidgetItem();
//    QTableWidgetItem *pitem6 = new QTableWidgetItem();
//    QTableWidgetItem *pitem7 = new QTableWidgetItem();

//    pitem4->data(Qt::Checked);
//    pitem5->data(Qt::ClosedHandCursor);
//    pitem6->data(Qt::CheckStateRole);
//    pitem7->data(Qt::CheckStateRole);

//    for (int i=0;i<count_ir;i++){

//        QTableWidgetItem *pitem4 = new QTableWidgetItem();
//        QTableWidgetItem *pitem5 = new QTableWidgetItem();
//        QTableWidgetItem *pitem6 = new QTableWidgetItem();
//        QTableWidgetItem *pitem7 = new QTableWidgetItem();

//        pitem4->data(Qt::Checked);
//        pitem5->data(Qt::ClosedHandCursor);
//        pitem6->data(Qt::CheckStateRole);
//        pitem7->data(Qt::CheckStateRole);

//        ui->tablewidIR->setItem(i,4,pitem4);
//        ui->tablewidIR->setItem(i,5,pitem5);
//        ui->tablewidIR->setItem(i,6,pitem6);
//        ui->tablewidIR->setItem(i,7,pitem7);

//    }

//    //QTableWidgetItem * QTableWidget::item ( int row, int column ) const

    //ui->tablewidIR->item(1,1)->text();

}

TableIr::~TableIr()
{
    delete ui;
}

void TableIr::on_save_butt_clicked()
{

    for (int i=0;i<count_ir;i++){

        ir[i].set_name(ui->tablewidIR->item(i,0)->text());
        ir[i].set_first_year(set_dateval(ui->tablewidIR->item(i,1)->text()));
        ir[i].set_this_year(set_dateval(ui->tablewidIR->item(i,2)->text()));
        ir[i].set_planned_year(set_dateval(ui->tablewidIR->item(i,3)->text()));

        set_boolval(i,4,ui->tablewidIR->item(i,4)->text());
        set_boolval(i,5,ui->tablewidIR->item(i,5)->text());
        set_boolval(i,6,ui->tablewidIR->item(i,6)->text());
        set_boolval(i,7,ui->tablewidIR->item(i,7)->text());


        for (int i=0;i<count_ir;i++){
            QStringList list;

            foreach (QString str, list) {

                twi->get_TabWidget()->addTab(new QLabel(str,twi->get_TabWidget()),str);
            }

            twi->show();
        }

    }
}


void TableIr::on_exit_butt_clicked()
{

    return;
}

QDate TableIr::set_dateval (QString str){

    QDate date;
    date.addYears(str.toInt());
    date.addDays(1);
    date.addMonths(1);
    return date;

}

void TableIr::set_boolval (int i,int j ,QString str){

    switch (j) {
    case 4:

        if (str=="1"){

            ir[i].set_val_acquire(true);
        }else{

            ir[i].set_val_acquire(false);
        }

        break;
    case 5:
        if (str=="1"){

            ir[i].set_val_maintain(true);
        }else{

            ir[i].set_val_maintain(false);
        }
        break;
    case 6:
        if (str=="1"){

            ir[i].set_val_develop(true);
        }else{

            ir[i].set_val_develop(false);
        }
        break;
    case 7:
        if (str=="1"){

            ir[i].set_val_profit(true);
        }else{
            if (str=="0"){
                ir[i].set_val_profit(false);
            } else {
                ErrorForm *e = new ErrorForm;

                e->setAttribute(Qt::WA_DeleteOnClose);

                e->show();
            }
        }
        break;
    default:
        ErrorForm *e = new ErrorForm;

        e->setAttribute(Qt::WA_DeleteOnClose);

        e->show();
        break;
    }
}
