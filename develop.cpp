#include "develop.h"



Develop::Develop(int years){

    years_develop=years;
    first_year.setDate(0000,00,00);
    number_employees = NULL;//new Employees*;
    //delete number_employees;
    //free(number_employees);
    salory= new int [(years!=0)?years:1];
    tax= new int [(years!=0)?years:1];
    consumables=new int [(years!=0)?years:1];
}

Employees** Develop::get_number_employees(){

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

void Develop::init_number_employees(int count_employees, int count_years){

    qDebug()<<count_employees<<" "<<count_years;

    //    Employees ** mas = new Employees*[count_employees];

    //    for (int i=0;i<count_years;i++){

    //           mas[i] = new Employees [count_years];
    //        }
    if (this->number_employees == NULL){

        this->number_employees = new struct Employees* [count_employees];

        for (int i=0;i<count_employees;i++){

            this->number_employees[i] = new Employees [count_years];
        }
    }else {

        ErrorForm::showerror();

    }

}

void Develop::set_number_employees(Employees** pEmployees){

    this->number_employees = pEmployees;
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

QDate Develop::set_first_year(int time){

    QDate date(0000,00,00);

    date.addYears(time);

    return date;
}
