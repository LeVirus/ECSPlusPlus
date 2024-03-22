TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++23 -fmodules-ts #-fcoroutines #-xc++-system-header iostream#-fmodule-header

SOURCES += \
        Headers/ECSManagerH.cpp \
        Headers/EntitiesManagerH.cpp \
        Headers/SystemH.cpp \
        ECSManagerI.cpp \
        EntitiesManagerI.cpp \
        Headers/SystemManagerH.cpp \
        SystemI.cpp \
        SystemManagerI.cpp \
        main.cpp
