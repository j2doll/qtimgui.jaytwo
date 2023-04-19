# $${\color{blue}QtImGUI.jaytwo }$$

- Based on QtImGui :+1: https://github.com/seanchas116/qtimgui 
   - QtImGui is under MIT license.

- Application with ImGUI and OpenGL based on Qt :kr: 아이엠지유와이와 오픈지엘의 큐트 기반인 어플리케이션
- Boiler-plate example :kr: 보일러 플레이트 예제
- Template project :kr: 템플릿 프로젝트

## How to make an example :kr: 예제 만드는 법

:one: create ```hello-world.pro```

```qmake
include(../QtImGUI/QtImGUI.pri)

HEADERS += \
MainImGui.h

SOURCES += \
main.cpp \
MainImGui.cpp
```

:two: create ```main.cpp```

```cpp
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
```

:three: create ```MainImGui.h```

```h
class MainImGui : public AbstractMainImGui
{
public:
    MainImGui();
    virtual ~MainImGui();

    // TODO: write how to render
    void renderImGui();

protected:
    ImVec4 clear_color;

// boiler-plate code }}

    bool show_test_window;
    bool show_another_window;

// boiler-plate code {{
};
#endif
// boiler-plate code }}
```

:four: create ```MainImGui.cpp```

```cpp
MainImGui::MainImGui()
    : AbstractMainImGui()
{
    clear_color = ImColor(114, 144, 154);

    show_test_window = true;
    show_another_window = false;
}

//////////////////////////

MainImGui::~MainImGui()
{
}

//////////////////////////

void MainImGui::renderImGui()
{
    // TODO: Define your oen redering of ImGUI

    using namespace ImGui;

    // 1. Show a simple window
    // Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets appears in a window automatically called "Debug"
    {
        Text("Hello, world! 한글"); // check Korean UTF-8 !!

        static float f = 0.0f;
        SliderFloat("float", &f, 0.0f, 1.0f);

        ColorEdit3("clear color", (float*)&clear_color);

        if (Button("Test Window"))
            show_test_window ^= 1;

        if (Button("Another Window"))
            show_another_window ^= 1;

        Text("Application average %.3f ms/frame (%.1f FPS)",
             1000.0f / GetIO().Framerate, GetIO().Framerate);
    }

    // 2. Show another simple window, this time using an explicit Begin/End pair
    if (show_another_window)
    {
        SetNextWindowSize(ImVec2(400,100), ImGuiCond_FirstUseEver);
        Begin("Another Window", &show_another_window);

            Text("Hello 한글 漢字 ...");

            char buf[4096];
            InputText("Input Text", buf, (4096-1)); // IME does not works in imgui 1.76

        End();
    }

    // 3. Show the ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
    if (show_test_window)
    {
        SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
        ShowDemoWindow();
    }

}
```

## :kr: 기타

- :kr: 한글 입력이 안되는 현상 있음 (Qt,ImGUI)


 
