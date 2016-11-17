#include "formemployees.h"


FormEmployees::FormEmployees(int element, bool flag,int count_employees,int count_years,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormEmployees)
{
    ui->setupUi(this);

    this->flag=flag;
    this->element=element;
    this->count_employees=count_employees;
    this->count_years=count_years;

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->move(10,10);

    //    QStandardItemModel* model = new QStandardItemModel (count_employees,count_years);

    ui->tableEmployees->setModel(new QStandardItemModel (count_employees,count_years));

    ui->tableEmployees->setItemDelegate(new ItemDelegateFloat);

    QHBoxLayout* pqhbxLayout = new QHBoxLayout;

    QVBoxLayout* pqvbxLayout = new QVBoxLayout;

    pqhbxLayout->setMargin(10);

    pqhbxLayout->setSpacing(10);

    pqhbxLayout->insertStretch(10);

    pqvbxLayout->setMargin(10);

    pqvbxLayout->setSpacing(10);

    pqvbxLayout->insertStretch(10);

    pqhbxLayout->addWidget(ui->ButtonExit);

    pqhbxLayout->addWidget(ui->ButtonSave);

    pqvbxLayout->addWidget(ui->tableEmployees);

    pqvbxLayout->addLayout(pqhbxLayout);


}

FormEmployees::~FormEmployees()
{
    delete ui;
}

void FormEmployees::on_ButtonExit_clicked()
{
    close();
}

void FormEmployees::on_ButtonSave_clicked()
{   qDebug()<<"\n on_ButtonSave_clicked";

    for(int i=0;i<count_employees;i++){
        for(int j=0;j<count_years;j++){

            dataisnull(i,j);
        }
    }

    close();
}

bool FormEmployees::isnull (int i,int j){

    return ui->tableEmployees->model()->data(ui->tableEmployees->model()->index(i,j,QModelIndex())).isNull();
}


bool FormEmployees::dataisnull (int i, int j){

    if (!isnull(i,j)) {

        switch (flag) {
        case true:
            (ir[element].develop->get_number_employees())[i][j].salory = ui->tableEmployees->model()->data( ui->tableEmployees->model()->index(i,j,QModelIndex())  ).toInt();

//            qDebug()<<"\n salory "<<(ir[element].develop->get_number_employees())[i][j].salory;

            break;

        case false:
            (ir[element].develop->get_number_employees())[i][j].tax = ui->tableEmployees->model()->data(  ui->tableEmployees->model()->index(i,j,QModelIndex())  ).toInt();

//            qDebug()<<"\n tax "<<ir[element].develop->get_number_employees()[i][j].tax;

            break;

        default:
            exit(1);
            break;
        }
    }else {

        ErrorForm::showerror ();

        return 1;
    }
    return false;
}
