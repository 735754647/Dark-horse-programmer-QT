#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T10:49:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QThread
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    mythread.cpp

HEADERS  += mywidget.h \
    mythread.h

FORMS    += mywidget.ui
CONFIG += c++11
