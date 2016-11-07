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

    int* number_employees; //количество сотрудников, обслуживающих  ИР
    int* salory; //размер заработной платы каждого из сотрудников, обслуживающих ИР
    int* tax; //размер отчислений с заработной платы каждого из сотрудников, обслуживающих ИР
    int consumables; //общие затраты на расходные материалы при обслуживании ИР
    int count_employees; //кол-во сотрудников, обслуживающих ИР
};

struct Profit{

    int profit; //прибыль от использования ресурса в течение года
};

struct cost_index{ // индексы увеличения ценн

    QDate year;
    double index;

};

struct Cost_ir{

    int acquire;
    int develop;
    int maitain;
    int profit;

};

#endif // STRUCT_H
