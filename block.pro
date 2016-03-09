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
    smtpclient.cpp \
    mimemessage.cpp \
    mimepart.cpp \
    mimecontentformatter.cpp \
    mimemultipart.cpp \
    mimetext.cpp \
    emailaddress.cpp \
    quotedprintable.cpp

HEADERS  += mainwindow.h \
    smtpclient.h \
    smtpmime.h \
    mimemessage.h \
    mimepart.h \
    mimecontentformatter.h \
    mimemultipart.h \
    mimetext.h \
    emailaddress.h \
    qoutedprintable.h

FORMS    += mainwindow.ui
