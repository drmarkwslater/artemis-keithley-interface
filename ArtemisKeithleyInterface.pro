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

INCLUDEPATH += "C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include"

LIBS += -L"C:\Users\bhamadmin\Documents\build-ArtemisKeithleyInterface-Desktop_Qt_5_4_2_MinGW_32bit2-Debug" -lni4882

