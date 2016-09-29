#include "develop.h"



Develop::Develop(int years){

    years_develop=years;
    first_year.setDate(0000,00,00);
    number_employees= new int [years];
    salory= new int [(years!=0)?years:1];
    tax= new int [(years!=0)?years:1];
    consumables=new int [(years!=0)?years:1];
}

int * Develop::get_number_employees(){

    return number_employees;
}



int * Develop::get_salory(){

    return salory;
}

int * Develop::get_tax(){

    return tax;
}

int * Develop::get_consumables(){

    return consumables;
}

void Develop::set_consumables(double * mas){

    for (int i=0;i<years_develop;i++){

        consumables[i]=mas[i];
    }
}

void Develop::set_number_employees(int * mas){

    for (int i=0;i<years_develop;i++){

        number_employees[i]=mas[i];
    }
}

void Develop::set_salory(double * mas){

    for (int i=0;i<years_develop;i++){

        salory[i]=mas[i];
    }
}

void Develop::set_tax(double * mas){

    for (int i=0;i<years_develop;i++){

        tax[i]=mas[i];
    }
}
