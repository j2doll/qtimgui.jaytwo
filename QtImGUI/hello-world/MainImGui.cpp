// MainImGui.cpp

#include "MainImGui.h"

#include <cstdlib>
#include <cstdio>

#include "D2Coding-Ver1.3.2-20180524.ttf.h"
#include "NanumGothic.ttf.h"

// NOTE: For portability, use only standard C++ code or OpenGL code.

MainImGui::MainImGui(ImVec4 clearColor)
{
    clear_color = clearColor;

    show_test_window = true;
    show_another_window = false;

    ImGui::CreateContext();

    if ( ! initFont() )
    {
        // Failed to set font
    }


}

bool MainImGui::initFont()
{
    float fontSize = 16.0f; // font size
    if ( ImGui::GetIO().Fonts == NULL )
        return false;

    // Korean
    const ImWchar* ptrImWchar = ImGui::GetIO().Fonts->GetGlyphRangesKorean();
    if ( ptrImWchar == NULL )
        return false;
    // const ImWchar* ptrImWchar = NULL;

    // D2Coding font
    void* ptrBuffer = malloc( D2Coding_Ver1_3_2_20180524_ttf_len );
    unsigned int bufferLen = D2Coding_Ver1_3_2_20180524_ttf_len;
    memcpy( ptrBuffer, D2Coding_Ver1_3_2_20180524_ttf, bufferLen );

    // add font(*.ttf) from memory data
    ImGui::GetIO().Fonts->AddFontFromMemoryTTF( ptrBuffer, bufferLen, fontSize, NULL, ptrImWchar );

    return true;
}

MainImGui::~MainImGui()
{
    ImGui::DestroyContext();
}

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
