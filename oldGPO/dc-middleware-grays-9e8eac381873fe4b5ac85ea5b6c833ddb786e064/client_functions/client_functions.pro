TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    ClientFunctions.cpp

HEADERS += \
    ClinetFucntions.h
LIBS += -lboost_system \
                     -pthread
