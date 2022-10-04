#include "GuiShapeMovement.h"

template <typename ShapeType>
void guiCheckForShapeMovement(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender,
        VectorOfArrayOfShapePtrs<ShapeType>& shapeArraysToRender)
{
    if (ImGui::Button("Move shapes up (W)"))
    {
        Movement::moveShapeArrayUp(shapesToRender);

        for (auto& shapeArray : shapeArraysToRender)
        {
            Movement::moveShapeArrayUp(shapeArray);
        }
    }
    if (ImGui::Button("Move shapes left (A)"))
    {
        Movement::moveShapeArrayLeft(shapesToRender);

        for (auto& shapeArray : shapeArraysToRender)
        {
            Movement::moveShapeArrayLeft(shapeArray);
        }
    }
    if (ImGui::Button("Move shapes down (S)"))
    {
        Movement::moveShapeArrayDown(shapesToRender);

        for (auto& shapeArray : shapeArraysToRender)
        {
            Movement::moveShapeArrayDown(shapeArray);
        }
    }
    if (ImGui::Button("Move shapes right (D)"))
    {
        Movement::moveShapeArrayRight(shapesToRender);

        for (auto& shapeArray : shapeArraysToRender)
        {
            Movement::moveShapeArrayRight(shapeArray);
        }
    }
    if (ImGui::Button("Move shapes to a random\npoint (Q)"))
    {
        Movement::moveShapeArrayToRandomPoint(shapesToRender);

        for (auto& shapeArray : shapeArraysToRender)
        {
            Movement::moveShapeArrayToRandomPoint(shapeArray);
        }
    }
}

template void guiCheckForShapeMovement(std::array<std::unique_ptr<Circle>, 3>&,
        VectorOfArrayOfCirclePtrs&);
template void guiCheckForShapeMovement(std::array<std::unique_ptr<Rectangle>, 3>&,
        VectorOfArrayOfRectanglePtrs&);
template void guiCheckForShapeMovement(std::array<std::unique_ptr<Ellipse>, 3>&,
        VectorOfArrayOfEllipsePtrs&);
template void guiCheckForShapeMovement(std::array<std::unique_ptr<Quadrangle>, 3>&,
        VectorOfArrayOfQuadranglePtrs&);
template void guiCheckForShapeMovement(std::array<std::unique_ptr<Rhombus>, 3>&,
        VectorOfArrayOfRhombusPtrs&);
template void guiCheckForShapeMovement(std::array<std::unique_ptr<Trapezoid>, 3>&,
        VectorOfArrayOfTrapezoidPtrs&);
