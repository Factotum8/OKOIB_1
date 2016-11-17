#ifndef WRFILE_H
#define WRFILE_H

#include <QtXml>

class WRFile
{
public:
    WRFile(QString nameFile);
private:
    void tarverseNode(const QDomNode& node);
};

#endif // WRFILE_H
