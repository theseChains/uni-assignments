#include "GuiEvents.h"

void guiHandleCircleEvents(std::array<std::unique_ptr<Circle>, 3>& circlesToRender,
        VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (mode::circles)
    {
        GuiCreation::checkForShapeCreation(circlesToRender);
        guiCheckForCircleModification(circlesToRender, circleArraysToRender);
        guiCheckForShapeMovement(circlesToRender, circleArraysToRender);
    }
}

void guiHandleRectangleEvents(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender,
        VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (mode::rectangles)
    {
        GuiCreation::checkForRectangleCreation(rectanglesToRender);
        guiCheckForRectangleModification(rectanglesToRender, rectangleArraysToRender);
        guiCheckForShapeMovement(rectanglesToRender, rectangleArraysToRender);
    }
}

void guiHandleLineEvents(std::array<std::unique_ptr<Line>, 3>& linesToRender,
        VectorOfArrayOfLinePtrs& lineArraysToRender)
{
    if (mode::lines)
    {
        GuiCreation::checkForShapeCreation(linesToRender);
        guiCheckForLineModification(linesToRender, lineArraysToRender);
        guiCheckForShapeMovement(linesToRender, lineArraysToRender); 
    }
}

void guiHandleCircleArrayEvents(VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (mode::circles)
    {
        GuiArrayCreation::checkForShapeArrayCreation(circleArraysToRender);
    }
}

void guiHandleRectangleArrayEvents(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (mode::rectangles)
    {
        GuiArrayCreation::checkForRectangleArrayCreation(rectangleArraysToRender);
    }
}

void guiHandleLineArrayEvents(VectorOfArrayOfLinePtrs& lineArraysToRender)
{
    if (mode::lines)
    {
        GuiArrayCreation::checkForShapeArrayCreation(lineArraysToRender);
    }
}
