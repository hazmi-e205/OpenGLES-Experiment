#-------------------------------------------------
#
# Project created by QtCreator 2018-09-09T15:47:38
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtproject
TEMPLATE = app


SOURCES += main.cpp\
    ../Sources/Mystic.cpp \
    ../Sources/Implement.cpp \
    ../Sources/Model.cpp \
    ../Sources/OGLNative.cpp \
    ../Sources/OGLRender.cpp \
    ../Sources/OGLShader.cpp \
    ../Sources/Speak.cpp \
    ../Sources/Vertex.cpp \
    QOGLWidget.cpp \
    OGLAdapter.cpp

HEADERS  += \
    ../Sources/Mystic.h \
    ../Sources/Implement.h \
    ../Sources/Model.h \
    ../Sources/OGLNative.h \
    ../Sources/OGLRender.h \
    ../Sources/OGLShader.h \
    ../Sources/Speak.h \
    ../Sources/Vertex.h \
    PlatformDefine.h \
    QOGLWidget.h \
    OGLAdapter.h

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/../Sources
