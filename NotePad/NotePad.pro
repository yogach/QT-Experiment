#-------------------------------------------------
#
# Project created by QtCreator 2021-04-26T14:46:06
#
#-------------------------------------------------

QT       += core gui

TARGET = NotePad
TEMPLATE = app


SOURCES += main.cpp\
    MainWindowSlot.cpp \
    MainWindowUI.cpp \
    FindDialog.cpp \
    ReplaceDialog.cpp \
    AboutDialog.cpp \
    AppConfig.cpp

HEADERS  += MainWindow.h \
    FindDialog.h \
    ReplaceDialog.h \
    AboutDialog.h \
    AppConfig.h

RESOURCES += \
    Res.qrc
