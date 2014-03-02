#-------------------------------------------------
#
# Project created by QtCreator 2013-10-14T13:27:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Schachoberflaeche
TEMPLATE = app


SOURCES += Schachoberflaeche/main.cpp\
    Schachoberflaeche/humanplayer.cpp \
    Schachoberflaeche/field.cpp \
    Schachoberflaeche/chessfield.cpp \
    Schachoberflaeche/newgamebutton.cpp

HEADERS  += \
    Schachoberflaeche/humanplayer.h \
    Schachoberflaeche/field.h \
    Schachoberflaeche/chessfield.h \
    Schachoberflaeche/newgamebutton.h

RESOURCES += \
    Schachoberflaeche/Schachfiguren.qrc OTHER_FILES += Schachoberflaeche\images\icon.ico RC_FILE = Schachoberflaeche.rc
