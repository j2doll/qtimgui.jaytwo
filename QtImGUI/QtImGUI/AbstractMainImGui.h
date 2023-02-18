
#ifndef ABSTRACT_MAIN_IMGUI_H
#define ABSTRACT_MAIN_IMGUI_H

#include "ImGuiRenderer.h"

class AbstractMainImGui
{
public:
    AbstractMainImGui(ImVec4 clearColor);
    virtual ~AbstractMainImGui();

    virtual bool initFont();
    virtual void renderImGui();

protected:
    ImVec4 clear_color;

};

#endif
