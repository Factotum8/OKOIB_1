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

    acquire.cost_first_year=0;
//    maintain->number_employees=NULL;
//    maintain->salory=0;
//    maintain->tax=0;
//    maintain->consumables=0;
    profit.profit=0;

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





