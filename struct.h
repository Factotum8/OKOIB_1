#ifndef STRUCT_H
#define STRUCT_H


#include <QDate>

struct Employees {

    int salory; //размер заработной платы каждого из сотрудников, обслуживающих ИР
    int tax; //размер отчислений с заработной платы каждого из сотрудников, обслуживающих ИР
};

struct Acquire {

    double cost_first_year;
};


struct Maintain{

    int count_employees; //количество сотрудников, обслуживающих  ИР
    int* salory; //размер заработной платы каждого из сотрудников, обслуживающих ИР
    int* tax; //размер отчислений с заработной платы каждого из сотрудников, обслуживающих ИР
    int consumables; //общие затраты на расходные материалы при обслуживании ИР
};

struct Profit{

    int profit; //прибыль от использования ресурса в течение года
};\

struct cost_index{ // индексы увеличения ценн

    QDate year;
    double index;

};

enum Tag {
    info_resource =0,         //0
    name =1,         //1
    first_year =2, //0
    planned_year =3,       //1
    develop =4,
    start_year =5,
    years_develop =6,
    year =7, // скорее всего переделаешь на year_develop
    employees =8,
    profit =9
};

#endif // STRUCT_H
