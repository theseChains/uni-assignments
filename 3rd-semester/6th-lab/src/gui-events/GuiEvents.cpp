#include "GuiEvents.h"

void guiHandleShapeArrayEvents(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (mode::all)
    {
        GuiArrayCreation::checkForShapeCreation(shapesToRender);
        GuiArrayCreation::checkForShapeDeletion(shapesToRender);
        guiCheckForShapeMovement(shapesToRender);
        guiCheckForShapeVisibilityModification(shapesToRender);
    }
    if (mode::circular)
    {
        guiCheckForCircularShapeMovement(shapesToRender);
        guiCheckForCircularShapeModification(shapesToRender);
        guiCheckForCircularShapeVisibilityModification(shapesToRender);
    }
    if (mode::quadrangular)
    {
        guiCheckForQuadrangularShapeMovement(shapesToRender);
        guiCheckForQuadrangularShapeVisibilityModification(shapesToRender);
    }
}

void guiCheckForShapeVisibilityModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Show all shapes (G)"))
    {
        showAllShapes(shapesToRender);
    }
    if (ImGui::Button("Hide all shapes (H)"))
    {
        hideAllShapes(shapesToRender);
    }
}

void guiCheckForCircularShapeVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Show circular shapes (G)"))
    {
        showCircularShapes(shapesToRender);
    }
    if (ImGui::Button("Hide circular shapes (H)"))
    {
        hideCircularShapes(shapesToRender);
    }
}

void guiCheckForQuadrangularShapeVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Show quadrangular shapes (G)"))
    {
        showQuadrangularShapes(shapesToRender);
    }
    if (ImGui::Button("Hide quadrangular shapes (H)"))
    {
        hideQuadrangularShapes(shapesToRender);
    }
}
