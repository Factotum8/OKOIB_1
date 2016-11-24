#include "develop.h"



Develop::Develop(int years){

    years_develop=years;
    first_year.setDate(1,1,1);
    number_employees = NULL;
    consumables= NULL;
    count_employees=0;
//    salory = NULL;
//    tax = NULL;
}

Develop::Develop(int first_year,int count_employees, int count_years){

    years_develop=count_years;

    this->first_year.setDate(first_year,1,1);

    if (  NULL != (number_employees = new Employees* [count_employees]) ){

        for (int i=0;i<count_employees;i++){

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

}



Employees** Develop::get_number_employees(){

    return number_employees;
}



//Employees** Develop::get_salory(){

//    return salory;
//}

//Employees** Develop::get_tax(){

//    return tax;
//}

int* Develop::get_consumables(){

    return consumables;
}

void Develop::set_consumables(int count_years){

    consumables = new int [count_years];
}

void Develop::init_number_employees(int count_employees, int count_years){

    qDebug()<<"\ncount_employees: "<<count_employees<<" count_years: "<<count_years;

    if (this->number_employees == NULL){

        this->number_employees = new struct Employees* [count_employees];

        for (int i=0;i<count_employees;i++){

            this->number_employees[i] = new Employees [count_years];
        }
    }else {

        ErrorForm::showerror();

        return;

    }

    for (int i=0;i<count_employees;i++){
        for(int j=0;j<count_employees;j++){
            this->number_employees[i][j].salory = 0;
            this->number_employees[i][j].tax = 0;
        }
    }

}

void Develop::set_number_employees(Employees** pEmployees){

    this->number_employees = pEmployees;
}



QDate Develop::set_first_year(int time){

    QDate date(time,1,1);

    return date;
}

void Develop::set_count_employees(int val){

    count_employees = val;
}

void Develop::set_years_develop(int val){

    years_develop = val;
}

//int Develop::get_years_develop(){

//    return this->years_develop;
//}

QDate Develop::get_first_year(){

   return first_year;

}

int  Develop::get_years_develop(){


    return years_develop;
}

int  Develop::get_count_employees(){

    return count_employees;
}
