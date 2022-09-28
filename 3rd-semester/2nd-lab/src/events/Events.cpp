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
        Modification::checkForLineModification(linesToRender);
        Movement::checkForShapeMovement(linesToRender);
    }
}

void handleRingEvents(std::array<std::unique_ptr<Ring>, 3>& ringsToRender)
{
    if (mode::rings)
    {
        Creation::checkForShapeCreation(ringsToRender);
        Modification::checkForCircularShapeModification(ringsToRender);
        Movement::checkForShapeMovement(ringsToRender);
    }
}

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
        Modification::checkForLineArrayModification(lineArraysToRender);
        Movement::checkForShapeArrayMovement(lineArraysToRender);
    }
}

void handleRingArrayEvents(VectorOfArrayOfRingPtrs& ringArraysToRender)
{
    if (mode::rings)
    {
        ArrayCreation::checkForShapeArrayCreation(ringArraysToRender);
        Modification::checkForCircularShapeArrayModification(ringArraysToRender);
        Movement::checkForShapeArrayMovement(ringArraysToRender);
    }
}
