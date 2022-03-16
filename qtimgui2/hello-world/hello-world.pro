# hello-world.pro
TARGET = hello-world
TEMPLATE = app
QT += core gui widgets # default module of QT

# Include pri & Set ImGUI direcotry
IMGUI_ROOT = $$PWD/../imgui-1.76
include(../QtImGUI/QtImGUI.pri)

# use boiler plate code
HEADERS += \
MainWindow.h \
MainImGui.h \
D2Coding-Ver1.3.2-20180524.ttf.h

SOURCES += \
MainWindow.cpp \
main.cpp \
MainImGui.cpp

RESOURCES += \
imgui.qrc


