// MainImGui.h

// boiler-plate code {{
#ifndef MainImGui_h
#define MainImGui_h

// NOTE: For portability, use only standard C++ code or OpenGL code.

#include <string>

using namespace std;

#include <imgui.h>

class MainImGui
{
public:
    MainImGui(ImVec4 clearColor = ImColor(114, 144, 154));
    virtual ~MainImGui();
    void renderImGui();
    bool initFont();

protected:
    ImVec4 clear_color;
// boiler-plate code }}

    bool show_test_window;
    bool show_another_window;

// boiler-plate code {{
};
#endif
// boiler-plate code }}
