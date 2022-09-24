#include "Events.h"

void handleCircleEvents(std::array<std::unique_ptr<Circle>, 3>& circlesToRender)
{
    if (workspace::circles)
    {
        Creation::checkForShapeCreation(circlesToRender);
        checkForCircleModification(circlesToRender);
        Movement::checkForShapeMovement(circlesToRender);
    }
}

void handleRectangleEvents(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    if (workspace::rectangles)
    {
        checkForRectangleShapeCreation(rectanglesToRender);
        checkForRectangleModification(rectanglesToRender);
        Movement::checkForShapeMovement(rectanglesToRender);
    }
}

void handleLineEvents(std::array<std::unique_ptr<Line>, 3>& linesToRender)
{
    if (workspace::lines)
    {
        Creation::checkForShapeCreation(linesToRender);
        checkForLineModification(linesToRender);
        Movement::checkForShapeMovement(linesToRender);
    }
}

void handleCircleArrayEvents(VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    if (workspace::circles)
    {
        ArrayCreation::checkForShapeArrayCreation(circleArraysToRender);
        checkForCircleArrayModification(circleArraysToRender);
    }
}

void handleRectangleArrayEvents(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (workspace::rectangles)
    {
        checkForRectangleArrayCreation(rectangleArraysToRender);
        checkForRectangleArrayModification(rectangleArraysToRender);
    }
}

void handleLineArrayEvents(VectorOfArrayOfLinePtrs& lineArraysToRender)
{
    if (workspace::lines)
    {
        ArrayCreation::checkForShapeArrayCreation(lineArraysToRender);
        checkForLineArrayModification(lineArraysToRender);
    }
}
