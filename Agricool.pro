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
    src/ui/bannerwidget.cpp \
    src/ui/mainwindow.cpp \
    src/service/bddService.cpp \
    src/model/culturecycle.cpp \
    src/model/event.cpp \
    src/model/harvest.cpp \
    src/model/operation.cpp \
    src/model/plot.cpp \
    src/model/plotmodel.cpp \
    src/model/product.cpp \
    src/model/productusage.cpp \
    src/model/tool.cpp \
    src/model/toolusage.cpp

HEADERS  += src/model/culturecycle.h \
    src/model/enums.h \
    src/model/event.h \
    src/model/harvest.h \
    src/model/operation.h \
    src/model/plot.h \
    src/model/plotmodel.h \
    src/model/product.h \
    src/model/productusage.h \
    src/model/tool.h \
    src/model/toolusage.h \
    src/service/bddService.h \
    src/ui/bannerwidget.h \
    src/ui/mainwindow.h

RESOURCES += \
    resources.qrc
