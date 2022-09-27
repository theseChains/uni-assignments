#include "GuiShapeModification.h"

void guiCheckForCircleModification(std::array<std::unique_ptr<Circle>, 3>& circlesToRender,
        VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (ImGui::Button("Enlarge circles (O)"))
    {
        enlargeCircles(circlesToRender);

        for (auto& circleArray : circleArraysToRender)
        {
            enlargeCircles(circleArray);
        }
    }
    if (ImGui::Button("Reduce circles (I)"))
    {
        reduceCircles(circlesToRender);

        for (auto& circleArray : circleArraysToRender)
        {
            reduceCircles(circleArray);
        }
    }
}

void guiCheckForRectangleModification(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender,
        VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (ImGui::Button("Reduce height of\nrectangles (Up)"))
    {
        reduceHeightOfRectangles(rectanglesToRender);

        for (auto& rectangleArray : rectangleArraysToRender)
        {
            reduceHeightOfRectangles(rectangleArray);
        }
    }
    if (ImGui::Button("Reduce width of\nrectangles (Left)"))
    {
        reduceWidthOfRectangles(rectanglesToRender);

        for (auto& rectangleArray : rectangleArraysToRender)
        {
            reduceWidthOfRectangles(rectangleArray);
        }
    }
    if (ImGui::Button("Increase height of\nrectangles (Down)"))
    {
        increaseHeightOfRectangles(rectanglesToRender);

        for (auto& rectangleArray : rectangleArraysToRender)
        {
            increaseHeightOfRectangles(rectangleArray);
        }
    }
    if (ImGui::Button("Increase width of\nrectangles (Right)"))
    {
        increaseWidthOfRectangles(rectanglesToRender);

        for (auto& rectangleArray : rectangleArraysToRender)
        {
            increaseWidthOfRectangles(rectangleArray);
        }
    }
}

void guiCheckForLineModification(std::array<std::unique_ptr<Line>, 3>& linesToRender,
        VectorOfArrayOfLinePtrs& lineArraysToRender)
{
    if (ImGui::Button("Rotate lines clockwise (R)"))
    {
        rotateLinesClockwise(linesToRender);

        for (auto& lineArray : lineArraysToRender)
        {
            rotateLinesClockwise(lineArray);
        }
    }
    if (ImGui::Button("Rotate lines counter-\nclockwise (T)"))
    {
        rotateLinesCounterClockwise(linesToRender);

        for (auto& lineArray : lineArraysToRender)
        {
            rotateLinesCounterClockwise(lineArray);
        }
    }
}
