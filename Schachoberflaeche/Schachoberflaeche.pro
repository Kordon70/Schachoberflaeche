#-------------------------------------------------
#
# Project created by QtCreator 2013-10-14T13:27:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Schachoberflaeche
TEMPLATE = app


SOURCES += main.cpp\
    humanplayer.cpp \
    field.cpp \
    chessfield.cpp

HEADERS  += \
    humanplayer.h \
    field.h \
    chessfield.h

RESOURCES += \
    Schachfiguren.qrc
