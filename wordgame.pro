#-------------------------------------------------
#
# Project created by QtCreator 2019-04-17T10:57:05
#
#-------------------------------------------------

QT       += core gui
QT       += sql network

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
	chooselevelwidget.cpp \
        main.cpp \
        mainwindow.cpp \
	playerfailedwidget.cpp \
	playerfilterdialog.cpp \
	playergamingwidget.cpp \
	playerpassedwidget.cpp \
	playerreadywidget.cpp \
	questionerfilterdialog.cpp \
	questionergamingwidget.cpp \
	questionerreadywidget.cpp \
	questionerwindow.cpp \
	signinwidget.cpp \
	signupwidget.cpp \
	tcpmanager.cpp \
    user.cpp \
    player.cpp \
    questioner.cpp \
    playerwindow.cpp \
	userdbmanager.cpp \
	worddbmanager.cpp

HEADERS += \
	alluserwidget.h \
	chooselevelwidget.h \
        mainwindow.h \
	playerfailedwidget.h \
	playerfilterdialog.h \
	playergamingwidget.h \
	playerpassedwidget.h \
	playerreadywidget.h \
	questionerfilterdialog.h \
	questionergamingwidget.h \
	questionerreadywidget.h \
	questionerwindow.h \
	signinwidget.h \
	signupwidget.h \
	tcpmanager.h \
    user.h \
    player.h \
    questioner.h \
    playerwindow.h \
	userdbmanager.h \
	worddbmanager.h

FORMS += \
	alluserwidget.ui \
	chooselevelwidget.ui \
        mainwindow.ui \
	playerfailedwidget.ui \
	playerfilterdialog.ui \
	playergamingwidget.ui \
	playerpassedwidget.ui \
	playerreadywidget.ui \
	questionerfilterdialog.ui \
	questionergamingwidget.ui \
	questionerreadywidget.ui \
	questionerwindow.ui \
	signinwidget.ui \
    playerwindow.ui \
	signupwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
