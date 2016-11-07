#include "develop.h"



Develop::Develop(int years){

    years_develop=years;
    first_year.setDate(1,1,1);
    number_employees = NULL;
    consumables= NULL;
    salory = NULL;
    tax = NULL;
}

Develop::Develop(int first_year,int count_employees, int count_years){

    years_develop=count_years;
    count_employees =0;
    consumables= NULL;

    this->first_year.setDate(first_year,1,1);

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

    //    consumables=new int [(count_years!=0)?count_years:1];

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

int* Develop::get_consumables(){

    return consumables;
}

void Develop::set_consumables(int count_years){

    consumables = new int [count_years];
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

    QDate date(time,1,1);

//    date.addYears(time);

    return date;
}

int Develop::get_years_develop (){

    return years_develop;
}

QDate Develop::get_first_year(){

    return first_year;
}


int  Develop::get_count_employees(){

    return count_employees;
}

int  Develop::get_count_years(){

    return count_years;
}

void  Develop::set_count_employees(int count){

    count_employees= count;
}

void  Develop::set_count_years(int count){

    count_years= count;
}
