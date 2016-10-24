#include "formemployees.h"


FormEmployees::FormEmployees(int count_employees,int count_years,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormEmployees)
{
    ui->setupUi(this);

    QStandardItemModel* model = new QStandardItemModel (count_employees,count_years);

    QItemDelegate* delegate = new QItemDelegate;

    QItemEditorCreatorBase* doubleEditor = new QStandardItemEditorCreator<QDoubleSpinBox>();// = new QDoubleSpinBox;

    QItemEditorFactory * factory = new QItemEditorFactory;

    factory->registerEditor(QVariant::Double, doubleEditor);

    delegate->setItemEditorFactory(factory);

    ui->tableEmployees->setModel(model);

    ui->tableEmployees->setItemDelegate(delegate);


}

FormEmployees::~FormEmployees()
{
    delete ui;
}

void FormEmployees::on_ButtonExit_clicked()
{
    close();
}
