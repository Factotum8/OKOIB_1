#ifndef FORMIR_H
#define FORMIR_H

#include <QWidget>
#include <QLineEdit>

#include "ui_formir.h"
#include "global.h"
#include "errorform.h"
#include "formemployees.h"
#include "develop.h"
#include "formconsumablesdev.h"

namespace Ui {
class FormIr;
}

class FormIr : public QWidget
{
    Q_OBJECT

public:
    explicit FormIr(int i, QWidget *parent = 0);
    ~FormIr();

private slots:
    void on_Exit_clicked();

    //void on_Save_clicked();

    void on_TableDev_clicked();

    void on_TableMaintain_clicked();

    void on_ButtTaxDev_clicked();

    void buttclickeddev (bool flag);

    void buttclickedmain (bool flag);

    void on_ButtonInputTaxMaint_clicked();

    void on_ButtonConsumablesDev_clicked();

private:
    Ui::FormIr *ui;
};

#endif // FORMIR_H

