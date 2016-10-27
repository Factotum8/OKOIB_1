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
    ~FormConsumablesDev();

private slots:
    void on_ButtonExit_clicked();

    void on_ButtonSave_clicked();

private:
    Ui::FormConsumablesDev *ui;

    int element;
    int count_years;
};

#endif // FORMCONSUMABLESDEV_H
