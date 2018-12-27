TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../gen-cpp/FileReceiver.cpp \
    ../gen-cpp/FileReceiver_server.skeleton.cpp

HEADERS += \
    ../gen-cpp/description_for_thrift_types.h


LIBS += -lthrift
