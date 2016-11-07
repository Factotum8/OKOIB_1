#ifndef IR_H
#define IR_H

#include <QTime>
#include <QString>
#include <math.h>

#include "develop.h"
#include "struct.h"
#include "develop.h"
#include "struct.h"

extern cost_index* c_index;
extern int count_cost_index;

class IR
{
private:
    QString name;
    QDate first_year; //первый календарный год эксплуатации
    QDate this_year; //текущий год эксплуатации
    QDate planned_year; //планируемый срок эксплуатации
    bool val_acquire; //приобретаемый
    bool val_develop; //разрабатываемый
    bool val_maintain; //обслуживаемый
    bool val_profit; //приносящий прибыль
    Cost_ir cost_ir;

public:

    Acquire acquire;
    Maintain* maintain=NULL;
    Profit profit;
    Develop* develop=NULL;

    IR();

    QString get_name ();
    QDate get_first_year();
    QDate get_this_year();
    QDate get_planned_year();
    bool get_val_acquire();
    bool get_val_develop();
    bool get_val_maintain();
    bool get_val_profit();

    void set_name (QString str);
    void set_first_year (QDate date);
    void set_this_year (QDate date);
    void set_planned_year (QDate date);
    void set_val_acquire (bool val);
    void set_val_develop (bool val);
    void set_val_maintain (bool val);
    void set_val_profit (bool val);
    void set_mantain_salory(int count);
    void set_mantain_tax(int count);
    void set_mantain_consumables(int count);
    int cost_acquire();
    int cost_development();


};


#endif // IR_H
