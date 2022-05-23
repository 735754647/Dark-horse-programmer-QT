#-------------------------------------------------
#
# Project created by QtCreator 2016-03-13T09:09:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QMytest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    histogram.cpp \
    pie.cpp

HEADERS  += mainwindow.h \
    login.h \
    histogram.h \
    pie.h

FORMS    += mainwindow.ui \
    login.ui

RESOURCES += \
    src.qrc \
    aa.qrc

CONFIG += c++11
