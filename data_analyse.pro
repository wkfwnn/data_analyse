#-------------------------------------------------
#
# Project created by QtCreator 2016-07-17T21:14:02
#
#-------------------------------------------------

QT       += core gui network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = data_analyse
TEMPLATE = app


SOURCES += main.cpp\
        mwidget.cpp \
    dll.cpp \
    config.cpp \
    updateledthread.cpp

HEADERS  += mwidget.h \
    dll.h \
    config.h \
    updateledthread.h

FORMS    += mwidget.ui

RESOURCES += \
    resource.qrc

DISTFILES +=
