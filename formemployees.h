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

namespace Ui {
class FormEmployees;
}

class FormEmployees : public QWidget
{
    Q_OBJECT

public:
    explicit FormEmployees(int count_employees,int count_years, QWidget *parent = 0);
    ~FormEmployees();

private slots:
    void on_ButtonExit_clicked();

private:
    Ui::FormEmployees *ui;
};

#endif // FORMEMPLOYEES_H
