// main.cpp
// boiler-plate code {{

#include <QtGlobal>
#include <QApplication>
#include <QTimer>

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QSurfaceFormat>

#include <QtImGui.h>
#include <imgui.h>

#include "MainWindow.h"
#include "MainImGui.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Use OpenGL 3 Core Profile, when available
    QSurfaceFormat glFormat;
    if (QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL)
    {
        glFormat.setVersion(3, 3);
        glFormat.setProfile(QSurfaceFormat::CoreProfile);
    }
    QSurfaceFormat::setDefaultFormat(glFormat);

    // [1] TODO : create your own main imgui class
    float fontSize = 24.0f; // font size
    MainImGui mainImGui(fontSize);

    // [2] TODO : create main windows. and combine them.
    MainWindow mainWindow;
    mainWindow.clear_color = ImColor(114, 144, 154); // background color
    mainWindow.abstractMainImGui = &mainImGui;
    mainWindow.showMaximized();

    // Update at 60 fps
    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &mainWindow, SLOT(update()));
    int msec = 16;
    timer.start(msec); // 1000 msec / 16 = 62.5 fps

    int ret = app.exec();
    return ret;
}

// boiler-plate code }}
