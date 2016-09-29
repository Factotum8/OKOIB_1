#ifndef IR_H
#define IR_H

#include <QTime>
#include "develop.h"
#include "struct.h"

class IR
{
private:
    QDate first_year; //первый календарный год эксплуатации
    QDate this_year; //текущий год эксплуатации
    QDate planned_year; //планируемый срок эксплуатации
    bool val_acquire; //приобретаемый
    bool val_develop; //разрабатываемый
    bool val_maintain; //обслуживаемый
    bool val_profit; //приносящий прибыль
    Acquire acquire;
    Develop *develop;
    Maintain maintain;
    Profit profit;

public:
    IR(int years_develop);
};


#endif // IR_H
