#-------------------------------------------------
#
# Project created by QtCreator 2016-03-13T01:22:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CarManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp

HEADERS  += mainwindow.h \
    login.h

FORMS    += mainwindow.ui \
    login.ui

CONFIG += c++11
