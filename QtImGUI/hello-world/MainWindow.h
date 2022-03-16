// MainWindow.h

// boiler-plate code {{
#ifndef MainWindow_h
#define MainWindow_h

#include <QtGlobal>
#include <QTimer>

#include <QOpenGLWidget>
#include <QOpenGLWindow>
#include <QOpenGLExtraFunctions>
#include <QSurfaceFormat>

#include <QtImGui.h>
#include <imgui.h>

#include "MainImGui.h"

#define USE_OPEN_GL_WINDOW

class MainWindow
#ifdef USE_OPEN_GL_WINDOW
        : public QOpenGLWindow,
#else
        : public QOpenGLWidget,
#endif
        protected QOpenGLExtraFunctions
{
public:
    virtual ~MainWindow();

    void initializeGL() override;
    void paintGL() override;

    virtual void renderImGui();

protected:
    ImVec4 clear_color;
    MainImGui* mainImGui;

};
// boiler-plate code }}

#endif
