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

        if (develop->get_first_year().year()== c_index[i].year.year()){

            index_year=i;
        }

    }

    double Ig=1;

    for (int i=index_year;i<count_cost_index;i++){

        Ig= c_index[i].index * Ig;

    }

    return round (  acquire.cost_first_year*Ig*( 1-this_year.year()/planned_year.year())  );

}


int IR::cost_development(){

    int base_salory_tax =0, accumulated_salory_tax=0,index_year=0;

    for (int i=0;i<count_cost_index;i++){

        if (develop->get_first_year().year()== c_index[i].year.year()){

            index_year=i;
        }

    }

        for(int j=0;j<develop->get_years_develop();j++){

            for (int i=0;i<develop->get_count_employees();i++){

            base_salory_tax+=develop->get_number_employees()[i][j].salory+develop->get_number_employees()[i][j].tax;
        }

        base_salory_tax+=develop->get_consumables()[j];

        accumulated_salory_tax=c_index[index_year+j].index*accumulated_salory_tax+base_salory_tax;

        base_salory_tax=0;

    }

    double Ig=1;

    for (int i=index_year;i<count_cost_index;i++){

        Ig= c_index[i].index * Ig;

    }

    return round( accumulated_salory_tax*Ig*(1-( develop->get_first_year().year() + develop->get_years_develop())/planned_year.year() ) );
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

                for (int i=0;i<develop->get_count_employees();i++){

                    if (develop->get_number_employees()[i] == NULL) {
                        return true;}

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

    return false;
}
