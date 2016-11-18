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
    Q_ENUMS(Tag)

public:
    WRFile(QString nameFile);
private:
    enum Tag tag ;
    const QString tag();

    int calculate_count_ir (const QDomNode& node);
    void traverseNode(const QDomNode& node);

    void setType(enum  Tag tag);
    void setType(const QString &tag);
};

#endif // WRFILE_H
