TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lenet -L/usr/local/lib -lprotobuf -pthread -lpthread

SOURCES += main.cpp \
    test.pb.cc

HEADERS += \
    test.pb.h

