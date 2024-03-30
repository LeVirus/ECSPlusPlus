TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++23 -fmodules-ts #-fcoroutines #-xc++-system-header iostream#-fmodule-header

SOURCES += \
        ComponentI.cpp \
        ComponentsManagerI.cpp \
        Headers/CompnentH.cpp \
        Headers/ComponentsManagerH.cpp \
        Headers/EntitiesManagerH.cpp \
        Headers/SystemH.cpp \
        Headers/SystemManagerH.cpp \
        Headers/ECSManagerH.cpp \
        ECSManagerI.cpp \
        EntitiesManagerI.cpp \
        SystemI.cpp \
        SystemManagerI.cpp \
        main.cpp
