#include "GuiEvents.h"

void guiHandleCircleEvents(std::array<std::unique_ptr<Circle>, 3>& circlesToRender)
{
    if (mode::circles)
    {
        GuiCreation::checkForShapeCreation(circlesToRender);
    }
}

void guiHandleRectangleEvents(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    if (mode::rectangles)
    {
        GuiCreation::checkForRectangleCreation(rectanglesToRender);
    }
}

void guiHandleLineEvents(std::array<std::unique_ptr<Line>, 3>& linesToRender)
{
    if (mode::lines)
    {
        GuiCreation::checkForShapeCreation(linesToRender);
    }
}

void guiHandleCircleArrayEvents(VectorOfArrayOfCirclePtrs& circelArraysToRender)
{
    if (mode::circles)
    {

    }
}

void guiHandleRectangleArrayEvents(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (mode::rectangles)
    {

    }
}

void guiHandleLineArrayEvents(VectorOfArrayOfLinePtrs& lineArraysToRender)
{
    if (mode::lines)
    {

    }
}
