#-------------------------------------------------
#
# Project created by QtCreator 2020-03-21T15:13:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myobject.cpp \
    myobject_test.cpp \
    my_moc_objectb.cpp \
    my_moc_objecta.cpp

HEADERS  += mainwindow.h \
    myobject.h \
    objecta.h \
    objectb.h

FORMS    += mainwindow.ui
