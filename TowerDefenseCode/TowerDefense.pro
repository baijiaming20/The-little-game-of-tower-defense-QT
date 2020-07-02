#-------------------------------------------------
#
# Project created by QtCreator 2020-06-11T22:04:26
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerDefense
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        startwindow.cpp \
    gamewindow.cpp \
    selectionframe.cpp \
    towerbaseclass.cpp \
    defensetower_1.cpp \
    defensetower_2.cpp \
    defensetower_3.cpp \
    defensetower_4.cpp \
    enemybaseclass.cpp \
    enemy_1.cpp \
    enemy_2.cpp \
    enemy_3.cpp \
    enemy_4.cpp

HEADERS += \
        startwindow.h \
    gamewindow.h \
    multifilestructure.h \
    selectionframe.h \
    towerbaseclass.h \
    defensetower_1.h \
    defensetower_2.h \
    defensetower_3.h \
    defensetower_4.h \
    enemybaseclass.h \
    enemy_1.h \
    generatepath.h \
    enemy_2.h \
    enemy_3.h \
    enemy_4.h

FORMS += \
        startwindow.ui
