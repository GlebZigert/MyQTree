#-------------------------------------------------
#
# Project created by QtCreator 2020-08-24T08:50:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyTree
TEMPLATE = app


SOURCES += main.cpp\
    id.cpp \
        mainwindow.cpp \
    mynumber.cpp \
    treeitem.cpp \
    treemodel.cpp \
    mytreeview.cpp \
    myitem.cpp \
    mymodel.cpp \
    newmodel.cpp \
    settingutils.cpp \
    map.cpp

HEADERS  += mainwindow.h \
    id.h \
    mynumber.h \
    treeitem.h \
    treemodel.h \
    mytreeview.h \
    myitem.h \
    mymodel.h \
    newmodel.h \
    settingutils.h \
    map.h

FORMS    += mainwindow.ui \
    map.ui

RESOURCES += \
    resource.qrc
