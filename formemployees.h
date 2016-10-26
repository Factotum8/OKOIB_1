#ifndef FORMEMPLOYEES_H
#define FORMEMPLOYEES_H

//#include <QWidget>
#include <QtWidgets>
#include <QStandardItemModel>
#include <QDoubleSpinBox>
#include <QStandardItemEditorCreator>

#include "itemdelegate.h"
#include "global.h"
#include "ui_formemployees.h"
#include "itemdelegatefloat.h"

namespace Ui {
class FormEmployees;
}

class FormEmployees : public QWidget
{
    Q_OBJECT

public:
    explicit FormEmployees(int element,bool flag,int count_employees,int count_years, QWidget *parent = 0);
    ~FormEmployees();


private slots:
    void on_ButtonExit_clicked();

    void on_ButtonSave_clicked();

private:
    Ui::FormEmployees *ui;

    bool flag;
    int element;
    int count_employees;
    int count_years;

    bool isnull (int i,int j);
    bool dataisnull (int i, int j);
};

#endif // FORMEMPLOYEES_H
