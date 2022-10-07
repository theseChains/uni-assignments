#include "GuiShapeArrayCreation.h"

void GuiArrayCreation::checkForShapeArrayCreation(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Create random shapes (N)"))
    {
        ArrayCreation::createRandomShapes(shapesToRender);
    }
}

void GuiArrayCreation::checkForShapeArrayDeletion(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Delete all shapes (Space)"))
    {
        ArrayCreation::deleteAllShapes(shapesToRender);
    }
}

void GuiArrayCreation::checkForShapeListCreation(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Create random shapes (N)"))
    {
        ListCreation::createRandomShapes(shapesToRender);
    }
}

void GuiArrayCreation::checkForShapeListDeletion(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Delete all shapes (Space)"))
    {
        ListCreation::deleteAllShapes(shapesToRender);
    }
}
