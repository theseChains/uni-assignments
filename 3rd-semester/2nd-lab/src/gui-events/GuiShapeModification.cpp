#include "GuiShapeModification.h"

void guiCheckForCircleModification(std::array<std::unique_ptr<Circle>, 3>& circlesToRender,
        VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (ImGui::Button("Enlarge circles (O)"))
    {
        Modification::enlargeCircles(circlesToRender);

        for (auto& circleArray : circleArraysToRender)
        {
            Modification::enlargeCircles(circleArray);
        }
    }
    if (ImGui::Button("Reduce circles (I)"))
    {
        Modification::reduceCircles(circlesToRender);

        for (auto& circleArray : circleArraysToRender)
        {
            Modification::reduceCircles(circleArray);
        }
    }
}

void guiCheckForRectangleModification(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender,
        VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (ImGui::Button("Reduce height of\nrectangles (Up)"))
    {
        Modification::reduceHeightOfRectangles(rectanglesToRender);

        for (auto& rectangleArray : rectangleArraysToRender)
        {
            Modification::reduceHeightOfRectangles(rectangleArray);
        }
    }
    if (ImGui::Button("Reduce width of\nrectangles (Left)"))
    {
        Modification::reduceWidthOfRectangles(rectanglesToRender);

        for (auto& rectangleArray : rectangleArraysToRender)
        {
            Modification::reduceWidthOfRectangles(rectangleArray);
        }
    }
    if (ImGui::Button("Increase height of\nrectangles (Down)"))
    {
        Modification::increaseHeightOfRectangles(rectanglesToRender);

        for (auto& rectangleArray : rectangleArraysToRender)
        {
            Modification::increaseHeightOfRectangles(rectangleArray);
        }
    }
    if (ImGui::Button("Increase width of\nrectangles (Right)"))
    {
        Modification::increaseWidthOfRectangles(rectanglesToRender);

        for (auto& rectangleArray : rectangleArraysToRender)
        {
            Modification::increaseWidthOfRectangles(rectangleArray);
        }
    }
}

void guiCheckForLineModification(std::array<std::unique_ptr<Line>, 3>& linesToRender,
        VectorOfArrayOfLinePtrs& lineArraysToRender)
{
    if (ImGui::Button("Rotate lines clockwise (R)"))
    {
        Modification::rotateLinesClockwise(linesToRender);

        for (auto& lineArray : lineArraysToRender)
        {
            Modification::rotateLinesClockwise(lineArray);
        }
    }
    if (ImGui::Button("Rotate lines counter-\nclockwise (T)"))
    {
        Modification::rotateLinesCounterClockwise(linesToRender);

        for (auto& lineArray : lineArraysToRender)
        {
            Modification::rotateLinesCounterClockwise(lineArray);
        }
    }
}
