#-------------------------------------------------
#
# Project created by QtCreator 2021-08-24T09:44:35
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 82-ThreadLifeCycle
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    MyThread.cpp \
    SyncThread.cpp \
    AsyncThread.cpp

HEADERS += \
    MyThread.h \
    SyncThread.h \
    AsyncThread.h
