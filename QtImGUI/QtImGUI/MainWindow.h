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

#include <imgui.h>

#include "QtImGui.h"
#include "AbstractMainImGui.h"

#define USE_OPEN_GL_WINDOW
// #define NOT_USE_OPEN_GL_WINDOW

class MainWindow
#ifdef USE_OPEN_GL_WINDOW
        : public QOpenGLWindow,
#else
        : public QOpenGLWidget,
#endif
        protected QOpenGLExtraFunctions
{
public:
    MainWindow();
    virtual ~MainWindow();

    void initializeGL() override;
    void paintGL() override;

    virtual void renderImGui();

    AbstractMainImGui* abstractMainImGui;

    ImVec4 clear_color;

protected:


};
// boiler-plate code }}

#endif
