#-------------------------------------------------
#
# Project created by QtCreator 2013-12-16T14:53:36
#
#-------------------------------------------------

QT       += core

QT       -= gui

QMAKE_CXX = g++

TARGET = RoleDoCavalo
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    tabuleiro.cpp \
    cavalo.cpp \
    subject.cpp \
    observer.cpp \
    player.cpp \
    caminho.cpp \
    cronometro.cpp \
    megasena.cpp

HEADERS += \
    tabuleiro.h \
    cavalo.h \
    asubject.h \
    aobserver.h \
    subject.h \
    observer.h \
    player.h \
    apecaxadrez.h \
    caminho.h \
    cronometro.h \
    megasena.h
