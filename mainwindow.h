#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"
#include "tableir.h"
#include "errorform.h"
#include "glob.h"
#include "ir.h"

extern IR *ir;
extern int count_ir;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_butt_enter_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
