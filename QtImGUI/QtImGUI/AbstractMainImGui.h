
#ifndef ABSTRACT_MAIN_IMGUI_H
#define ABSTRACT_MAIN_IMGUI_H

#include "imgui.h"
#include "ImGuiRenderer.h"

class AbstractMainImGui
{
public:
    AbstractMainImGui();
    virtual ~AbstractMainImGui();

    virtual void renderImGui() = 0;

protected:
    virtual bool initFont();

};

#endif
