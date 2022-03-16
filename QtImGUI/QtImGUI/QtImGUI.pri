###############
# QtImGUI.pri
###############

QT += core gui widgets opengl openglwidgets

message('Print Working Directory')
message($$PWD)

isEmpty(IMGUI_ROOT) {
    IMGUI_ROOT = $$PWD/../imgui
}

INCLUDEPATH += \
. \
$$PWD

HEADERS += \
$$PWD/ImGuiRenderer.h \
$$PWD/QtImGui.h

SOURCES += \
$$PWD/ImGuiRenderer.cpp \
$$PWD/QtImGui.cpp

INCLUDEPATH += \
$${IMGUI_ROOT}

SOURCES += \
$${IMGUI_ROOT}/imgui_draw.cpp \
$${IMGUI_ROOT}/imgui.cpp \
$${IMGUI_ROOT}/imgui_demo.cpp \
$${IMGUI_ROOT}/imgui_widgets.cpp
