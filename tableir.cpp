#include "tableir.h"
#include "ui_tableir.h"

TableIr::TableIr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableIr)
{
    ui->setupUi(this);
}

TableIr::~TableIr()
{
    delete ui;
}
