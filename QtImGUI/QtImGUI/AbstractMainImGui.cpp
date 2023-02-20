

#include "AbstractMainImGui.h"
#include "NanumGothic.ttf.h"

///////////////////////////

AbstractMainImGui::AbstractMainImGui(float fs)
{
    // float fontSize = 16.0f; // font size
    fontSize = fs;

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
    ImGui::GetIO().Fonts->AddFontFromMemoryTTF( ptrBuffer, bufferLen, fontSize, NULL, ptrImWchar );

    return true;
}


///////////////////////////

