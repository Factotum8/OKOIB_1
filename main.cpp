#include "mainwindow.h"
#include "tableir.h"
#include "tabwidgetir.h"
#include "global.h"
#include "formir.h"


#include <QApplication>

extern TabWidgetIr *twi;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.move(300,300);
    w.setFixedHeight(250);
    w.setFixedWidth(226);

    w.show();

    return a.exec();
}

