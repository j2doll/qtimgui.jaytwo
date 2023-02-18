###############
# QtImGUI.pri
###############

QT += core gui widgets opengl openglwidgets

message('Print Working Directory')
message($$PWD)

##########################
# imgui

isEmpty(IMGUI_ROOT) {
    IMGUI_ROOT = $$PWD/../imgui-1.76
}

INCLUDEPATH += \
$${IMGUI_ROOT}

HEADERS += \
$${IMGUI_ROOT}/imconfig.h \
$${IMGUI_ROOT}/imgui.h \
$${IMGUI_ROOT}/imgui_internal.h \
$${IMGUI_ROOT}/imstb_rectpack.h \
$${IMGUI_ROOT}/imstb_textedit.h \
$${IMGUI_ROOT}/imstb_truetype.h

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
