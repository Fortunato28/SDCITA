TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../../thrift/gen-cpp \
               inc \


SOURCES += \
        src/main.cpp \
    src/middleware.cpp \
    src/task_handler.cpp \
    src/server_part_handler.cpp

HEADERS += \
    inc/thrift_generated.h \
    inc/middleware.h \
    inc/task_handler.h \
    inc/server_part_handler.h

LIBS += -lthrift \
        -lthriftnb \
        -levent \
    ../../lib/libthriftDegenerated.a \
    -lboost_system \
    -lboost_filesystem
