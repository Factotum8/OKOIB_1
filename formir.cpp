#include "formir.h"

int k=0;

FormIr::FormIr(int i,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormIr)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    if (!ir[i].get_val_develop()){

        ui->frameDevelop->hide();

    } else {

        ui->textEditFirstYearDev->setPlaceholderText("1920-2020");
        ui->textEditFirstYearDev->setValidator(new QIntValidator (1920,2020));
        ui->textEditYearsDev->setInputMask("D0");
        ui->textEditEmployeesDev->setInputMask("D0");

    }

    if (!ir[i].get_val_acquire()){

        ui->frameAcquire->hide();

    } else {

        ui->textEditAcquire->setInputMask("D000");
    }

    if (!ir[i].get_val_maintain()){

        ui->frameMantain->hide();

    } else {

        ui->textEditEmployeesMaint->setInputMask("D0000");
    }

    if (!ir[i].get_val_profit()){

        ui->frameProfit->hide();
    } else {

        ui->textEditProfit->setInputMask("D0000");
    }

    k=i;
}

FormIr::~FormIr()
{
    delete ui;
}

void FormIr::on_Exit_clicked()
{
    close();
}


void FormIr::on_TableDev_clicked()
{
    buttclickeddev(true);
}

void FormIr::on_TableMaintain_clicked()
{


    buttclickedmain(3,ui->textEditEmployeesMaint->text().toInt());

}

void FormIr::on_ButtonInputTaxMaint_clicked()
{

    buttclickedmain(2,ui->textEditEmployeesMaint->text().toInt());

}

void FormIr::on_ButtonConsumablesMain_clicked()
{

    ir[k].set_mantain_consumables(ui->textEditEmployeesMaint->text().toInt());

    FormConsumablesDev* buttonconsumablesmain = new FormConsumablesDev(1,k,ui->textEditEmployeesMaint->text().toInt());

    buttonconsumablesmain->setAttribute(Qt::WA_DeleteOnClose);

    buttonconsumablesmain->show();


}

void FormIr::on_ButtTaxDev_clicked()
{
    buttclickeddev(false);
}

void FormIr::buttclickeddev (bool flag){

    if (ir[k].get_val_develop()&!ui->textEditEmployeesDev->text().isEmpty()&!ui->textEditFirstYearDev->text().isEmpty()
            &!ui->textEditYearsDev->text().isEmpty()){

        if (ir[k].develop != NULL){

            delete (ir[k].develop);
        }

        ir[k].develop = new Develop(ui->textEditFirstYearDev->text().toInt(),ui->textEditEmployeesDev->text().toInt(), ui->textEditYearsDev->text().toInt());

        ir[k].develop->set_count_employees(ui->textEditEmployeesDev->text().toInt());

        ir[k].develop->set_years_develop(ui->textEditYearsDev->text().toInt());

        FormEmployees* formfmployees = new FormEmployees(k,flag,ui->textEditEmployeesDev->text().toInt(),ui->textEditYearsDev->text().toInt());

        formfmployees->setAttribute(Qt::WA_DeleteOnClose);

        formfmployees->show();

    }else{

        ErrorForm::showerror ();
    }
}


bool FormIr::buttclickedmain (int flagbutt, int employees){

    if (ir[k].get_val_maintain()&!ui->textEditEmployeesMaint->text().isEmpty()){

        if (ir[k].maintain != NULL){

            delete ir[k].maintain;
        }

        ir[k].maintain = new Maintain;

        init_mantain(k);

        ir[k].set_mantain_salory(employees);

        ir[k].set_mantain_tax(employees);

        ir[k].maintain->consumables = ui->lineEditConsumablesMain->text().toInt();

        ir[k].maintain->count_employees = ui->textEditEmployeesMaint->text().toInt();

        FormConsumablesDev* formconsumablesmain = new FormConsumablesDev(flagbutt,k,employees);

        formconsumablesmain->setAttribute(Qt::WA_DeleteOnClose);

        formconsumablesmain->show();




    }else{

        ErrorForm::showerror ();

        return true;
    }

    return false;
}

