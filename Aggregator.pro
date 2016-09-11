#-------------------------------------------------
#
# Project created by QtCreator 2015-09-25T15:25:16
#
#-------------------------------------------------

QT       += core
QT       += network

QT       -= gui

TARGET = Aggregator
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    get_my_stuff/nodeinputadapter.cpp \
    get_my_stuff/mailadapter.cpp \
    get_my_stuff/elasticsearch.cpp \
    get_my_stuff/restrequest.cpp \
    mainwindow.cpp

HEADERS += \


unix|win32: LIBS += -lqjson

FORMS += \
    mainwindow.ui
