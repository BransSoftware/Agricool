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

SOURCES += src/core/culturecycle.cpp \
    src/core/event.cpp \
    src/core/harvest.cpp \
    src/core/main.cpp \
    src/core/operation.cpp \
    src/core/plot.cpp \
    src/core/product.cpp \
    src/core/productusage.cpp \
    src/core/tool.cpp \
    src/core/toolusage.cpp \
    src/dao/plotdao.cpp \
    src/dao/culturecycledao.cpp \
    src/ui/bannerwidget.cpp \
    src/ui/mainwindow.cpp \
    src/service/bddService.cpp \
    src/dao/eventdao.cpp \
    src/dao/harvestdao.cpp \
    src/dao/operationdao.cpp \
    src/dao/productdao.cpp \
    src/dao/productusagedao.cpp \
    src/dao/tooldao.cpp \
    src/dao/toolusagedao.cpp

HEADERS  += src/core/culturecycle.h \
    src/core/enums.h \
    src/core/event.h \
    src/core/harvest.h \
    src/core/operation.h \
    src/core/plot.h \
    src/core/product.h \
    src/core/productusage.h \
    src/core/tool.h \
    src/core/toolusage.h \
    src/dao/plotdao.h \
    src/dao/culturecycledao.h \
    src/service/bddService.h \
    src/ui/bannerwidget.h \
    src/ui/mainwindow.h \
    src/dao/daobase.h \
    src/dao/eventdao.h \
    src/dao/harvestdao.h \
    src/dao/operationdao.h \
    src/dao/productdao.h \
    src/dao/productusagedao.h \
    src/dao/tooldao.h \
    src/dao/toolusagedao.h


RESOURCES += \
    resources.qrc
