#ifndef DEVELOP_H
#define DEVELOP_H

#include <QTime>

class Develop
{

private:
    QDate first_year; //первый календарный год разработки,
    int years_develop; //количество лет разработки,
    int * number_employees=NULL; //количество сотрудников, участвующих в разработке ИР, в каждый год разработки
    int * salory=NULL; //размер заработной платы каждого из сотрудников, участвующих в разработке ИР, в каждый год разработки
    int * tax=NULL; //размер отчислений с заработной платы каждого из сотрудников, участвующих в разработке ИР, в каждый год разработки,
    int * consumables=NULL; //общие затраты на расходные материалы при разработке ИР в каждый год разработки

public:
    Develop(int years);

    QDate get_first_year();

    int* get_number_employees();

    int * get_salory ();

    int* get_tax ();

    int* get_consumables ();

    void set_consumables(double * mas );

    void set_tax(double * mas);

    void set_salory(double * mas );

    void set_number_employees(int * mas);

    QDate set_first_year (QDate time);

};

#endif // DEVELOP_H
