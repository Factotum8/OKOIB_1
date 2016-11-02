#include "formcostindex.h"
#include "ui_formcostindex.h"

FormCostIndex::FormCostIndex(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormCostIndex)
{
    ui->setupUi(this);
}

FormCostIndex::~FormCostIndex()
{
    delete ui;
}
