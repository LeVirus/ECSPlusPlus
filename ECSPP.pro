TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++20 -fmodules-ts #-fcoroutines #-xc++-system-header iostream#-fmodule-header

SOURCES += \
        Headers/ECSManagerH.cpp \
        Headers/SystemManagerH.cpp \
        Headers/EntitiesManagerH.cpp \
        Headers/SystemH.cpp \
        ECSManagerI.cpp \
        EntitiesManagerI.cpp \
        SystemI.cpp \
        SystemManagerI.cpp \
        main.cpp
