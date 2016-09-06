#-------------------------------------------------
#
# Project created by QtCreator 2016-08-27T08:45:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


LIBS += -LC:\mysql\lib -llibmysql

#LIBS += -lmysqlclient

TARGET = cdma
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindlg.cpp \
    scriptdlg.cpp \
    mymysql.cpp \
    insert_mscdlg.cpp \
    select_msgdlg.cpp

HEADERS  += mainwindow.h \
    logindlg.h \
    scriptdlg.h \
    mymysql.h \
    insert_mscdlg.h \
    select_msgdlg.h