void FormIr::on_ButtonConsumablesDev_clicked()
{
    if (ir[k].get_val_develop()&!ui->textEditEmployeesDev->text().isEmpty()&!ui->textEditFirstYearDev->text().isEmpty()
            &!ui->textEditYearsDev->text().isEmpty()){

        if (ir[k].develop == NULL){

            ir[k].develop =new Develop(ui->textEditFirstYearDev->text().toInt(),ui->textEditEmployeesDev->text().toInt(), ui->textEditYearsDev->text().toInt());

        } else {

            delete (ir[k].develop);

            ir[k].develop =new Develop(ui->textEditFirstYearDev->text().toInt(),ui->textEditEmployeesDev->text().toInt(), ui->textEditYearsDev->text().toInt());
        }

        FormConsumablesDev* formconsumablesdev = new FormConsumablesDev(k,ui->textEditYearsDev->text().toInt());

        //        formfmployees->setAttribute(Qt::WA_DeleteOnClose);

        formconsumablesdev->show();

    }else{

        ErrorForm::showerror ();
    }
}



void FormIr::on_Save_clicked()
{
    //    if (!ui->textEditAcquire->text().isEmpty()
    //            &!ui->textEditEmployeesDev->text().isEmpty()
    //            &!ui->textEditYearsDev->text().isEmpty()
    //            &!ui->textEditFirstYearDev->text().isEmpty()
    //            &!ui->textEditEmployeesMaint->text().isEmpty()
    //            &!ui->lineEditConsumablesMain->text().isEmpty()
    //            &!ui->textEditProfit->text().isEmpty()
    //            )

    //    {

    if (ir[k].get_val_acquire()&&ui->textEditAcquire->text().isEmpty() ){

        ErrorForm::showerror();

        return;
    }

    if (ir[k].get_val_profit()&&ui->textEditProfit->text().isEmpty() ){

        ErrorForm::showerror();

        return;
    }

    if (ir[k].get_val_maintain()&&ui->textEditAcquire->text().isEmpty() ){

        ErrorForm::showerror();

        return;
    }

    ir[k].acquire.cost_first_year = ui->textEditAcquire->text().toInt();


    ir[k].profit.profit = ui->textEditProfit->text().toInt();


    if (ir[k].isEmptyIR()){

        ErrorForm::showerror();

        return;
    }

    this->hide();

    //    } else {

    //        ErrorForm::showerror();
    //    }
}

void init_mantain (int element){

    ir[element].maintain->consumables = 0;
    ir[element].maintain->count_employees = 0;
    ir[element].maintain->salory = NULL;
    ir[element].maintain->tax = NULL;

}

//bool FormIr::isEmptyformIR(){

//    if (ir[k].get_val_develop())  {
//        if (   ir[k].develop!=NULL) {

//            if (ir[k].develop->get_first_year().isNull()) {return true;}

//            if (ir[k].develop->get_years_develop()<=0)    {return true;}

//            if ((ir[k].develop->get_number_employees() != NULL) && (ir[k].develop->get_consumables() != NULL)) {

//                for (int i=0;i<ir[k].develop->get_years_develop();i++){

//                    if (ir[k].develop->get_number_employees()[i] == NULL) {return true;}

//                }

//            }else{
//                return  true;
//            }
//        }else{
//            return true;
//        }

//    }

//    if(ir[k].get_val_maintain()){

//        if (ir[k].maintain != NULL){

//            qDebug()<<"nval_maintain==1 and mantain != NULL";

//            if (ir[k].maintain->consumables <= 0) {
//                qDebug()<<"\nir[k].maintain->consumables: "<<ir[k].maintain->consumables;
//                qDebug()<<"\nacquire.cost_first_year: "<<ir[k].acquire.cost_first_year;
//                qDebug()<<"\nir[k].profit.profit: "<< ir[k].profit.profit;

//                return true;}

//            if (ir[k].maintain->count_employees <= 0) {return true;}

//            if (ir[k].maintain->salory == NULL) {return true;}
//            if (ir[k].maintain->tax == NULL) {return true;}

//        }

//        else
//        {   qDebug()<<"nval_maintain==1 or mantain == NULL";
//            return true;
//        }
//    }

//    return false;
//}
