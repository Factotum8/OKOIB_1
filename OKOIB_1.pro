#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T16:22:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OKOIB_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    spr.cpp \
    ir.cpp \
    develop.cpp \
    tableir.cpp \
    errorform.cpp

HEADERS  += mainwindow.h \
    spr.h \
    ir.h \
    develop.h \
    struct.h \
    tableir.h \
    errorform.h \
    global.h

FORMS    += mainwindow.ui \
    tableir.ui \
    errorform.ui
