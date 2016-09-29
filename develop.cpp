#include "develop.h"



Develop::Develop(int years){

    years_develop=years;
    first_year.setDate(0000,00,00);
    number_employees= new int [years];
    salory= new double [years];
    tax= new double[years];
    consumables=new double [years];
}

int * Develop::get_number_employees(){

    return number_employees;
}



double * Develop::get_salory(){

    return salory;
}

double * Develop::get_tax(){

    return tax;
}

double * Develop::get_consumables(){

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
