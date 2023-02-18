// MainImGui.cpp

#include <cstdlib>
#include <cstdio>

#include <string>
#include <iostream>

#include <imgui.h>

#include "MainImGui.h"

// NOTE: For portability, use only standard C++ code or OpenGL code.

//////////////////////////

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

//////////////////////////

