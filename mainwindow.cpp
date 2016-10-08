#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tableir.h"

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
    ui->edit_quantity->text();

    TableIr *w2 = new TableIr;

    w2->setAttribute(Qt::WA_DeleteOnClose);

    w2->show();
}

