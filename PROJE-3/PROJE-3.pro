#-------------------------------------------------
#
# Project created by QtCreator 2017-05-18T11:57:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PROJE-3
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


SOURCES += main.cpp\
        mainwindow.cpp \
    Background.cpp \
    Comment.cpp \
    Database.cpp \
    Interface.cpp \
    Movie.cpp \
    Rating.cpp \
    Source.cpp \
    Studio.cpp \
    User.cpp \
    modelmovie.cpp \
    modelcomment.cpp \
    modelrating.cpp

HEADERS  += mainwindow.h \
    Background.h \
    Comment.h \
    CommonData.h \
    Database.h \
    Interface.h \
    Movie.h \
    Rating.h \
    Studio.h \
    User.h \
    modelmovie.h \
    modelcomment.h \
    modelcomment.h \
    modelrating.h

FORMS    += mainwindow.ui

DISTFILES += \
    db/comment.txt \
    db/movie.txt \
    db/rating.txt \
    db/studio.txt \
    db/user.txt
