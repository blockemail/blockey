#-------------------------------------------------
#
# Project created by QtCreator 2016-03-22T01:15:29
#
#-------------------------------------------------

QT       += core gui network
QT += webkitwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = blockey
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loginform.cpp \
    simpletextform.cpp \
    typepcikform.cpp \
    htmlform.cpp \
    highlighter.cpp

HEADERS  += mainwindow.h \
    loginform.h \
    simpletextform.h \
    typepickform.h \
    htmlform.h \
    highlighter.h

SOURCES += \
    src/emailaddress.cpp \
    src/mimeattachment.cpp \
    src/mimefile.cpp \
    src/mimehtml.cpp \
    src/mimeinlinefile.cpp \
    src/mimemessage.cpp \
    src/mimepart.cpp \
    src/mimetext.cpp \
    src/smtpclient.cpp \
    src/quotedprintable.cpp \
    src/mimemultipart.cpp \
    src/mimecontentformatter.cpp \

HEADERS  += \
    src/emailaddress.h \
    src/mimeattachment.h \
    src/mimefile.h \
    src/mimehtml.h \
    src/mimeinlinefile.h \
    src/mimemessage.h \
    src/mimepart.h \
    src/mimetext.h \
    src/smtpclient.h \
    src/SmtpMime \
    src/quotedprintable.h \
    src/mimemultipart.h \
    src/mimecontentformatter.h


FORMS    += mainwindow.ui \
    loginform.ui \
    simpletextform.ui \
    typepickform.ui \
    htmlform.ui
