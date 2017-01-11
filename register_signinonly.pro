#-------------------------------------------------
#
# Project created by QtCreator 2016-08-25T18:23:07
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = register_signinonly
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    person.cpp

HEADERS  += mainwindow.h \
    person.h \
    settings.h \
    webservice.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:\Qt\5.7\msvc2013_64\bin

DISTFILES += \
    Database.csv
