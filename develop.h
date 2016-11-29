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
    Employees** number_employees = NULL ; //зарплаты и отчисления сотрудников, участвующих в разработке ИР, в каждый год разработки
    int count_employees; // кол-во сорудников учасвующих в разработке
    int* consumables; //общие затраты на расходные материалы при разработке ИР в каждый год разработки

public:
    Develop(int years);

    Develop(int first_year,int count_employees, int count_years);

    QDate get_first_year();

    void set_first_year (int time);

    int  get_years_develop();

//    int  get_count_years();

    int  get_count_employees();

    int* get_consumables ();

    Employees** get_number_employees();

//    Employees** get_salory ();

//    Employees** get_tax ();

    void init_number_employees(int count_employees, int count_years);

    void init_consumables(int count_years);

//    void set_number_employees(Employees** pEmployees);

    void set_consumables(int count_years);

    void set_count_employees(int val);

    void set_years_develop(int val);


 //    void set_tax(double * mas);

//    void set_salory(double * mas );



};

#endif // DEVELOP_H
