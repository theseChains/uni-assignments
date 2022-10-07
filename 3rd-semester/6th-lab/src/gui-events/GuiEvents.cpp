#include "GuiEvents.h"

void guiHandleShapeArrayEvents(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (container::array)
    {
        if (mode::all)
        {
            GuiArrayCreation::checkForShapeArrayCreation(shapesToRender);
            GuiArrayCreation::checkForShapeArrayDeletion(shapesToRender);
            guiCheckForShapeArrayMovement(shapesToRender);
            guiCheckForShapeVisibilityModification(shapesToRender);
        }
        if (mode::circular)
        {
            guiCheckForCircularShapeArrayMovement(shapesToRender);
            guiCheckForCircularShapeModification(shapesToRender);
            guiCheckForCircularShapeVisibilityModification(shapesToRender);
        }
        if (mode::quadrangular)
        {
            guiCheckForQuadrangularShapeArrayMovement(shapesToRender);
            guiCheckForQuadrangularShapeVisibilityModification(shapesToRender);
        }
    }
}

void guiHandleShapeListEvents(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (container::list)
    {
        if (mode::all)
        {
            GuiArrayCreation::checkForShapeListCreation(shapesToRender);
            GuiArrayCreation::checkForShapeListDeletion(shapesToRender);
        }
        if (mode::circular)
        {

        }
        if (mode::quadrangular)
        {

        }
    }
}

void guiCheckForShapeVisibilityModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Show all shapes (G)"))
    {
        for (auto& shape : shapesToRender)
        {
            showShape(shape);
        }
    }
    if (ImGui::Button("Hide all shapes (H)"))
    {
        for (auto& shape : shapesToRender)
        {
            hideShape(shape);
        }
    }
}

void guiCheckForCircularShapeVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Show circular shapes (G)"))
    {
        for (auto& shape : shapesToRender)
        {
            showCircularShape(shape);
        }
    }
    if (ImGui::Button("Hide circular shapes (H)"))
    {
        for (auto& shape : shapesToRender)
        {
            hideCircularShape(shape);
        }
    }
}

void guiCheckForQuadrangularShapeVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Show quadrangular shapes (G)"))
    {
        for (auto& shape : shapesToRender)
        {
            showQuadrangularShape(shape);
        }
    }
    if (ImGui::Button("Hide quadrangular shapes (H)"))
    {
        for (auto& shape : shapesToRender)
        {
            hideQuadrangularShape(shape);
        }
    }
}
