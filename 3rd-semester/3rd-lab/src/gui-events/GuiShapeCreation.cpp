#include "GuiShapeCreation.h"

template <typename CircularShape>
void GuiCreation::checkForCircularShapeCreation(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender)
{
    if (ImGui::Button("Create default shape (F)"))
    {
        Creation::handleDefaultCircularShapeCreation(shapesToRender[util::defaultShapeIndex]);
    }
    if (ImGui::Button("Create first constructor\nshape (C)"))
    {
        Creation::handleFirstConstructorCircularShapeCreation(shapesToRender[util::firstConstructorShapeIndex]);
    }
    if (ImGui::Button("Create second constructor\nshape (V)"))
    {
        Creation::handleSecondConstructorCircularShapeCreation(shapesToRender[util::secondConstructorShapeIndex]);
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

template void GuiCreation::checkForCircularShapeCreation(std::array<std::unique_ptr<Circle>, 3>&);
template void GuiCreation::checkForCircularShapeCreation(std::array<std::unique_ptr<Ellipse>, 3>&);

template <typename ParallelogrammaticShape>
void GuiCreation::checkForParallelogramCreation(
        std::array<std::unique_ptr<ParallelogrammaticShape>, 3>& shapesToRender)
{
    if (ImGui::Button("Create default shape (F)"))
    {
        Creation::handleDefaultParallelogramCreation(shapesToRender[util::defaultShapeIndex]);
    }
    if (ImGui::Button("Create first constructor\nshape (C)"))
    {
        Creation::handleFirstConstructorParallelogramCreation(
                shapesToRender[util::firstConstructorShapeIndex]);
    }
    if (ImGui::Button("Create second constructor\nshape (V)"))
    {
        Creation::handleSecondConstructorParallelogramCreation(
                shapesToRender[util::secondConstructorShapeIndex]);
    }
    // deletion
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

template void GuiCreation::checkForParallelogramCreation(std::array<std::unique_ptr<Rectangle>, 3>&);
template void GuiCreation::checkForParallelogramCreation(std::array<std::unique_ptr<Rhombus>, 3>&);

void GuiCreation::checkForQuadrangleCreation(std::array<std::unique_ptr<Quadrangle>, 3>& quadranglesToRender)
{
    if (ImGui::Button("Create default shape (F)"))
    {
        Creation::handleDefaultQuadrangleShapeCreation(quadranglesToRender[util::defaultShapeIndex]);
    }
    if (ImGui::Button("Create first constructor\nshape (C)"))
    {
        Creation::handleFirstConstructorQuadrangleCreation(quadranglesToRender[util::firstConstructorShapeIndex]);
    }
    if (ImGui::Button("Create second constructor\nshape (V)"))
    {
        Creation::handleSecondConstructorQuadrangleCreation(quadranglesToRender[util::secondConstructorShapeIndex]);
    }
    // deletion
    if (ImGui::Button("Delete default shape (G)"))
    {
        Creation::hideAndDeleteShape(quadranglesToRender[util::defaultShapeIndex]);
    }
    if (ImGui::Button("Delete first constructor\nshape (Y)"))
    {
        Creation::hideAndDeleteShape(quadranglesToRender[util::firstConstructorShapeIndex]);
    }
    if (ImGui::Button("Delete second constructor\nshape (H)"))
    {
        Creation::hideAndDeleteShape(quadranglesToRender[util::secondConstructorShapeIndex]);
    }
}

void GuiCreation::checkForTrapezoidCreation(std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender)
{
    if (ImGui::Button("Create default shape (F)"))
    {
        Creation::handleDefaultTrapezoidShapeCreation(trapezoidsToRender[util::defaultShapeIndex]);
    }
    if (ImGui::Button("Create first constructor\nshape (C)"))
    {
        Creation::handleFirstConstructorTrapezoidCreation(trapezoidsToRender[util::firstConstructorShapeIndex]);
    }
    if (ImGui::Button("Create second constructor\nshape (V)"))
    {
        Creation::handleSecondConstructorTrapezoidCreation(trapezoidsToRender[util::secondConstructorShapeIndex]);
    }
    // deletion
    if (ImGui::Button("Delete default shape (G)"))
    {
        Creation::hideAndDeleteShape(trapezoidsToRender[util::defaultShapeIndex]);
    }
    if (ImGui::Button("Delete first constructor\nshape (Y)"))
    {
        Creation::hideAndDeleteShape(trapezoidsToRender[util::firstConstructorShapeIndex]);
    }
    if (ImGui::Button("Delete second constructor\nshape (H)"))
    {
        Creation::hideAndDeleteShape(trapezoidsToRender[util::secondConstructorShapeIndex]);
    }
}
