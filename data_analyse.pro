#-------------------------------------------------
#
# Project created by QtCreator 2016-07-17T21:14:02
#
#-------------------------------------------------

QT       += core gui network serialport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = data_analyse
TEMPLATE = app


SOURCES += main.cpp\
        mwidget.cpp \
    config.cpp \
    updatescreenthread.cpp \
    databaseserver.cpp \
    dialog.cpp \
    databasesearch.cpp

HEADERS  += mwidget.h \
    config.h \
    updatescreenthread.h \
    databaseserver.h \
    dialog.h \
    databasesearch.h

FORMS    += mwidget.ui \
    dialog.ui

RESOURCES += \
    resource.qrc

DISTFILES +=
