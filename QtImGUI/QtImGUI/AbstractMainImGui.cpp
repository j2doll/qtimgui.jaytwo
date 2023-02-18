

#include "AbstractMainImGui.h"
#include "NanumGothic.ttf.h"

///////////////////////////

AbstractMainImGui::AbstractMainImGui(ImVec4 clearColor)
{
    clear_color = clearColor;

    ImGui::CreateContext();

    if ( ! initFont() )
    {
        // Failed to set font
    }

}

//////////////////////////

AbstractMainImGui::~AbstractMainImGui()
{
    ImGui::DestroyContext();
}

//////////////////////////

bool AbstractMainImGui::initFont()
{
    if ( ImGui::GetIO().Fonts == NULL )
        return false;

    // Korean font
    const ImWchar* ptrImWchar = ImGui::GetIO().Fonts->GetGlyphRangesKorean();
    if ( ptrImWchar == NULL )
        return false;

    // Nanum Gothic font
    void* ptrBuffer = malloc( NanumGothic_ttf_len );
    unsigned int bufferLen = NanumGothic_ttf_len;
    memcpy( ptrBuffer, NanumGothic_ttf, bufferLen );

    // add font(*.ttf) from memory data
    float fontSize = 16.0f; // font size
    ImGui::GetIO().Fonts->AddFontFromMemoryTTF( ptrBuffer, bufferLen, fontSize, NULL, ptrImWchar );

    return true;
}

//////////////////////////

void AbstractMainImGui::renderImGui()
{
    // TODO: Define your oen redering of ImGUI
}

///////////////////////////

