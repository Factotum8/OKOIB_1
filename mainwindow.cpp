#include "mainwindow.h"

//IR *ir;
//extern int count_ir;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_butt_enter_clicked()
{
    QString str=ui->edit_quantity->text();

    if (str.length()==0){

        ErrorForm *e = new ErrorForm;

       // ErrorForm *e = new ErrorForm(this); проанализируй потом

        e->setAttribute(Qt::WA_DeleteOnClose);

        e->show();

        return;
    }

    count_ir=str.toInt();

    ir = new IR [count_ir];

    TabWidgetIr *twi= new TabWidgetIr;

    twi->setAttribute(Qt::WA_DeleteOnClose);

    TableIr *w2 = new TableIr;

    w2->setAttribute(Qt::WA_DeleteOnClose);


    w2->show();


}


void MainWindow::on_edit_quantity_editingFinished()
{

//    QString str=ui->edit_quantity->text();

//    if (str.length()==0){

//        ErrorForm *e = new ErrorForm;

//        e->setAttribute(Qt::WA_DeleteOnClose);

//        e->show();

//        return;
//    }

//    count_ir=str.toInt();

//    ir = new IR [count_ir];

//    TableIr *w2 = new TableIr;

//    w2->setAttribute(Qt::WA_DeleteOnClose);


//    w2->show();

}
