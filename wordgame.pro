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
	playerreadywidget.cpp \
	questionerfilterdialog.cpp \
	questionergamingwidget.cpp \
	questionerreadywidget.cpp \
	questionerwindow.cpp \
	signinwidget.cpp \
	signupwidget.cpp \
    user.cpp \
    player.cpp \
    questioner.cpp \
    playerwindow.cpp \
	userdbmanager.cpp \
	worddbmanager.cpp

HEADERS += \
	alluserwidget.h \
        mainwindow.h \
	playerfilterdialog.h \
	playergamingwidget.h \
	playerreadywidget.h \
	questionerfilterdialog.h \
	questionergamingwidget.h \
	questionerreadywidget.h \
	questionerwindow.h \
	signinwidget.h \
	signupwidget.h \
    user.h \
    player.h \
    questioner.h \
    playerwindow.h \
	userdbmanager.h \
	worddbmanager.h

FORMS += \
	alluserwidget.ui \
        mainwindow.ui \
	playerfilterdialog.ui \
	playergamingwidget.ui \
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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/release/ -lcomponents
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/debug/ -lcomponents
else:unix: LIBS += -L$$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/ -lcomponents

INCLUDEPATH += $$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components
DEPENDPATH += $$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/release/libcomponents.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/debug/libcomponents.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/release/components.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/debug/components.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/libcomponents.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/ -lcomponents
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/ -lcomponentsd
else:unix: LIBS += -L$$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/ -lcomponents

INCLUDEPATH += $$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components
DEPENDPATH += $$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/libcomponents.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/libcomponentsd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/components.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/componentsd.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../build-qt-material-widgets-Desktop_Qt_5_12_2_clang_64bit-Debug/components/libcomponents.a
