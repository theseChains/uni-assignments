#include "GuiShapeCreation.h"

template <typename ShapeType>
void Gui::checkForShapeCreation(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender)
{
    if (ImGui::Button("Create default circle (F)"))
    {
        Creation::handleDefaultShapeCreation(shapesToRender[util::defaultShapeIndex]);
    }
    if (ImGui::Button("Create first constructor\ncircle (C)"))
    {
        Creation::handleFirstConstructorShapeCreation(shapesToRender[util::firstConstructorShapeIndex]);
    }
    if (ImGui::Button("Create second constructor\ncircle (V)"))
    {
        Creation::handleSecondConstructorShapeCreation(shapesToRender[util::secondConstructorShapeIndex]);
    }
}

template void Gui::checkForShapeCreation(std::array<std::unique_ptr<Circle>, 3>&);
template void Gui::checkForShapeCreation(std::array<std::unique_ptr<Line>, 3>&);

void Gui::checkForRectangleCreation(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    if (ImGui::Button("Create default rectangle (F)"))
    {
        handleDefaultRectangleCreation(rectanglesToRender[util::defaultShapeIndex]);
    }
    if (ImGui::Button("Create first constructor\nrectangle (C)"))
    {
        handleFirstConstructorRectangleCreation(rectanglesToRender[util::firstConstructorShapeIndex]);
    }
    if (ImGui::Button("Create second constructor\nrectangle (V)"))
    {
        handleSecondConstructorRectangleCreation(rectanglesToRender[util::secondConstructorShapeIndex]);
    }
}
