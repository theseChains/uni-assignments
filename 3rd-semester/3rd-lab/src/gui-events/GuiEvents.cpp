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

void guiHandleEllipseEvents(std::array<std::unique_ptr<Ellipse>, 3>& ellipsesToRender,
        VectorOfArrayOfEllipsePtrs& ellipseArraysToRender)
{
    if (mode::ellipses)
    {
        GuiCreation::checkForShapeCreation(ellipsesToRender);
        guiCheckForEllipseShapeModification(ellipsesToRender, ellipseArraysToRender);
        guiCheckForShapeMovement(ellipsesToRender, ellipseArraysToRender);
    }
}

// array creation
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

void guiHandleEllipseArrayCreation(VectorOfArrayOfEllipsePtrs& ellipseArraysToRender)
{
    if (mode::ellipses)
    {
        GuiArrayCreation::checkForShapeArrayCreation(ellipseArraysToRender);
    }
}
