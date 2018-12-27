TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    task_executor.cpp

INCLUDEPATH += ../../thrift/gen-cpp \
               ../../Server/SDCITA_Server/inc

HEADERS += \
    task_executor.h

LIBS += -lthrift \
    ../../lib/libthriftDegenerated.a \
    -lboost_system \
    -lboost_filesystem

