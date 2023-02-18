###############
# QtImGUI.pri
###############

QT += core gui widgets opengl openglwidgets

message('Print Working Directory')
message($$PWD)

##########################
# imgui

isEmpty(IMGUI_ROOT) {
    IMGUI_ROOT = $$PWD/../imgui
}

INCLUDEPATH += \
$${IMGUI_ROOT}

SOURCES += \
$${IMGUI_ROOT}/imgui_draw.cpp \
$${IMGUI_ROOT}/imgui.cpp \
$${IMGUI_ROOT}/imgui_demo.cpp \
$${IMGUI_ROOT}/imgui_widgets.cpp

##########################
# Qimgui

INCLUDEPATH += \
. \
$$PWD

HEADERS += \
$$PWD/ImGuiRenderer.h \
$$PWD/MainWindow.h \
$$PWD/NanumGothic.ttf.h \
$$PWD/QtImGui.h \
$$PWD/AbstractMainImGui.h

SOURCES += \
$$PWD/ImGuiRenderer.cpp \
$$PWD/MainWindow.cpp \
$$PWD/QtImGui.cpp \
$$PWD/AbstractMainImGui.cpp

##########################
