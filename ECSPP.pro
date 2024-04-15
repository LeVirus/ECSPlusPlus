TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++20 -fmodules-ts -fcoroutines #-xc++-system-header iostream#-fmodule-header
INCLUDEPATH += Headers

SOURCES += \
        ComponentsManager.cpp \
        ECSManager.cpp \
        EntitiesManager.cpp \
        Headers/Component.hpp \
        Headers/ComponentsManager.hpp \
        Headers/ECSManager.hpp \
        Headers/EntitiesManager.hpp \
        Headers/System.hpp \
        Headers/SystemManager.hpp \
        System.cpp \
        SystemManager.cpp \
        main.cpp
