TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lboost_system
LIBS += -pthread
LIBS += -lssl
LIBS += -lcrypto

SOURCES += \
        main.cpp
