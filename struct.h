#ifndef STRUCT_H
#define STRUCT_H


#include <QDate>


struct Acquire {

    double cost_first_year;
};


struct Maintain{

    int number_employees; //количество сотрудников, обслуживающих  ИР
    double salory; //размер заработной платы каждого из сотрудников, обслуживающих ИР
    double tax; //размер отчислений с заработной платы каждого из сотрудников, обслуживающих ИР
    double consumables; //общие затраты на расходные материалы при обслуживании ИР
};

struct Profit{

    double profit; //прибыль от использования ресурса в течение года
};

struct cost_index{

    QDate year;
    double index;

};

#endif // STRUCT_H
