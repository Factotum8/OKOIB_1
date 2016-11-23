#include "mainwindow.h"

//IR *ir;
//extern int count_ir;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout* pqvbxLayout = new QVBoxLayout;

    pqvbxLayout->setMargin(5);

    pqvbxLayout->setSpacing(5);

    pqvbxLayout->insertStretch(5);

    pqvbxLayout->addWidget(ui->lab_quantity);

    pqvbxLayout->addWidget(ui->edit_quantity);

    pqvbxLayout->addWidget(ui->butt_enter);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_butt_enter_clicked()
{
    QString str=ui->edit_quantity->text();

    if (str.length()==0){

//        ErrorForm *e = new ErrorForm;

//        e->setAttribute(Qt::WA_DeleteOnClose);

//        e->setWindowFlags(Qt::WindowStaysOnTopHint);

//        e->move(500,500);

//        e->show();

        ErrorForm::showerror();

        return;
    }

    count_ir=str.toInt();

    ir = new IR [count_ir];

    TableIr *w2 = new TableIr;

    w2->setAttribute(Qt::WA_DeleteOnClose);

    w2->move(10,10);
    //w2->setWindowFlags(Qt::WindowStaysOnTopHint);
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

void MainWindow::on_butt_fileName_clicked()
{
    if (!ui->edit_fileName->text().isEmpty())
    {
        WRFile wrfile(ui->edit_fileName->text());

        for (int i=0;i<count_ir;i++)
        {
            if (ir[i].isEmptyIR())
            {
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
}
