TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++23 -fmodules-ts #-fcoroutines #-xc++-system-header iostream#-fmodule-header

SOURCES += \
        Headers/CompnentH.cpp \
        ComponentI.cpp \
        Headers/ComponentsManagerH.cpp \
        ComponentsManagerI.cpp \
        Headers/EntitiesManagerH.cpp \
        Headers/SystemManagerH.cpp \
        Headers/SystemH.cpp \
        Headers/ECSManagerH.cpp \
        main.cpp
