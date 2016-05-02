#-------------------------------------------------
#
# Project created by QtCreator 2016-05-01T21:06:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pd2-Taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    demo.cpp \
    note.cpp \
    beatmap.cpp

HEADERS  += mainwindow.h \
    demo.h \
    note.h \
    beatmap.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
