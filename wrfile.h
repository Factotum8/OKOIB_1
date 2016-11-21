#ifndef WRFILE_H
#define WRFILE_H

#include <QtXml>
#include <QMetaEnum>
#include <QDebug>
#include <QObject>


#include "global.h"
#include "struct.h"


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

    enum Tag {
        info_resource=0,         //0
        name =1,         //1
        first_year =2, //0
        planned_year =3,       //1
        develop =4,
        start_year =5,
        years_develop =6,
        year =7, // скорее всего переделаешь на year_develop
        employees =8,
        profit =9
    };

private:
    int calculate_count_ir (const QDomNode& node);
    void traverseNode(const QDomNode& node);
    QMetaEnum tags;
};

#endif // WRFILE_H
