#include "tabwidgetir.h"
#include "ui_tabwidgetir.h"

TabWidgetIr::TabWidgetIr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabWidgetIr)
{
    ui->setupUi(this);

}

TabWidgetIr::~TabWidgetIr()
{
    delete ui;
}

QTabWidget* TabWidgetIr::get_TabWidget (){

    return (ui->tabWidget);

}
