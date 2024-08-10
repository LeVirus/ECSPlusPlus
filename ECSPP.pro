TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++23  -fcoroutines #-fmodules-ts -xc++-system-header iostream#-fmodule-header
INCLUDEPATH += Headers

SOURCES += \
        ComponentsManager.cpp \
        main.cpp

HEADERS += \
        Headers/Component.hpp \
        Headers/ComponentsManager.hpp \
        Headers/ECSManager.hpp \
        Headers/EntitiesManager.hpp \
        Headers/System.hpp \
        Headers/SystemManager.hpp \
    Headers/TemplateDeclaration.hpp \
    Headers/TestCompMan.hpp \
    Headers/TestSystem.hpp
