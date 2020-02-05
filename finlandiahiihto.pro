TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

QT += network

SOURCES += main.cpp \
    network.cpp \
    parser.cpp

HEADERS += \
    network.h \
    parser.h
