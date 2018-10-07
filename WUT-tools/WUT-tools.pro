#-------------------------------------------------
#
# Project created by QtCreator 2018-05-23T21:23:37
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WUT-tools
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += __QT_GUI__
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += CURL_STATICLIB

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    ../../src/HttpReq.cpp \
    ../../src/LoginReq.cpp \
    ../../src/ScoreTableReq.cpp \
    ../../src/TimeTableReq.cpp \
    loginwindow.cpp \
    table.cpp

HEADERS += \
    ../../src/HttpReq.h \
    ../../src/LoginReq.h \
    ../../src/ScoreTableReq.h \
    ../../src/TableReq.h \
    ../../src/TimeTableReq.h \
    loginwindow.h \
    table.h

FORMS += \
    loginwindow.ui

DISTFILES += \
    ../../makefile

unix:!macx: LIBS += -L$$PWD/../../libcurl/linux/lib/ -lcurl -lrt -lpthread -Wl,-Bdynamic


INCLUDEPATH += $$PWD/../../libcurl/linux/include
DEPENDPATH += $$PWD/../../libcurl/linux/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../libcurl/linux/lib/libcurl.a

unix:!macx: LIBS += -L$$PWD/../../libgumbo/linux/lib/ -lgumbo

INCLUDEPATH += $$PWD/../../libgumbo/linux/include
DEPENDPATH += $$PWD/../../libgumbo/linux/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../libgumbo/linux/lib/libgumbo.a

unix:!macx: LIBS += -L$$PWD/../../libgq/linux/lib/ -lgq

INCLUDEPATH += $$PWD/../../libgq/linux/include
DEPENDPATH += $$PWD/../../libgq/linux/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../libgq/linux/lib/libgq.a



win32: LIBS += -L$$PWD/../../libgq/mingw/lib/ -lgq

INCLUDEPATH += $$PWD/../../libgq/mingw/include
DEPENDPATH += $$PWD/../../libgq/mingw/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../libgq/mingw/lib/gq.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../libgq/mingw/lib/libgq.a

win32: LIBS += -L$$PWD/../../libgumbo/mingw/lib/ -lgumbo

INCLUDEPATH += $$PWD/../../libgumbo/mingw/include
DEPENDPATH += $$PWD/../../libgumbo/mingw/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../libgumbo/mingw/lib/gumbo.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../libgumbo/mingw/lib/libgumbo.a


win32: LIBS += -L$$PWD/../../libcurl/mingw/lib/ -lcurl -lwldap32 -lws2_32 -Wl,-Bstatic

INCLUDEPATH += $$PWD/../../libcurl/mingw/include
DEPENDPATH += $$PWD/../../libcurl/mingw/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../libcurl/mingw/lib/curl.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../libcurl/mingw/lib/libcurl.a
