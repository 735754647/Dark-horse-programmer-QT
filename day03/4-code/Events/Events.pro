#-------------------------------------------------
#
# Project created by QtCreator 2016-03-08T10:27:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Events
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mylabel.cpp

HEADERS  += widget.h \
    mylabel.h

FORMS    += widget.ui

CONFIG += c++11
