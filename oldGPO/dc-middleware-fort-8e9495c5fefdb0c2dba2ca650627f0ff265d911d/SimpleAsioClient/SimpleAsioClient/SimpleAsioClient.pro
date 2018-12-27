TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lboost_system \
        -pthread

QMAKE_LFLAGS += -static

SOURCES += main.cpp
