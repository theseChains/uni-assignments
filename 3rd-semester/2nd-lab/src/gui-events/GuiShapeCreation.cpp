#include "GuiShapeCreation.h"

template <typename ShapeType>
void GuiCreation::checkForShapeCreation(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender)
{
    if (ImGui::Button("Create default shape (F)"))
    {
        Creation::handleDefaultShapeCreation(shapesToRender[util::defaultShapeIndex]);
    }
    if (ImGui::Button("Create first constructor\nshape (C)"))
    {
        Creation::handleFirstConstructorShapeCreation(shapesToRender[util::firstConstructorShapeIndex]);
    }
    if (ImGui::Button("Create second constructor\nshape (V)"))
    {
        Creation::handleSecondConstructorShapeCreation(shapesToRender[util::secondConstructorShapeIndex]);
    }
    // also deletion is here
    if (ImGui::Button("Delete default shape (G)"))
    {
        Creation::hideAndDeleteShape(shapesToRender[util::defaultShapeIndex]);
    }
    if (ImGui::Button("Delete first constructor\nshape (Y)"))
    {
        Creation::hideAndDeleteShape(shapesToRender[util::firstConstructorShapeIndex]);
    }
    if (ImGui::Button("Delete second constructor\nshape (H)"))
    {
        Creation::hideAndDeleteShape(shapesToRender[util::secondConstructorShapeIndex]);
    }
}

template void GuiCreation::checkForShapeCreation(std::array<std::unique_ptr<Circle>, 3>&);
template void GuiCreation::checkForShapeCreation(std::array<std::unique_ptr<Line>, 3>&);

void GuiCreation::checkForRectangleCreation(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    if (ImGui::Button("Create default shape (F)"))
    {
        Creation::handleDefaultRectangleCreation(rectanglesToRender[util::defaultShapeIndex]);
    }
    if (ImGui::Button("Create first constructor\nshape (C)"))
    {
        Creation::handleFirstConstructorRectangleCreation(rectanglesToRender[util::firstConstructorShapeIndex]);
    }
    if (ImGui::Button("Create second constructor\nshape (V)"))
    {
        Creation::handleSecondConstructorRectangleCreation(rectanglesToRender[util::secondConstructorShapeIndex]);
    }
    // deletion
    if (ImGui::Button("Delete default shape (G)"))
    {
        Creation::hideAndDeleteShape(rectanglesToRender[util::defaultShapeIndex]);
    }
    if (ImGui::Button("Delete first constructor\nshape (Y)"))
    {
        Creation::hideAndDeleteShape(rectanglesToRender[util::firstConstructorShapeIndex]);
    }
    if (ImGui::Button("Delete second constructor\nshape (H)"))
    {
        Creation::hideAndDeleteShape(rectanglesToRender[util::secondConstructorShapeIndex]);
    }
}
