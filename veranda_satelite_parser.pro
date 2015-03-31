#-------------------------------------------------
#
# Project created by QtCreator 2014-09-29T14:37:18
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT       += sql
QT       += network

TARGET = veranda_satelite_parser
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

OBJECTS_DIR = compile
MOC_DIR = compile

SOURCES += main.cpp \
    model/modelmodem.cpp \
    util/util_skyw.cpp \
    view/skywavenetwork.cpp \
    util/parsing_fuction.cpp \
    model/db_config.cpp \
    model/get_db.cpp \
    controller/worker.cpp

HEADERS += \
    model/modelmodem.h \
    util/util_skyw.h \
    util/initdb.h \
    view/skywavenetwork.h \
    model/struct_xml.h \
    util/parsing_fuction.h \
    model/db_config.h \
    model/get_db.h \
    controller/worker.h
