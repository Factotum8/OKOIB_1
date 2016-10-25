#include "tableir.h"

//extern TabWidgetIr *twi;

TableIr::TableIr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableIr)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->move(10,10);

    QHBoxLayout* pqhbxLayout = new QHBoxLayout;

    QVBoxLayout* pqvbxLayout = new QVBoxLayout;

    pqhbxLayout->setMargin(10);

    pqhbxLayout->setSpacing(10);

    pqhbxLayout->insertStretch(10);

    pqvbxLayout->setMargin(10);

    pqvbxLayout->setSpacing(10);

    pqvbxLayout->insertStretch(10);

    pqhbxLayout->addWidget(ui->exit_butt);

    pqhbxLayout->addWidget(ui->save_butt);

    pqvbxLayout->addWidget(ui->tableViewIR);

    pqhbxLayout->addLayout(pqvbxLayout);

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
    for (int i=0;i<count_ir;i++){

        if (dataisnull(i,0)) {

            return;
        }

        if (dataisnull(i,1)) {

            return;
        }

        if (dataisnull(i,2)) {

            return;
        }

        if (dataisnull(i,3)) {

            return;
        }

        if (dataisnull(i,4)) {

            return;
        }

        if (dataisnull(i,5)) {

            return;
        }

        if (dataisnull(i,6)) {

            return;
        }

        if (dataisnull(i,7)) {

            return;
        }

    }

    TabWidgetIr *twi= new TabWidgetIr;

    twi->setAttribute(Qt::WA_DeleteOnClose);
    //twi->setWindowFlags(Qt::WindowStaysOnTopHint);

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
//        ErrorForm *e = new ErrorForm;

//        e->setAttribute(Qt::WA_DeleteOnClose);
//        e->setWindowFlags(Qt::WindowStaysOnTopHint);

//        e->show();
        ErrorForm::showerror ();
        break;
    }
}

bool TableIr::isnull (int i,int j){

    return ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,j,QModelIndex())).isNull();
}


bool TableIr::dataisnull (int i, int j){

    if (!isnull(i,j)) {

        switch (j) {

        case 0:

            ir[i].set_name(ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,0,QModelIndex())).toString());
            break;

        case 1:

            ir[i].set_first_year(set_dateval(ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,1,QModelIndex())).toInt()));
            break;

        case 2:
            ir[i].set_this_year(set_dateval(ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,2,QModelIndex())).toInt()));
            break;

        case 3:

            ir[i].set_planned_year(set_dateval(ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,3,QModelIndex())).toInt()));
            break;
        case 4:

            set_boolval(i,4,ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,4,QModelIndex())).toInt());
            break;

        case 5:

            set_boolval(i,5,ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,5,QModelIndex())).toInt());
            break;

        case 6:

            set_boolval(i,6,ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,6,QModelIndex())).toInt());
            break;

        case 7:

            set_boolval(i,7,ui->tableViewIR->model()->data(ui->tableViewIR->model()->index(i,7,QModelIndex())).toInt());
            break;

        default:

//            ErrorForm* e = new ErrorForm();

//            e->setAttribute(Qt::WA_DeleteOnClose);

//            e->setWindowFlags(Qt::WindowStaysOnTopHint);

//            e->show();
            ErrorForm::showerror ();
            break;
        }

        return 0;

    }else {

//        ErrorForm* e = new ErrorForm();

//        e->setAttribute(Qt::WA_DeleteOnClose);

//        e->setWindowFlags(Qt::WindowStaysOnTopHint);

//        e->show();
        ErrorForm::showerror ();

        return 1;
    }
}
