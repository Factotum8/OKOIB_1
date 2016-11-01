#ifndef FORMCONSUMABLESDEV_H
#define FORMCONSUMABLESDEV_H

#include <QWidget>

#include "global.h"
//#include "itemdelegatefloat.h"

namespace Ui {
class FormConsumablesDev;
}

class FormConsumablesDev : public QWidget
{
    Q_OBJECT

public:
    explicit FormConsumablesDev(int element,int count_years,QWidget *parent = 0);
    explicit FormConsumablesDev(int flagbutt,int element,int employees,QWidget *parent = 0);

    ~FormConsumablesDev();

    bool isnull (int j);
    void filling_mantain();

private slots:
    void on_ButtonExit_clicked();

    void on_ButtonSave_clicked();

private:
    Ui::FormConsumablesDev *ui;

    int element;
    int count_years;
    int count_employees;
    int flagbutt;
    int delta_years;
};

#endif // FORMCONSUMABLESDEV_H
