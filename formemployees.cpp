#include "formemployees.h"
#include "ui_formemployees.h"

FormEmployees::FormEmployees(int count_employees,int count_years,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormEmployees)
{
    ui->setupUi(this);



}

FormEmployees::~FormEmployees()
{
    delete ui;
}
