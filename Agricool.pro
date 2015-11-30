#-------------------------------------------------
#
# Project created by QtCreator 2015-11-24T09:18:00
#
#-------------------------------------------------

QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = Agricool
TEMPLATE = app
CONFIG += c++11

SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/bannerwidget.cpp \
    src/plot.cpp \
    src/culturecycle.cpp \
    src/operation.cpp \
    src/event.cpp \
    src/harvest.cpp \
    src/tool.cpp \
    src/product.cpp \
    src/toolusage.cpp \
    src/productusage.cpp

HEADERS  += src/mainwindow.h \
    src/bannerwidget.h \
    src/plot.h \
    src/culturecycle.h \
    src/operation.h \
    src/event.h \
    src/harvest.h \
    src/tool.h \
    src/product.h \
    src/toolusage.h \
    src/productusage.h \
    src/enums.h

RESOURCES += \
    resources.qrc
