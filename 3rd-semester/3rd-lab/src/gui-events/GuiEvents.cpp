#include "GuiEvents.h"

void guiHandleCircleEvents(std::array<std::unique_ptr<Circle>, 3>& circlesToRender,
        VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (mode::circles)
    {
        GuiCreation::checkForCircularShapeCreation(circlesToRender);
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
        GuiCreation::checkForCircularShapeCreation(ellipsesToRender);
        guiCheckForEllipseShapeModification(ellipsesToRender, ellipseArraysToRender);
        guiCheckForShapeMovement(ellipsesToRender, ellipseArraysToRender);
    }
}

void guiHandleQuadrangleEvents(std::array<std::unique_ptr<Quadrangle>, 3>& quadranglesToRender,
        VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender)
{
    if (mode::quadrangles)
    {
        GuiCreation::checkForQuadrangleCreation(quadranglesToRender);
        guiCheckForShapeMovement(quadranglesToRender, quadrangleArraysToRender);
    }
}

// array creation
void guiHandleCircleArrayCreation(VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (mode::circles)
    {
        GuiArrayCreation::checkForCircularShapeArrayCreation(circleArraysToRender);
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
        GuiArrayCreation::checkForCircularShapeArrayCreation(ellipseArraysToRender);
    }
}

void guiHandleQuadrangleArrayCreation(VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender)
{
    if (mode::quadrangles)
    {
        GuiArrayCreation::checkForQuadrangleArrayCreation(quadrangleArraysToRender);
    }
}
