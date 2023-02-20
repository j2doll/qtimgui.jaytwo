
#ifndef ABSTRACT_MAIN_IMGUI_H
#define ABSTRACT_MAIN_IMGUI_H

#include "imgui.h"
#include "ImGuiRenderer.h"

class AbstractMainImGui
{
public:
    AbstractMainImGui(float fontSize = 16.0f);
    virtual ~AbstractMainImGui();

    virtual void renderImGui() = 0;

    float fontSize;

protected:
    virtual bool initFont();

};

#endif
