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


//    QHeaderView* model = new QHeaderView;
//    model->setStringList(QStringList() << "Наименование ИР" << "Первый календарный г. эксплуатации" << "Текущий г. эксплуатации"<<"Планируемый срок эксплуатации"
//                                                                                                <<"Приобретённый"<<"Разработанный"<<"Обслуживаемый"<<"Приносящий");




    QStringList model;
    model<< "Наименование ИР" << "Первый календарный г. эксплуатации" << "Текущий г. эксплуатации"<<"Планируемый срок эксплуатации"
                                                                                                            <<"Приобретённый"<<"Разработанный"<<"Обслуживаемый"<<"Приносящий";

     QStringListModel c;

     c.setStringList(QStringList() << "Наименование ИР" << "Первый календарный г. эксплуатации" << "Текущий г. эксплуатации"<<"Планируемый срок эксплуатации"
                                                                                                                    <<"Приобретённый"<<"Разработанный"<<"Обслуживаемый"<<"Приносящий");
    QItemSelectionModel select(&c);
    //ui->tableViewIR->setModel(new QStandardItemModel (count_ir,COLUMNCOUNT));//(COLUMNCOUNT,count_ir));
    ui->tableViewIR->setItemDelegate(new ItemDelegate);
    ui->tableViewIR->setSelectionMode(&select);
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
    }


    TabWidgetIr *twi= new TabWidgetIr;

    twi->setAttribute(Qt::WA_DeleteOnClose);

    twi->show();
}



void TableIr::on_exit_butt_clicked()
{
    this->close();
    return;
}

QDate TableIr::set_dateval (QString str){

    QDate date(0000,00,00);

    date.addYears(str.toInt());

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
    case 6:
        if (str=="1"){

            ir[i].set_val_maintain(true);

        }else{

            ir[i].set_val_maintain(false);
        }
        break;
    case 5:
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
