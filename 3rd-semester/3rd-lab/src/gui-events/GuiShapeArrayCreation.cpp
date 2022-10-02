#include "GuiShapeArrayCreation.h"

template <typename ShapeType>
void GuiArrayCreation::checkForShapeArrayCreation(VectorOfArrayOfShapePtrs<ShapeType>& arraysToRender)
{
    if (ImGui::Button("Create an array of\nshapes (N)"))
    {
        ArrayCreation::handleShapeArrayCreation(arraysToRender);
    }
    if (ImGui::Button("Delete last array of\nshapes (B)"))
    {
        if (!arraysToRender.empty())
        {
            arraysToRender.pop_back();
        }
    }
    if (ImGui::Button("Delete all arrays of\nshapes (Space)"))
    {
        arraysToRender.clear();
    }
}

template void GuiArrayCreation::checkForShapeArrayCreation(VectorOfArrayOfCirclePtrs&);
template void GuiArrayCreation::checkForShapeArrayCreation(VectorOfArrayOfEllipsePtrs&);

void GuiArrayCreation::checkForRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (ImGui::Button("Create an array of\nshapes (N)"))
    {
        ArrayCreation::handleRectangleArrayCreation(rectangleArraysToRender);
    }
    if (ImGui::Button("Delete last array of\nshapes (B)"))
    {
        if (!rectangleArraysToRender.empty())
        {
            rectangleArraysToRender.pop_back();
        }
    }
    if (ImGui::Button("Delete all arrays of\nshapes (Space)"))
    {
        rectangleArraysToRender.clear();
    }
}
