#-------------------------------------------------
#
# Project created by QtCreator 2015-11-24T09:18:00
#
#-------------------------------------------------

QT       += core gui \
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Agricool
TEMPLATE = app

SOURCES += src/main.cpp \
    src/ui/bannerwidget.cpp \
    src/ui/mainwindow.cpp \
    src/service/bddService.cpp

HEADERS  += src/ui/bannerwidget.h \
    src/ui/mainwindow.h \
    src/service/bddService.h

RESOURCES += \
    resources.qrc
