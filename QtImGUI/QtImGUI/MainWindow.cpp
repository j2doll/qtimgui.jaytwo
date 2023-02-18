// MainWindow.cpp

#include "MainWindow.h"

MainWindow::MainWindow()
#ifdef USE_OPEN_GL_WINDOW
        : QOpenGLWindow()
#else
        : QOpenGLWidget()
#endif
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::initializeGL()
{
    // TODO: define your configuration
    QString strWindowTitle = ""; // main window title. such as "QtImGui widget example";
    clear_color = ImColor(114, 144, 154); // background color

#ifdef USE_OPEN_GL_WINDOW
    setTitle(strWindowTitle);
#else
    setWindowTitle(strWindowTitle);
#endif

    initializeOpenGLFunctions();
    QtImGui::initialize(this);
}

void MainWindow::paintGL()
{
    QtImGui::newFrame();

    // Do render before ImGui UI is rendered
    glViewport( 0, 0, width(), height() );
    glClearColor( clear_color.x, clear_color.y, clear_color.z, clear_color.w );
    glClear( GL_COLOR_BUFFER_BIT );

    renderImGui();

    // TODO: Define your own redering of Qt/OpenGL

    ImGui::Render();
}

void MainWindow::renderImGui()
{
    if ( abstractMainImGui != nullptr )
    {
        abstractMainImGui->renderImGui();
    }
}



