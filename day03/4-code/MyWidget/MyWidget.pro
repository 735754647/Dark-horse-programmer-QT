#-------------------------------------------------
#
# Project created by QtCreator 2016-03-08T09:24:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyWidget
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    smallwidget.cpp \
    mytest.cpp

HEADERS  += widget.h \
    smallwidget.h \
    mytest.h

FORMS    += widget.ui \
    smallwidget.ui \
    mytest.ui
