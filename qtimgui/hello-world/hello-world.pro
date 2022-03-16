# hello-world.pro

TARGET = hello-world-widget

TEMPLATE = app

# default module of QT
QT += core gui widgets

# include pri
include(../qtimgui.pri)

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


