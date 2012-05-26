#-------------------------------------------------
#
# Project created by QtCreator 2011-09-21T19:12:25
#
#-------------------------------------------------

# Add more folders to ship with the application, here
folder_01.source = qml/qml/qml/qml
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian:TARGET.UID3 = 0xE1518112

###################
QT       += core gui sql

TARGET = laba1
TEMPLATE = app

SOURCES += main.cpp\
    delegat.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    conn.h \
    delegat.h

RESOURCES   += main.qrc
FORMS    += mainwindow.ui
