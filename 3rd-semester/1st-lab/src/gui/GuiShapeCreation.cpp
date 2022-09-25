#include "GuiShapeCreation.h"

template <typename ShapeType>
void Gui::checkForShapeCreation(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender)
{
    if (ImGui::Button("Create default circle (F)"))
    {
        Creation::handleDefaultShapeCreation(shapesToRender[util::defaultShapeIndex]);
    }
}

template void Gui::checkForShapeCreation(std::array<std::unique_ptr<Circle>, 3>&);
template void Gui::checkForShapeCreation(std::array<std::unique_ptr<Line>, 3>&);
