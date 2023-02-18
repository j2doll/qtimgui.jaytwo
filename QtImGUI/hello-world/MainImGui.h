// MainImGui.h

// boiler-plate code {{
#ifndef MainImGui_h
#define MainImGui_h

// NOTE: For portability, use only standard C++ code or OpenGL code.

#include <string>

#include <imgui.h>
#include <AbstractMainImGui.h>

class MainImGui : public AbstractMainImGui
{
public:
    MainImGui();
    virtual ~MainImGui();

    void renderImGui();

protected:
// boiler-plate code }}

    bool show_test_window;
    bool show_another_window;

// boiler-plate code {{
};
#endif
// boiler-plate code }}
