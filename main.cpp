#include "mainwindow.h"
#include "tableir.h"
#include "tabwidgetir.h"
#include "global.h"

#include <QApplication>

extern TabWidgetIr *twi;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    twi->get_TabWidget() = new QTabWidget;

    return a.exec();
}
