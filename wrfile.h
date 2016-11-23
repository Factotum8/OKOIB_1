#ifndef WRFILE_H
#define WRFILE_H

#include <QtXml>
#include <QMetaEnum>
#include <QDebug>
#include <QObject>
#include <iostream>


#include "global.h"
#include "struct.h"

using std::cout;

extern IR *ir;
extern int count_ir;
extern cost_index* c_index;
extern int count_cost_index;

class WRFile
{
    Q_GADGET //https://www.christian-gmeiner.info/2015/05/qmetaenum-serializing-c-enums/
    Q_ENUMS(Tag) //https://habrahabr.ru/post/149085/

public:
    WRFile(QString nameFile);

    int get_numb_tag(QString str);

    QString regexp_numb(QString pnumb);

    enum Tag {
        info_resource=0,         //0
        name=1,         //1
        first_year=2, //0
        planned_year=3,       //1
        develop =4,
        start_year_develop =5,
        years_develop =6,
        develop_employees_count = 7,
        year_develop =8, // скорее всего переделаешь на year_develop
        employee_develop =9,
        profit=10,
        this_year=11,
        tax_employee_develop=12,
        consumables_develop=13,
        maintain=14,
        maintain_employees_count=15,
        employees_maintain=16,
        tax_employee_maintain=17,
        consumable_maintain=18
    };

private:
    int calculate_count_ir (const QDomNode& node);
    void traverseNode(const QDomNode& node);
    QMetaEnum tags;
};

#endif // WRFILE_H
