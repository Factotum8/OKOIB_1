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
        ui->textEditYearsDev->setInputMask("0D");
        ui->textEditEmployeesDev->setInputMask("0D");

    }

    if (!ir[i].get_val_acquire()){

        ui->frameAcquire->hide();

    } else {

        ui->textEditAcquire->setInputMask("0D");
    }

    if (!ir[i].get_val_maintain()){

        ui->frameMantain->hide();

    } else {

        ui->textEditEmployeesMaint->setInputMask("0D");
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

void FormIr::on_Save_clicked()
{

        if (ir[k].get_val_develop()&!ui->textEditEmployeesDev->text().isEmpty()&!ui->textEditFirstYearDev->text().isEmpty()&!ui->textEditYearsDev->text().isEmpty()){

            ir[k].develop = new Develop(ui->textEditYearsDev->text().toInt());

            ir[k].develop->set_first_year(ui->textEditFirstYearDev->text().toInt());

//            ir[k].develop->set_number_employees(ui->textEditEmployeesDev->text().toInt());

        }

        if (ir[k].get_val_acquire()&!ui->textEditAcquire->text().isEmpty()){

            //ir[k].acquire.cost_first_year
        }

}

void FormIr::on_TableDev_clicked()
{
    if (ir[k].get_val_develop()&!ui->textEditEmployeesDev->text().isEmpty()&!ui->textEditFirstYearDev->text().isEmpty()&!ui->textEditYearsDev->text().isEmpty()){

        ir[k].develop->init_number_employees(ui->textEditEmployeesDev->text().toInt(), ui->textEditYearsDev->text().toInt());

    }else{

        ErrorForm* e = new ErrorForm;

        e->show();
    }
}
