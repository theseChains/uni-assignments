#include "GuiEvents.h"

void guiHandleCircleEvents(std::array<std::unique_ptr<Circle>, 3>& circlesToRender,
        VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (mode::circles)
    {
        GuiCreation::checkForShapeCreation(circlesToRender);
        guiCheckForCircularShapeModification(circlesToRender, circleArraysToRender);
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

void guiHandleRingEvents(std::array<std::unique_ptr<Ring>, 3>& ringsToRender,
        VectorOfArrayOfRingPtrs& ringArraysToRender)
{
    if (mode::rings)
    {
        GuiCreation::checkForShapeCreation(ringsToRender);
        guiCheckForCircularShapeModification(ringsToRender, ringArraysToRender);
        guiCheckForShapeMovement(ringsToRender, ringArraysToRender); 
    }
}

void guiHandleCircleArrayCreation(VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (mode::circles)
    {
        GuiArrayCreation::checkForShapeArrayCreation(circleArraysToRender);
    }
}

void guiHandleRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (mode::rectangles)
    {
        GuiArrayCreation::checkForRectangleArrayCreation(rectangleArraysToRender);
    }
}

void guiHandleLineArrayCreation(VectorOfArrayOfLinePtrs& lineArraysToRender)
{
    if (mode::lines)
    {
        GuiArrayCreation::checkForShapeArrayCreation(lineArraysToRender);
    }
}

void guiHandleRingArrayCreation(VectorOfArrayOfRingPtrs& ringArraysToRender)
{
    if (mode::rings)
    {
        GuiArrayCreation::checkForShapeArrayCreation(ringArraysToRender);
    }
}
