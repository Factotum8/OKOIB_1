#include "formemployees.h"


FormEmployees::FormEmployees(int count_employees,int count_years,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormEmployees)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->move(10,10);

    QStandardItemModel* model = new QStandardItemModel (count_employees,count_years);

    QItemDelegate* delegate = new QItemDelegate;

    QItemEditorCreatorBase* doubleEditor = new QStandardItemEditorCreator<QDoubleSpinBox>();// = new QDoubleSpinBox;

    QItemEditorFactory * factory = new QItemEditorFactory;

    factory->registerEditor(QVariant::Double, doubleEditor);

    delegate->setItemEditorFactory(factory);

    ui->tableEmployees->setModel(model);

    ui->tableEmployees->setItemDelegate(delegate);

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
