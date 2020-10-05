#-------------------------------------------------
#
# Project created by QtCreator 2020-07-13T21:58:32
#
#-------------------------------------------------

QT       += core gui sql #widgets

TEMPLATE = app
TARGET = internetbook


unix {
    INCLUDEPATH += /usr/include/boost_1_72_0
    LIBS += -L/usr/include/boost_1_72_0 -L/usr/include/boost_1_72_0/stage/lib -lpthread -lboost_thread -lboost_system -lboost_log_setup -lboost_log
}

win32 {

}

QMAKE_LFLAGS += -lboost_thread -lboost_system -lboost_log_setup -lboost_log -lboost_filesystem -lboost_regex
QMAKE_CXXFLAGS += -Wall

CONFIG += c++17 \
        debug \
        warn_on

DEFINES += BOOST_LOG_DYN_LINK

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES     = ./icons/icons.qrc

SOURCES += \
        src/main.cpp \
        src/config/config.cpp \
        src/config/logger.cpp \
        src/entity/Link.cpp \
        src/entity/Folder.cpp \
        src/repository/Repository.cpp

HEADERS += \
        src/config/config.h \
        src/config/logger.h \
        src/entity/Link.h \
        src/entity/Folder.h \
        src/repository/Repository.h
