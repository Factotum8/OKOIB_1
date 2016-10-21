#ifndef FORMEMPLOYEES_H
#define FORMEMPLOYEES_H

#include <QWidget>

#include "itemdelegate.h"
#include "global.h"

namespace Ui {
class FormEmployees;
}

class FormEmployees : public QWidget
{
    Q_OBJECT

public:
    explicit FormEmployees(int count_employees,int count_years, QWidget *parent = 0);
    ~FormEmployees();

private:
    Ui::FormEmployees *ui;
};

#endif // FORMEMPLOYEES_H
