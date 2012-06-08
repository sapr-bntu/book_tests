#-------------------------------------------------
#
# Project created by QtCreator 2012-05-25T10:47:08
#
#-------------------------------------------------

QT       += sql testlib

TARGET = tst_test_booktest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_test_booktest.cpp \
    ../laba1/mainwindow.cpp \
    ../laba1/delegat.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../laba1/ui_mainwindow.h \
    ../laba1/mainwindow.h \
    ../laba1/delegat.h \
    ../laba1/conn.h
