#-------------------------------------------------
#
# Project created by QtCreator 2019-03-30T17:16:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = netscan
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scanner.cpp \
    scannerfactory.cpp

HEADERS  += mainwindow.h \
    scanner.h \
    scannerfactory.h


unix {
    SOURCES += linuxicmpscanner.cpp
    HEADERS += linuxicmpscanner.h
}
win32 {
    SOURCES += windowsicmpscanner.cpp
    HEADERS += windowsicmpscanner.h
}

FORMS    += mainwindow.ui
