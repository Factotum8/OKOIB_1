#include "ir.h"
#include "develop.h"
#include "struct.h"


IR::IR(int years_develop)
{
    develop= new Develop (years_develop);

     val_acquire=0;
     val_develop=0;
     val_maintain=0;
     val_profit=0;

    first_year.setDate(0000,00,00);;
    this_year.setDate(0000,00,00);;
    planned_year.setDate(0000,00,00);;

    acquire.cost_first_year=0;
    maintain.number_employees;
    maintain.salory=0;
    maintain.tax=0;
    maintain.consumables=0;
    profit.profit=0;

}
