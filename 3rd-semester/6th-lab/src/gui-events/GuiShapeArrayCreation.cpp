#include "GuiShapeArrayCreation.h"

void GuiArrayCreation::checkForShapeCreation(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Create random shapes (N)"))
    {
        ArrayCreation::createRandomShapes(shapesToRender);
    }
}

void GuiArrayCreation::checkForShapeDeletion(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Delete all shapes (Space)"))
    {
        ArrayCreation::deleteAllShapes(shapesToRender);
    }
}
