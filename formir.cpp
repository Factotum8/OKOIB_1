#include "formir.h"

int k=0;

FormIr::FormIr(int i,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormIr)
{
    ui->setupUi(this);

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

        ui->textEditAcquire->setInputMask("D0");
    }

    if (!ir[i].get_val_maintain()){

        ui->frameMantain->hide();

    } else {

        ui->textEditEmployeesMaint->setInputMask("D0000");
    }

    if (!ir[i].get_val_profit()){

        ui->frameProfit->hide();
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

//void FormIr::on_Save_clicked()
//{

//    if (ir[k].get_val_develop()&!ui->textEditEmployeesDev->text().isEmpty()&!ui->textEditFirstYearDev->text().isEmpty()&!ui->textEditYearsDev->text().isEmpty()){

//        ir[k].develop = new Develop(ui->textEditYearsDev->text().toInt());

//        ir[k].develop->set_first_year(ui->textEditFirstYearDev->text().toInt());

//        //            ir[k].develop->set_number_employees(ui->textEditEmployeesDev->text().toInt());

//    }

//    if (ir[k].get_val_acquire()&!ui->textEditAcquire->text().isEmpty()){

//        //ir[k].acquire.cost_first_year
//    }

//}

void FormIr::on_TableDev_clicked()
{
    buttclickeddev(true);
}

void FormIr::on_TableMaintain_clicked()
{
    if (!ui->textEditEmployeesMaint->text().isEmpty()){

        //        ir[k].maintain->salory = new int[ui->textEditEmployeesMaint->text().toInt()];

        ir[k].set_mantain_salory(ui->textEditEmployeesMaint->text().toInt());
        ////////////////////////////////////////////////////////////////////////////////////////////

        FormConsumablesDev* formconsumablesmain = new FormConsumablesDev(3,k,ui->textEditEmployeesMaint->text().toInt());

        formconsumablesmain->setAttribute(Qt::WA_DeleteOnClose);

        formconsumablesmain->show();

    } else {

        ErrorForm::showerror ();
    }

}

void FormIr::on_ButtonInputTaxMaint_clicked()
{
    if (!ui->textEditEmployeesMaint->text().isEmpty()){

        //        ir[k].maintain->tax = new int[ui->textEditEmployeesMaint->text().toInt()];

        ir[k].set_mantain_tax(ui->textEditEmployeesMaint->text().toInt());

        FormConsumablesDev* formtaxmain = new FormConsumablesDev(2,k,ui->textEditEmployeesMaint->text().toInt());

        formtaxmain->setAttribute(Qt::WA_DeleteOnClose);

        formtaxmain->show();

    } else {

        ErrorForm::showerror ();
    }
}

void FormIr::on_ButtonConsumablesMain_clicked()
{
    //    ir[k].maintain->tax = new int [ir[k].get_this_year().year()-ir[k].get_first_year().year()];

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

        if (ir[k].develop == NULL){

            ir[k].develop =new Develop(ui->textEditFirstYearDev->text().toInt(),ui->textEditEmployeesDev->text().toInt(), ui->textEditYearsDev->text().toInt());

        } else {

            delete (ir[k].develop);

            ir[k].develop =new Develop(ui->textEditFirstYearDev->text().toInt(),ui->textEditEmployeesDev->text().toInt(), ui->textEditYearsDev->text().toInt());
        }

        FormEmployees* formfmployees = new FormEmployees(k,flag,ui->textEditEmployeesDev->text().toInt(),ui->textEditYearsDev->text().toInt());

        formfmployees->setAttribute(Qt::WA_DeleteOnClose);

        formfmployees->show();

    }else{

        ErrorForm::showerror ();
    }
}


void FormIr::buttclickedmain (bool flag){

    if (ir[k].get_val_develop()&!ui->textEditEmployeesMaint->text().isEmpty()){

        if (ir[k].maintain == NULL){

            ir[k].maintain =new Maintain;

        } else {

            delete (ir[k].maintain);

            ir[k].maintain =new Maintain;
        }

        FormEmployees* formfmployees = new FormEmployees(k,flag,ui->textEditEmployeesDev->text().toInt(),ui->textEditYearsDev->text().toInt());

        formfmployees->setAttribute(Qt::WA_DeleteOnClose);

        formfmployees->show();

    }else{

        ErrorForm::showerror ();
    }
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
    if (!ui->textEditAcquire->text().isEmpty()&!ui->textEditProfit->text().isEmpty()&!ui->textEditEmployeesDev->text().isEmpty()
            &!ui->textEditEmployeesMaint->text().isEmpty()&!ui->textEditFirstYearDev->text().isEmpty()&!ui->textEditYearsDev->text().isEmpty())
    {

        ir[k].acquire.cost_first_year = ui->textEditAcquire->text().toInt();

        ir[k].profit.profit = ui->textEditProfit->text().toInt();

        close();

    } else {

        ErrorForm::showerror();
    }
}
