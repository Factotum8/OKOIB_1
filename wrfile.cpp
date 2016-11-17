#include "wrfile.h"

WRFile::WRFile(QString nameFile)
{
    QDomDocument domDoc;

    QFile file(nameFile);

    if (file.open(QIODevice::ReadOnly)){
        if(domDoc.setContent(&file)){

            QDomElement domElement = domDoc.documentElement();

            tarverseNode(domElement);
        }
        file.close();
    }
}

void WRFile::tarverseNode(const QDomNode& node)
{

}
