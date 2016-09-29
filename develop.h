#ifndef DEVELOP_H
#define DEVELOP_H

#include <QTime>

class Develop
{

private:
    QTime first_year; //первый календарный год разработки,
    int years_develop; //количество лет разработки,
    int * number_employees=NULL; //количество сотрудников, участвующих в разработке ИР, в каждый год разработки
    double *salory=NULL; //размер заработной платы каждого из сотрудников, участвующих в разработке ИР, в каждый год разработки
    double *tax=NULL; //размер отчислений с заработной платы каждого из сотрудников, участвующих в разработке ИР, в каждый год разработки,
    double *consumables=NULL; //общие затраты на расходные материалы при разработке ИР в каждый год разработки

public:
    Develop(int years_develop){

        first_year;
        number_employees= new int [years_develop];
        salory= new double [years_develop];
        tax= new double[years_develop];
        consumables=new double [years_develop];
    }

    QTime get_first_year();

    int* get_number_employees();

    double * get_salory ();

    double* get_tax ();

    double* get_consumables ();

    void set_consumables(double * mas );

    void set_tax(double * mas);

    void set_salory(double * mas );

    void set_number_employees(int * mas);

    QTime set_first_year (QTime time);

};

#endif // DEVELOP_H
