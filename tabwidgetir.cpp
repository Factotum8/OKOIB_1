#include "tabwidgetir.h"


TabWidgetIr::TabWidgetIr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabWidgetIr)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->move(10,10);

    QStringList    list ;

    for (int i=0;i<count_ir;i++){

        list<<ir[i].get_name();

    }

    int i=0;

    foreach (QString str, list) {

        qDebug()<<"\nTabWidgetIr() FormIr(i) i:"<<i;

        ui->tabWidget->addTab(new FormIr(i),str );

        i++;

    }

    qDebug()<<"\ncount_ir"<<count_ir;

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

void TabWidgetIr::on_buttCostYears_clicked()
{
    int min_first_year = 3000, max_years_develop=0;

    //     qDebug()<<"\ncount_ir"<<count_ir;

    for (int i=0;i<count_ir;i++){
        //        qDebug()<<"\nir[i]:"<< ir[i].get_this_year().year();

        if (ir[i].get_val_develop()){


            if (max_years_develop < ir[i].develop->get_years_develop() ){

                max_years_develop = ir[i].develop->get_years_develop();
            }

            if (min_first_year > ir[i].develop->get_first_year().year()){

                min_first_year = ir[i].develop->get_first_year().year();
            }
        }
    }

    count_cost_index = max_years_develop;

    //    qDebug()<<"\nmin_cost_index :"<< min;

    //    qDebug()<<"\nmax_cost_index :"<< max;

    qDebug()<<"\ncount_cost_index :"<< count_cost_index;

    if (c_index != NULL) {

        delete [] c_index;
    }

    c_index = new cost_index [count_cost_index];

    for (int i=0;i<count_cost_index;i++){

        c_index[i].index = 0;
    }

    FormConsumablesDev* form_cost_index = new FormConsumablesDev (4);

    form_cost_index->show();

    for (int i=0;i<count_cost_index;i++){

        c_index[i].year.setDate(min_first_year+i,1,1);

    }
}

void TabWidgetIr::on_ButtonCalculateCostIr_clicked()
{
    if (c_index != NULL)
    {
        qDebug()<<"\ncount_cost_index: "<<count_cost_index;

        for (int i=0;i<count_cost_index;i++){

            qDebug()<<"\nc_index[i].index: "<<c_index[i].index;

            if (c_index[i].index==0){

                ErrorForm::showerror();

                return;
            }
        }
    }
    else
    {
        ErrorForm::showerror();

        return;
    }

    for (int i=0;i<count_ir;i++){

        if (ir[i].isEmptyIR()){

            ErrorForm::showerror();

            return;
        }
    }

    if (isEmptyCostIndex(c_index)) {

        ErrorForm::showerror();

        return;
    }

    //    QTableWidget* result=new QTableWidget();

    //    result->setRowCount(count_ir);

    //    result->setColumnCount(2);

    //    for (int i=0;i<count_ir;i++){

    //        int result_cost=0;

    //        result->setItem(0,i,new QTableWidgetItem (ir[i].get_name()));

    //        result_cost=ir[i].get_val_acquire()?ir[i].cost_acquire():0 +ir[i].get_val_develop()?ir[i].cost_development():0
    //                                                                                            +ir[i].get_val_maintain()?ir[i].cost_maintain():0 +ir[i].get_val_profit()?ir[i].profit.profit:0;

    //        QString str= QString::number(result_cost);

    //        result->setItem(1,i,new QTableWidgetItem(str));
    //    }

    //    result->show();
    FormInformationResourcesCosts* resourcescosts = new FormInformationResourcesCosts();

    resourcescosts->show();
}

void TabWidgetIr::on_ButtonCalculate_clicked()
{
    if (c_index==NULL) {

        ErrorForm::showerror();

        return;
    }

    for (int i=0;i<count_ir;i++){

        if (FormIr::isEmptyformIR(i)){

            ErrorForm::showerror();

            return;
        }
    }

    QTableWidget* result=new QTableWidget();

    result->setRowCount(count_ir);

    result->setColumnCount(2);

    for (int i=0;i<count_ir;i++){

        int result_cost=0;

        result->setItem(0,i,new QTableWidgetItem (ir[i].get_name()));

        result_cost=ir[i].get_val_acquire()?ir[i].cost_acquire():0 +ir[i].get_val_develop()?ir[i].cost_development():0
                            +ir[i].get_val_maintain()?ir[i].cost_maintain():0 +ir[i].get_val_profit()?ir[i].profit.profit:0;

        QString str= QString::number(result_cost);

        result->setItem(1,i,new QTableWidgetItem(str));
    }

    result->show();

}
