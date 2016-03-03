#-------------------------------------------------
#
# Project created by QtCreator 2016-03-03T23:34:50
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = block
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    smtpclient.cpp

HEADERS  += mainwindow.h \
    smtpclient.h

FORMS    += mainwindow.ui
