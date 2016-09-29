#ifndef IR_H
#define IR_H

#include <QTime>
#include "develop.h"

class IR
{
private:

private:
    QTime first_year; //первый календарный год эксплуатации
    QTime this_year; //текущий год эксплуатации
    QTime planned_year; //планируемый срок эксплуатации
    bool acquire; //приобретаемый
    bool develop; //разрабатываемый
    bool maintain; //обслуживаемый
    bool profit; //приносящий прибыль
    Acquire acquire;
    Develop develop;
    Maintain maintain;
    Profit profit;



public:
    IR(int years_develop);
};

struct Acquire {

    double cost_first_year;
};

/*class Develop {

private:
    QTime first_year; //первый календарный год разработки,
    int years_develop; //количество лет разработки,
    int * number_employees=NULL; //количество сотрудников, участвующих в разработке ИР, в каждый год разработки
    double *salory=NULL; //размер заработной платы каждого из сотрудников, участвующих в разработке ИР, в каждый год разработки
    double *tax=NULL; //размер отчислений с заработной платы каждого из сотрудников, участвующих в разработке ИР, в каждый год разработки,
    double *consumables=NULL; //общие затраты на расходные материалы при разработке ИР в каждый год разработки

public:
    Develop(int years_develop){

        first_year=0;
        number_employees= new int [years_develop];
        salory= new double [years_develop];
        tax= new double[years_develop];
        consumables=new double [years_develop];
    }

    int* get_number_employees(){

        return number_employees;
    }

    double * get_salory (){

        return salory;
    }

    double* get_tax (){

        return tax;
    }

    double* consumables (){

        return consumables;
    }
};*/

struct Maintain{

    int number_employees; //количество сотрудников, обслуживающих  ИР
    double salory; //размер заработной платы каждого из сотрудников, обслуживающих ИР
    double tax; //размер отчислений с заработной платы каждого из сотрудников, обслуживающих ИР
    double consumables; //общие затраты на расходные материалы при обслуживании ИР
};

struct Profit{

    double profit; //прибыль от использования ресурса в течение года
};

#endif // IR_H
