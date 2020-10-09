include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

CONFIG += c++17 \
        debug \
        warn_on

DEFINES += TESTPROJ

HEADERS +=     tst_link.h \
        logger.h \
        ../src/entity/Link.h \
        ../src/entity/Folder.h

SOURCES += main.cpp \
        ../src/entity/Link.cpp \
        ../src/entity/Folder.cpp \
