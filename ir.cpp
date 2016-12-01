#include "ir.h"
#include "develop.h"
#include "struct.h"

int count_cost_index=40;
cost_index* c_index=NULL;

IR::IR()
{

    develop=NULL; //new Develop (years_develop);

    val_acquire=0;
    val_develop=0;
    val_maintain=0;
    val_profit=0;

    this_year.setDate(1,1,1);
    planned_year.setDate(1,1,1);;
    maintain = NULL;
    acquire.cost_first_year=0;
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

void IR::set_mantain_salory(int count){

    if (maintain == NULL) qDebug ()<< "ALL PIZDA";

    if (maintain->salory == NULL){

        maintain->salory = new int [count];

    } else {

        delete maintain->salory;

        maintain->salory = new int [count];

    }
}

void IR::set_mantain_tax(int count){

    if (maintain->tax == NULL){

        maintain->tax = new int [count];

    }  else {

        delete maintain->tax;

        maintain->tax = new int [count];

    }
}

//////////////////////

void IR::set_mantain_consumables(int count){

    maintain->consumables=count;
}

int IR::cost_acquire(){

    int index_year=0;

    for (int i=0;i<count_cost_index;i++){

        if (get_first_year().year()== c_index[i].year.year()){

            index_year=i;
        }

    }

    double Ig=1;

    for (int i=index_year; i < (this_year.year()-1); i++){

        Ig= c_index[i].index * Ig;

    }

    return round (  (double)acquire.cost_first_year*Ig*(1-((double)this_year.year()-1)/(double)planned_year.year())  );

}


int IR::cost_development(){

    int base_salory_tax [develop->get_years_develop()] , first_year_develop=0,first_year_exploitation=0;

    double accumulated_salory_tax=0.0;

    for (int i=0;i<count_cost_index;i++){

        if (develop->get_first_year().year() == c_index[i].year.year()){

            first_year_develop=i;

            qDebug()<<"\n first_year_develop:"<<c_index[i].index;
        }

        if (first_year.year() == c_index[i].year.year()){

            first_year_exploitation=i;

            qDebug()<<"\n first_year_exploitation:"<<c_index[i].index;
        }

    }

    qDebug()<<"\ndevelop->get_count_employees: "<<develop->get_count_employees();

    for (int j=0;j<develop->get_years_develop();j++){

        for (int i=0;i<develop->get_count_employees();i++){

            base_salory_tax[j] = develop->get_number_employees()[i][j].salory + develop->get_number_employees()[i][j].tax;

//            qDebug()<<"\n salory:"<<develop->get_number_employees()[i][j].salory;

//            qDebug()<<"\n tax:"<<develop->get_number_employees()[i][j].tax;

        }

        base_salory_tax[j]+=develop->get_consumables()[j];

        qDebug()<<"\n base_salory_tax[j]:  "<<base_salory_tax[j];

    }

    accumulated_salory_tax = base_salory_tax[0];

    for (int i=1;i<develop->get_years_develop();i++){

        accumulated_salory_tax = c_index[first_year_develop+i-1].index * accumulated_salory_tax + base_salory_tax[i];
    }

    for (int i= first_year_develop+develop->get_years_develop()-1;i< (this_year.year()-1)  ;i++){

        accumulated_salory_tax = accumulated_salory_tax * c_index[i].index;

        qDebug()<<"\n retard"<<i;
    }

//    qDebug()<<"\n double or int: "<<(1-((double)this_year.year()-1)/(double)planned_year.year());

    return round(  accumulated_salory_tax= accumulated_salory_tax * (1-((double)this_year.year()-1)/(double)planned_year.year())  );
}

int IR::cost_maintain(){

    int cost=0;

    for (int i=0;i<maintain->count_employees;i++){

        cost+=maintain->salory[i]+maintain->tax[i];
    }

    return cost+maintain->consumables;

}


bool IR::isEmptyIR()
{

    if (get_val_develop())  {
        if (   develop!=NULL) {

            if (develop->get_first_year().isNull()) {return true;}

            if (develop->get_years_develop()<=0)    {return true;}

            if ((develop->get_number_employees() != NULL) && (develop->get_consumables() != NULL)) {

                qDebug()<<"\nisEmptyIR count_employees: "<<develop->get_count_employees();
                qDebug()<<"\nisEmptyIR years_develop: "<<develop->get_years_develop();

                for (int i=0;i<develop->get_count_employees();i++){
                    for (int j=0;j<develop->get_years_develop();j++){

                        //                        if (develop->get_number_employees()[i][j].salory <= 0) {return true;}
                        //                        if (develop->get_number_employees()[i][j].tax <= 0) {return true;}
                        qDebug()<<"\n isEmptyIR salory:["<<i<<","<<j<<"] = "<< develop->get_number_employees()[i][j].salory;
                        qDebug()<<"\n isEmptyIR tax:["<<i<<","<<j<<"] = "<< develop->get_number_employees()[i][j].tax;


                    }
                }

            }else{
                return  true;
            }
        }else{
            return true;
        }

    }

    if(get_val_maintain()){

        if (maintain != NULL){

            qDebug()<<"nval_maintain==1 and mantain != NULL";

            if (maintain->consumables <= 0) {
                qDebug()<<"\nir[k].maintain->consumables: "<<maintain->consumables;
                qDebug()<<"\nacquire.cost_first_year: "<<acquire.cost_first_year;
                qDebug()<<"\nir[k].profit.profit: "<< profit.profit;

                return true;}

            if (maintain->count_employees <= 0) {return true;}

            if (maintain->salory == NULL) {return true;}
            if (maintain->tax == NULL) {return true;}

        }

        else
        {   qDebug()<<"nval_maintain==1 or mantain == NULL";
            return true;
        }
    }

    if(get_val_acquire()){

        if (acquire.cost_first_year <= 0) {return true;}
    }

    if(get_val_profit()){

        if(profit.profit<=0){return true;}
    }

    return false;
}


bool isEmptyCostIndex (cost_index *pointer)
{
    if (pointer == NULL) { return true;}

    for (int i=0;i<count_cost_index;i++){

        qDebug()<<"\n isEmptyCostIndex c_index: "<<pointer[i].index;
        if(pointer[i].index <= 0) {return true;}
        if(pointer[i].year.year() <= 0) {return true;}

    }

    return false;
}
