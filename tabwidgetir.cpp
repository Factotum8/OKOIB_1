#include "tabwidgetir.h"


TabWidgetIr::TabWidgetIr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabWidgetIr)
{
    ui->setupUi(this);
    QStringList    list ;

    for (int i=0;i<count_ir;i++){

        list<<ir[i].get_name();

    }

    int i=0;

    foreach (QString str, list) {

        ui->tabWidget->addTab(new FormIr(i),str );

        i++;

    }

//    for (int i=0;i<count_ir;i++){

//        if (!ir[i].get_val_develop()){

//            ui->tabWidget;
//        }
//    }

}

TabWidgetIr::~TabWidgetIr()
{
    delete ui;
}

QTabWidget* TabWidgetIr::get_TabWidget (){

    return (ui->tabWidget);

}

void TabWidgetIr::on_ButtonMainExit_clicked()
{
    close();
}
