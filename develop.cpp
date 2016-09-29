#include "develop.h"



Develop::Develop(int years){

    years_develop=years;
    first_year=0;
    number_employees= new int [years];
    salory= new double [years];
    tax= new double[years];
    consumables=new double [years];
}

Develop::get_number_employees(){

    return number_employees;
}



Develop::get_salory(){

    return salory;
}

Develop::get_tax(){

    return tax;
}

Develop::get_consumables(){

    return consumables;
}

Develop::set_consumables(double * mas){

    for (int i=0;i<years_develop;i++){

        consumables[i]=mas[i];
    }
}

Develop::set_number_employees(double * mas){

    for (int i=0;i<years_develop;i++){

        number_employees[i]=mas[i];
    }
}

Develop::set_salory(double * mas){

    for (int i=0;i<years_develop;i++){

        salory[i]=mas[i];
    }
}

Develop::set_tax(double * mas){

    for (int i=0;i<years_develop;i++){

        tax[i]=mas[i];
    }
}
