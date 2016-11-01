#include "ir.h"
#include "develop.h"
#include "struct.h"


IR::IR()
{

    develop=NULL; //new Develop (years_develop);

    val_acquire=0;
    val_develop=0;
    val_maintain=0;
    val_profit=0;

    first_year.setDate(0000,00,00);;
    this_year.setDate(0000,00,00);;
    planned_year.setDate(0000,00,00);;
    maintain == NULL;
    acquire.cost_first_year=0;
//        maintain->number_employees=NULL;
//        maintain->salory=NULL;
//        maintain->tax=NULL;
//        maintain->consumables=NULL;
    profit.profit=NULL;

    name="not name";
}

QDate IR::get_first_year(){

    return first_year;
}

QString IR::get_name(){

    return name;
}

QDate IR::get_planned_year(){

    return planned_year;
}

QDate IR::get_this_year(){

    return this_year;
}

bool IR::get_val_acquire(){

    return val_acquire;
}

bool IR::get_val_develop(){

    return val_develop;
}

bool IR::get_val_maintain(){

    return val_maintain;
}

bool IR::get_val_profit(){

    return val_profit;
}

void IR::set_first_year(QDate date){

    first_year=date;
}

void IR::set_name(QString str){

    name=str;
}

void IR::set_planned_year(QDate date){

    planned_year=date;
}

void IR::set_this_year(QDate date){

    this_year=date;
}

void IR::set_val_acquire(bool val){

    val_acquire=val;
}

void IR::set_val_develop(bool val){

    val_develop=val;
}

void IR::set_val_maintain(bool val){

    val_maintain=val;
}

void IR::set_val_profit(bool val){

    val_profit=val;
}

void IR::set_mantain_salory(int count){

    if (maintain->salory == NULL){

        maintain->salory = new int [count];

    } else {

        delete (maintain->salory);

        maintain->salory = new int [count];

    }
}

void IR::set_mantain_tax(int count){

    if (maintain->tax == NULL){
        maintain->tax = new int [count];
    }
}

void IR::set_mantain_consumables(int count){

    if (maintain->consumables == NULL){
        maintain->consumables = new int [count];
    }
}
