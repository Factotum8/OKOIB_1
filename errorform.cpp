#include "errorform.h"
#include "ui_errorform.h"

ErrorForm::ErrorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorForm)
{
    ui->setupUi(this);
}

ErrorForm::~ErrorForm()
{
    delete ui;
}

void ErrorForm::showerror (){

    ErrorForm *e = new ErrorForm;

    e->setAttribute(Qt::WA_DeleteOnClose);

    e->setWindowFlags(Qt::WindowStaysOnTopHint);

    e->move(500,300);

    e->show();

    return;
}
