#-------------------------------------------------
#
# Project created by QtCreator 2019-04-17T10:57:05
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wordgame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
	alluserwidget.cpp \
        main.cpp \
        mainwindow.cpp \
	playerfilterdialog.cpp \
	playergamingwidget.cpp \
	questionerfilterdialog.cpp \
	questionergamingwidget.cpp \
	questionerwindow.cpp \
    user.cpp \
    player.cpp \
    questioner.cpp \
    signupdialog.cpp \
    playerwindow.cpp \
    userdb.cpp \
	worddb.cpp

HEADERS += \
	alluserwidget.h \
        mainwindow.h \
	playerfilterdialog.h \
	playergamingwidget.h \
	questionerfilterdialog.h \
	questionergamingwidget.h \
	questionerwindow.h \
    user.h \
    player.h \
    questioner.h \
    signupdialog.h \
    playerwindow.h \
    userdb.h \
	worddb.h

FORMS += \
	alluserwidget.ui \
        mainwindow.ui \
	playerfilterdialog.ui \
	playergamingwidget.ui \
	questionerfilterdialog.ui \
	questionergamingwidget.ui \
	questionerwindow.ui \
    signupdialog.ui \
    playerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
