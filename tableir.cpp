#include "tableir.h"

//extern TabWidgetIr *twi;

TableIr::TableIr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableIr)
{
    ui->setupUi(this);

    //ui->tableViewIR->setEditTriggers(QAbstractItemView::SelectedClicked);

/*    ui->tablewidIR->setColumnCount(COLUMNCOUNT);
    ui->tablewidIR->setRowCount(count_ir);
     Включаем сетку
    ui->tablewidIR->setShowGrid(true);
     Разрешаем выделение только одного элемента
    ui->tablewidIR->setSelectionMode(QAbstractItemView::SingleSelection);
     Разрешаем выделение построчно
    ui->tablewidIR->setSelectionBehavior(QAbstractItemView::SelectRows);
     Устанавливаем заголовки колонок
        ui->tablewidIR->setHorizontalHeaderLabels(headers);
     Растягиваем последнюю колонку на всё доступное пространство
    ui->tablewidIR->horizontalHeader()->setStretchLastSection(true);
     Скрываем колонку под номером 0
        ui->tablewidIR->hideColumn(0);

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
    ui->tablewidIR->setHorizontalHeaderItem(7, new QTableWidgetItem(tr("Приносящий")));*/


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QStringList list;

    list<< "Наименование ИР" << "Первый календарный г. эксплуатации" << "Текущий г. эксплуатации"<<"Планируемый срок эксплуатации"
        <<"Приобретённый"<<"Разработанный"<<"Обслуживаемый"<<"Приносящий";

    QStandardItemModel* model = new QStandardItemModel (count_ir,COLUMNCOUNT);

    model->setHorizontalHeaderLabels(list);

    ui->tableViewIR->setModel(model);//new QStandardItemModel (count_ir,COLUMNCOUNT));
    ui->tableViewIR->setItemDelegate(new ItemDelegate);

    ui->tableViewIR->setColumnWidth(0,175);
    ui->tableViewIR->setColumnWidth(1,295);
    ui->tableViewIR->setColumnWidth(2,215);
    ui->tableViewIR->setColumnWidth(3,265);
    ui->tableViewIR->setColumnWidth(4,135);
    ui->tableViewIR->setColumnWidth(5,145);
    ui->tableViewIR->setColumnWidth(6,145);
    ui->tableViewIR->setColumnWidth(7,145);
    ui->tableViewIR->horizontalHeader()->setStretchLastSection(true);

}

TableIr::~TableIr()
{
    delete ui;
}

void TableIr::on_save_butt_clicked()
{
/*        for (int i=0;i<count_ir;i++){

            ir[i].set_name(ui->tablewidIR->item(i,0)->text());
            ir[i].set_first_year(set_dateval(ui->tablewidIR->item(i,1)->text()));
            ir[i].set_this_year(set_dateval(ui->tablewidIR->item(i,2)->text()));
            ir[i].set_planned_year(set_dateval(ui->tablewidIR->item(i,3)->text()));

            set_boolval(i,4,ui->tablewidIR->item(i,4)->text());
            set_boolval(i,5,ui->tablewidIR->item(i,5)->text());
            set_boolval(i,6,ui->tablewidIR->item(i,6)->text());
            set_boolval(i,7,ui->tablewidIR->item(i,7)->text());
        }*/

    for (int i=0;i<count_ir;i++){

        ir[i].set_name(ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,0,QModelIndex())).toString());

        ir[i].set_first_year(set_dateval(ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,1,QModelIndex())).toInt()));

        ir[i].set_this_year(set_dateval(ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,2,QModelIndex())).toInt()));

        ir[i].set_planned_year(set_dateval(ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,3,QModelIndex())).toInt()));

        set_boolval(i,4,ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,4,QModelIndex())).toInt());

        set_boolval(i,5,ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,5,QModelIndex())).toInt());

        set_boolval(i,6,ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,6,QModelIndex())).toInt());

        set_boolval(i,7,ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,7,QModelIndex())).toInt());

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

QDate TableIr::set_dateval (int str){

    QDate date(0000,00,00);

    date.addYears(str);

    return date;

}

void TableIr::set_boolval (int i,int j ,int str){

    switch (j) {
    case 4:

        if (str== 1){

            ir[i].set_val_acquire(true);
        }else{

            ir[i].set_val_acquire(false);
        }

        break;
    case 6:
        if (str==1){

            ir[i].set_val_maintain(true);

        }else{

            ir[i].set_val_maintain(false);
        }
        break;
    case 5:
        if (str==1){

            ir[i].set_val_develop(true);

        }else{

            ir[i].set_val_develop(false);
        }
        break;
    case 7:
        if (str==1){

            ir[i].set_val_profit(true);

        }else{

            ir[i].set_val_profit(false);

        }
        break;
    default:
        ErrorForm *e = new ErrorForm;

        e->setAttribute(Qt::WA_DeleteOnClose);

        e->show();
        break;
    }
}
