#include "Events.h"

void handleCircleEvents(std::array<std::unique_ptr<Circle>, 3>& circlesToRender)
{
    if (mode::circles)
    {
        Creation::checkForShapeCreation(circlesToRender);
        checkForCircleModification(circlesToRender);
        Movement::checkForShapeMovement(circlesToRender);
    }
}

void handleRectangleEvents(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    if (mode::rectangles)
    {
        checkForRectangleShapeCreation(rectanglesToRender);
        checkForRectangleModification(rectanglesToRender);
        Movement::checkForShapeMovement(rectanglesToRender);
    }
}

void handleLineEvents(std::array<std::unique_ptr<Line>, 3>& linesToRender)
{
    if (mode::lines)
    {
        Creation::checkForShapeCreation(linesToRender);
        checkForLineModification(linesToRender);
        Movement::checkForShapeMovement(linesToRender);
    }
}

void handleCircleArrayEvents(VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (mode::circles)
    {
        ArrayCreation::checkForShapeArrayCreation(circleArraysToRender);
        checkForCircleArrayModification(circleArraysToRender);
        Movement::checkForShapeArrayMovement(circleArraysToRender);
    }
}

void handleRectangleArrayEvents(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (mode::rectangles)
    {
        checkForRectangleArrayCreation(rectangleArraysToRender);
        checkForRectangleArrayModification(rectangleArraysToRender);
        Movement::checkForShapeArrayMovement(rectangleArraysToRender);
    }
}

void handleLineArrayEvents(VectorOfArrayOfLinePtrs& lineArraysToRender)
{
    if (mode::lines)
    {
        ArrayCreation::checkForShapeArrayCreation(lineArraysToRender);
        checkForLineArrayModification(lineArraysToRender);
        Movement::checkForShapeArrayMovement(lineArraysToRender);
    }
}
