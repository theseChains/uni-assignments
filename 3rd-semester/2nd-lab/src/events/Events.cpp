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

void handleRingEvents(std::array<std::unique_ptr<Ring>, 3>& ringsToRender)
{
    if (mode::rings)
    {
        Creation::checkForShapeCreation(ringsToRender);
        Modification::checkForCircularShapeModification(ringsToRender);
        Movement::checkForShapeMovement(ringsToRender);
    }
}

void handleAsteriskEvents(std::array<std::unique_ptr<Asterisk>, 3>& asterisksToRender)
{
    if (mode::asterisks)
    {
        Creation::checkForShapeCreation(asterisksToRender);
        Modification::checkForLineShapeModification(asterisksToRender); 
        Movement::checkForShapeMovement(asterisksToRender);
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

void handleRingArrayEvents(VectorOfArrayOfRingPtrs& ringArraysToRender)
{
    if (mode::rings)
    {
        ArrayCreation::checkForShapeArrayCreation(ringArraysToRender);
        Modification::checkForCircularShapeArrayModification(ringArraysToRender);
        Movement::checkForShapeArrayMovement(ringArraysToRender);
    }
}

void handleAsteriskArrayEvents(VectorOfArrayOfAsteriskPtrs& asteriskArraysToRender)
{
    if (mode::asterisks)
    {
        ArrayCreation::checkForShapeArrayCreation(asteriskArraysToRender);
        Modification::checkForLineShapeArrayModification(asteriskArraysToRender);
        Movement::checkForShapeArrayMovement(asteriskArraysToRender);
    }
}
