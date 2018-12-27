TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \

HEADERS += \
    ../../../lib/inc/FileReceiver.h \
    ../../../lib/inc/description_for_thrift_types.h \
    ../../../lib/inc/description_for_thrift_constants.h

INCLUDEPATH += /home/fort/Education/NIR/Practice/thriftTest/gen-cpp/

LIBS += -lthrift \
    ../../../lib/libthriftDegenerated.a
