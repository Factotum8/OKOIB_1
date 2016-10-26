#include "develop.h"



Develop::Develop(int years){

    years_develop=years;
    first_year.setDate(0000,00,00);
    number_employees = NULL;
    consumables=new int [(years!=0)?years:1];
}

Develop::Develop(int first_year,int count_employees, int count_years){

    years_develop=count_years;

    this->first_year.setDate(first_year,00,00);

    if ( NULL != (salory = new Employees* [count_employees]) && NULL != (tax = new Employees* [count_employees])
         && NULL != (number_employees = new Employees* [count_employees]) ){

        for (int i=0;i<count_employees;i++){

            this->salory[i] = new Employees [count_years];
            this->tax[i] = new Employees [count_years];
            this->number_employees[i] = new Employees [count_years];
        }
    }
    else{
        qDebug()<<"\nCan't allocate memory\n";
        exit(0);
    }

    for (int i=0;i<count_employees;i++){

        for (int j=0;j<count_years;j++){

            this->number_employees[i][j].salory = 0;
        }

    }

    consumables=new int [(count_years!=0)?count_years:1];
}

Employees** Develop::get_number_employees(){

    return number_employees;
}



 Employees** Develop::get_salory(){

    return salory;
}

 Employees** Develop::get_tax(){

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


//void Develop::set_salory(double * mas){

//    for (int i=0;i<years_develop;i++){

//        salory[i]=mas[i];
//    }
//}

//void Develop::set_tax(double * mas){

//    for (int i=0;i<years_develop;i++){

//        tax[i]=mas[i];
//    }
//}

QDate Develop::set_first_year(int time){

    QDate date(0000,00,00);

    date.addYears(time);

    return date;
}
