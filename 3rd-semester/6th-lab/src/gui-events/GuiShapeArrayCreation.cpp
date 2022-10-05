#include "GuiShapeArrayCreation.h"

void GuiArrayCreation::checkForShapeCreation(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    if (ImGui::Button("Create random shapes (N)"))
    {
        ArrayCreation::createRandomShapes(shapesToRender);
    }
}

void GuiArrayCreation::checkForShapeDeletion(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    if (ImGui::Button("Delete all shapes (Space)"))
    {
        ArrayCreation::deleteAllShapes(shapesToRender);
    }
}
