#-------------------------------------------------
#
# Project created by QtCreator 2015-11-11T15:28:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArtemisKeithleyInterface
TEMPLATE = app


SOURCES += main.cpp\
        keithleywindow.cpp \
    keithleydevice.cpp

HEADERS  += keithleywindow.h \
    keithleydevice.h

FORMS    += keithleywindow.ui

LIBS += -L$$PWD/. -lni4882
INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
