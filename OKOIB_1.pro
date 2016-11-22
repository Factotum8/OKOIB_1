#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T16:22:39
#
#-------------------------------------------------

QT       += core gui
QT       +=xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OKOIB_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ir.cpp \
    develop.cpp \
    tableir.cpp \
    errorform.cpp \
    global.cpp \
    tabwidgetir.cpp \
    formir.cpp \
    itemdelegate.cpp \
    formemployees.cpp \
    itemdelegatefloat.cpp \
    formconsumablesdev.cpp \
    formcostindex.cpp \
    wrfile.cpp

HEADERS  += mainwindow.h \
    ir.h \
    develop.h \
    struct.h \
    tableir.h \
    errorform.h \
    global.h \
    tabwidgetir.h \
    formir.h \
    itemdelegate.h \
    formemployees.h \
    itemdelegatefloat.h \
    formconsumablesdev.h \
    formcostindex.h \
    wrfile.h

FORMS    += mainwindow.ui \
    tableir.ui \
    errorform.ui \
    tabwidgetir.ui \
    formir.ui \
    formemployees.ui \
    formconsumablesdev.ui \
    formcostindex.ui

OTHER_FILES += \
    data.xml
