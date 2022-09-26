#include "GuiConfig.h"

void configureGui()
{
    ImGui::GetStyle().ScaleAllSizes(1.2f);
    ImGui::GetIO().FontGlobalScale = 2.0f;
    ImGui::GetIO().ConfigWindowsResizeFromEdges = false;
    ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;
}

void runGuiLoop()
{
    ImGui::Begin(mode::get().c_str());

    ImGui::SetWindowSize(ImVec2(util::guiWidth, util::windowHeight));
    ImGui::SetWindowPos(ImVec2(0, 0));

    if (ImGui::Button("Change mode (M)"))
    {
        mode::shift();
    }
}
