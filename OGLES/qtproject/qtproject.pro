#-------------------------------------------------
#
# Project created by QtCreator 2018-09-09T15:47:38
#
#-------------------------------------------------

QT       += core gui opengl
LIBS     += -lopengl32 -glu32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtproject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h
