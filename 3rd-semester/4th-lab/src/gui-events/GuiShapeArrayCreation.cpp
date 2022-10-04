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

template <typename ParallelogrammaticShape>
void GuiArrayCreation::checkForParallelogramArrayCreation(
        VectorOfArrayOfParalellogramShapePtrs<ParallelogrammaticShape>& shapeArraysToRender)
{
    if (ImGui::Button("Create an array of\nshapes (N)"))
    {
        ArrayCreation::handleParallelogramArrayCreation(shapeArraysToRender);
    }
    if (ImGui::Button("Delete last array of\nshapes (B)"))
    {
        if (!shapeArraysToRender.empty())
        {
            shapeArraysToRender.pop_back();
        }
    }
    if (ImGui::Button("Delete all arrays of\nshapes (Space)"))
    {
        shapeArraysToRender.clear();
    }
}

template void GuiArrayCreation::checkForParallelogramArrayCreation(VectorOfArrayOfRectanglePtrs&);
template void GuiArrayCreation::checkForParallelogramArrayCreation(VectorOfArrayOfRhombusPtrs&);

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

void GuiArrayCreation::checkForTrapezoidArrayCreation(
        VectorOfArrayOfTrapezoidPtrs& trapezoidArraysToRender)
{
    if (ImGui::Button("Create an array of\nshapes (N)"))
    {
        ArrayCreation::handleTrapezoidArrayCreation(trapezoidArraysToRender);
    }
    if (ImGui::Button("Delete last array of\nshapes (B)"))
    {
        if (!trapezoidArraysToRender.empty())
        {
            trapezoidArraysToRender.pop_back();
        }
    }
    if (ImGui::Button("Delete all arrays of\nshapes (Space)"))
    {
        trapezoidArraysToRender.clear();
    }
}
