#include "GuiShapeMovement.h"

void guiCheckForShapeMovement(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    if (ImGui::Button("Move shapes up (W)"))
    {
        Movement::moveAllShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (ImGui::Button("Move shapes left (A)"))
    {
        Movement::moveAllShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (ImGui::Button("Move shapes down (S)"))
    {
        Movement::moveAllShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (ImGui::Button("Move shapes right (D)"))
    {
        Movement::moveAllShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (ImGui::Button("Move shapes to a random\npoint (Q)"))
    {
        Movement::moveAllShapes(shapesToRender);
    }
}

void guiCheckForCircularShapeMovement(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    if (ImGui::Button("Move circular shapes\nup (W)"))
    {
        Movement::moveCircularShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (ImGui::Button("Move circular shapes\nleft (A)"))
    {
        Movement::moveCircularShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (ImGui::Button("Move circular shapes\ndown (S)"))
    {
        Movement::moveCircularShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (ImGui::Button("Move circular shapes\nright (D)"))
    {
        Movement::moveCircularShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (ImGui::Button("Move circular shapes\nto a random point (Q)"))
    {
        Movement::moveCircularShapes(shapesToRender);
    }
}

void guiCheckForQuadrangularShapeMovement(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    if (ImGui::Button("Move quadrangular shapes\nup (W)"))
    {
        Movement::moveQuadrangularShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (ImGui::Button("Move quadrangular shapes\nleft (A)"))
    {
        Movement::moveQuadrangularShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (ImGui::Button("Move quadrangular shapes\ndown (S)"))
    {
        Movement::moveQuadrangularShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (ImGui::Button("Move quadrangular shapes\nright (D)"))
    {
        Movement::moveQuadrangularShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (ImGui::Button("Move quadrangular shapes\nto a random point (Q)"))
    {
        Movement::moveQuadrangularShapes(shapesToRender);
    }
}
