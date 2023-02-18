# hello-world.pro

TARGET = hello-world
TEMPLATE = app
QT += core gui widgets # default module of QT

#####################################
# use boiler plate code
# Include pri & Set ImGUI direcotry
include(../QtImGUI/QtImGUI.pri)

HEADERS += \
MainImGui.h

SOURCES += \
main.cpp \
MainImGui.cpp



