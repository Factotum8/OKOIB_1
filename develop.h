#ifndef DEVELOP_H
#define DEVELOP_H

#include <QTime>
#include <QDebug>

#include "struct.h"
#include "errorform.h"

class Develop
{

private:
    QDate first_year; //первый календарный год разработки,
    int years_develop; //количество лет разработки,
    Employees** number_employees = 0 ; //зарплаты (количество сотрудников), участвующих в разработке ИР, в каждый год разработки
    Employees** salory= NULL; //размер заработной платы каждого из сотрудников, участвующих в разработке ИР, в каждый год разработки
    Employees** tax= NULL; //отчисления (размер отчислений) с заработной платы каждого из сотрудников, участвующих в разработке ИР, в каждый год разработки,
    int * consumables=NULL; //общие затраты на расходные материалы при разработке ИР в каждый год разработки

public:
    Develop(int years);

    Develop(int first_year,int count_employees, int count_years);

    QDate get_first_year();

    Employees** get_number_employees();

    void init_number_employees(int count_employees, int count_years);

    void set_number_employees(Employees** pEmployees);

    Employees** get_salory ();

    Employees** get_tax ();

    int* get_consumables ();

    void set_consumables(double * mas );

//    void set_tax(double * mas);

//    void set_salory(double * mas );


    QDate set_first_year (QDate time);

    QDate set_first_year (int time);

};

#endif // DEVELOP_H
