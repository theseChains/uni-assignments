#include "Events.h"

void circleEventHandlerFunction(std::array<std::unique_ptr<Circle>, 3>& circlesToRender)
{
    if (workspace::circles)
    {
        Creation::checkForShapeCreation(circlesToRender);
        checkForCircleModification(circlesToRender);
        Movement::checkForShapeMovement(circlesToRender);
    }
}

void rectangleEventHandlerFunction(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    if (workspace::rectangles)
    {
        checkForRectangleShapeCreation(rectanglesToRender);
        checkForRectangleModification(rectanglesToRender);
        Movement::checkForShapeMovement(rectanglesToRender);
    }
}

void lineEventHandlerFunction(std::array<std::unique_ptr<Line>, 3>& linesToRender)
{
    if (workspace::lines)
    {
        Creation::checkForShapeCreation(linesToRender);
        checkForLineModification(linesToRender);
        Movement::checkForShapeMovement(linesToRender);
    }
}
