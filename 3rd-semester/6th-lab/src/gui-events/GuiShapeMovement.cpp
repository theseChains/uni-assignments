#include "GuiShapeMovement.h"

void guiCheckForShapeArrayMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Move shapes up (W)"))
    {
        Movement::moveAllArrayShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (ImGui::Button("Move shapes left (A)"))
    {
        Movement::moveAllArrayShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (ImGui::Button("Move shapes down (S)"))
    {
        Movement::moveAllArrayShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (ImGui::Button("Move shapes right (D)"))
    {
        Movement::moveAllArrayShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (ImGui::Button("Move shapes to a random\npoint (Q)"))
    {
        Movement::moveAllArrayShapes(shapesToRender);
    }
}

void guiCheckForCircularShapeArrayMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Move circular shapes\nup (W)"))
    {
        Movement::moveCircularArrayShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (ImGui::Button("Move circular shapes\nleft (A)"))
    {
        Movement::moveCircularArrayShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (ImGui::Button("Move circular shapes\ndown (S)"))
    {
        Movement::moveCircularArrayShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (ImGui::Button("Move circular shapes\nright (D)"))
    {
        Movement::moveCircularArrayShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (ImGui::Button("Move circular shapes\nto a random point (Q)"))
    {
        Movement::moveCircularArrayShapes(shapesToRender);
    }
}

void guiCheckForQuadrangularShapeArrayMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Move quadrangular shapes\nup (W)"))
    {
        Movement::moveQuadrangularArrayShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (ImGui::Button("Move quadrangular shapes\nleft (A)"))
    {
        Movement::moveQuadrangularArrayShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (ImGui::Button("Move quadrangular shapes\ndown (S)"))
    {
        Movement::moveQuadrangularArrayShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (ImGui::Button("Move quadrangular shapes\nright (D)"))
    {
        Movement::moveQuadrangularArrayShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (ImGui::Button("Move quadrangular shapes\nto a random point (Q)"))
    {
        Movement::moveQuadrangularArrayShapes(shapesToRender);
    }
}

void guiCheckForShapeListMovement(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Move shapes up (W)"))
    {
        Movement::moveAllListShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (ImGui::Button("Move shapes left (A)"))
    {
        Movement::moveAllListShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (ImGui::Button("Move shapes down (S)"))
    {
        Movement::moveAllListShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (ImGui::Button("Move shapes right (D)"))
    {
        Movement::moveAllListShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (ImGui::Button("Move shapes to a random\npoint (Q)"))
    {
        Movement::moveAllListShapes(shapesToRender);
    }
}

void guiCheckForCircularShapeListMovement(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Move circular shapes\nup (W)"))
    {
        Movement::moveCircularListShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (ImGui::Button("Move circular shapes\nleft (A)"))
    {
        Movement::moveCircularListShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (ImGui::Button("Move circular shapes\ndown (S)"))
    {
        Movement::moveCircularListShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (ImGui::Button("Move circular shapes\nright (D)"))
    {
        Movement::moveCircularListShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (ImGui::Button("Move circular shapes\nto a random point (Q)"))
    {
        Movement::moveCircularListShapes(shapesToRender);
    }
}

void guiCheckForQuadrangularShapeListMovement(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Move quadrangular shapes\nup (W)"))
    {
        Movement::moveQuadrangularListShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (ImGui::Button("Move quadrangular shapes\nleft (A)"))
    {
        Movement::moveQuadrangularListShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (ImGui::Button("Move quadrangular shapes\ndown (S)"))
    {
        Movement::moveQuadrangularListShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (ImGui::Button("Move quadrangular shapes\nright (D)"))
    {
        Movement::moveQuadrangularListShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (ImGui::Button("Move quadrangular shapes\nto a random point (Q)"))
    {
        Movement::moveQuadrangularListShapes(shapesToRender);
    }
}
