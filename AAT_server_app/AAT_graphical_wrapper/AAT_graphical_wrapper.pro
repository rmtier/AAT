#-------------------------------------------------
#
# Project created by QtCreator 2016-09-14T19:18:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AAT_graphical_wrapper
TEMPLATE = app

#link AAT_core shared library
LIBS += -L/home/rami/AAT/AAT_server_app/dyn_lib_aligment_core/_build -lAAT_core


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h\
            ../dyn_lib_aligment_core/include/aat.h

FORMS    += mainwindow.ui
