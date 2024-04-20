TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++23 -fmodules-ts -fcoroutines #-xc++-system-header iostream#-fmodule-header
INCLUDEPATH += Headers

SOURCES += \
        ComponentsManager.cpp \
        EntitiesManager.cpp \
        System.cpp \
        SystemManager.cpp \
        ECSManager.cpp \
        main.cpp

HEADERS += \
        Headers/Component.hpp \
        Headers/ComponentsManager.hpp \
        Headers/ECSManager.hpp \
        Headers/EntitiesManager.hpp \
        Headers/System.hpp \
        Headers/SystemManager.hpp \
