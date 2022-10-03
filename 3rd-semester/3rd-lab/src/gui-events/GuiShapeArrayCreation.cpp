#include "GuiShapeArrayCreation.h"

template <typename CircularShape>
void GuiArrayCreation::checkForCircularShapeArrayCreation(
        VectorOfArrayOfShapePtrs<CircularShape>& arraysToRender)
{
    if (ImGui::Button("Create an array of\nshapes (N)"))
    {
        ArrayCreation::handleCircularShapeArrayCreation(arraysToRender);
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

template void GuiArrayCreation::checkForCircularShapeArrayCreation(VectorOfArrayOfCirclePtrs&);
template void GuiArrayCreation::checkForCircularShapeArrayCreation(VectorOfArrayOfEllipsePtrs&);

void GuiArrayCreation::checkForRectangleArrayCreation(
        VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
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

void GuiArrayCreation::checkForQuadrangleArrayCreation(
        VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender)
{
    if (ImGui::Button("Create an array of\nshapes (N)"))
    {
        ArrayCreation::handleQuadrangleArrayCreation(quadrangleArraysToRender);
    }
    if (ImGui::Button("Delete last array of\nshapes (B)"))
    {
        if (!quadrangleArraysToRender.empty())
        {
            quadrangleArraysToRender.pop_back();
        }
    }
    if (ImGui::Button("Delete all arrays of\nshapes (Space)"))
    {
        quadrangleArraysToRender.clear();
    }
}
