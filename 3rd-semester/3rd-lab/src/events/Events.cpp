#include "Events.h"

void handleCircleEvents(std::array<std::unique_ptr<Circle>, 3>& circlesToRender)
{
    if (mode::circles)
    {
        Creation::checkForShapeCreation(circlesToRender);
        Modification::checkForCircularShapeModification(circlesToRender);
        Movement::checkForShapeMovement(circlesToRender);
    }
}

void handleRectangleEvents(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    if (mode::rectangles)
    {
        Creation::checkForRectangleShapeCreation(rectanglesToRender);
        Modification::checkForRectangleModification(rectanglesToRender);
        Movement::checkForShapeMovement(rectanglesToRender);
    }
}

void handleLineEvents(std::array<std::unique_ptr<Line>, 3>& linesToRender)
{
    if (mode::lines)
    {
        Creation::checkForShapeCreation(linesToRender);
        Modification::checkForLineShapeModification(linesToRender);
        Movement::checkForShapeMovement(linesToRender);
    }
}

void handleEllipseEvents(std::array<std::unique_ptr<Ellipse>, 3>& ellipsesToRender)
{
    if (mode::ellipses)
    {
        Creation::checkForShapeCreation(ellipsesToRender);
        Movement::checkForShapeMovement(ellipsesToRender);
    }
}

// arrays of shapes
void handleCircleArrayEvents(VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (mode::circles)
    {
        ArrayCreation::checkForShapeArrayCreation(circleArraysToRender);
        Modification::checkForCircularShapeArrayModification(circleArraysToRender);
        Movement::checkForShapeArrayMovement(circleArraysToRender);
    }
}

void handleRectangleArrayEvents(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (mode::rectangles)
    {
        ArrayCreation::checkForRectangleArrayCreation(rectangleArraysToRender);
        Modification::checkForRectangleArrayModification(rectangleArraysToRender);
        Movement::checkForShapeArrayMovement(rectangleArraysToRender);
    }
}

void handleLineArrayEvents(VectorOfArrayOfLinePtrs& lineArraysToRender)
{
    if (mode::lines)
    {
        ArrayCreation::checkForShapeArrayCreation(lineArraysToRender);
        Modification::checkForLineShapeArrayModification(lineArraysToRender);
        Movement::checkForShapeArrayMovement(lineArraysToRender);
    }
}
