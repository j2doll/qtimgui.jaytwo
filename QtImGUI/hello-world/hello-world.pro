# hello-world.pro
TARGET = hello-world
TEMPLATE = app
QT += core gui widgets # default module of QT

# Include pri & Set ImGUI direcotry
IMGUI_ROOT = $$PWD/../imgui-1.76
include(../QtImGUI/QtImGUI.pri)

# use boiler plate code

HEADERS += \
MainImGui.h

SOURCES += \
main.cpp \
MainImGui.cpp



