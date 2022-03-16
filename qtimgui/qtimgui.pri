###############
# qtimgui.pri
###############

QT += core
QT += gui
QT += widgets
QT += openglwidgets
QT += opengl

message('Print Working Directory')
message($$PWD)

INCLUDEPATH += \
 $$PWD/imgui \
 $$PWD

HEADERS += \
 $$PWD/ImGuiRenderer.h \
 $$PWD/QtImGui.h

SOURCES += \
 $$PWD/ImGuiRenderer.cpp \
 $$PWD/QtImGui.cpp

SOURCES += \
 $$PWD/imgui/imgui_draw.cpp \
 $$PWD/imgui/imgui.cpp \
 $$PWD/imgui/imgui_demo.cpp \
 $$PWD/imgui/imgui_widgets.cpp
