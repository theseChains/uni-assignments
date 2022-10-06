#include "Events.h"

void handleShapeArrayEvents(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (mode::all)
    {
        ArrayCreation::checkForShapeCreation(shapesToRender);
        ArrayCreation::checkForShapeDeletion(shapesToRender);
        Movement::checkForShapeArrayMovement(shapesToRender);
        checkForShapeArrayVisibilityModification(shapesToRender);
    }
    if (mode::circular)
    {
        Movement::checkForCircularShapeMovement(shapesToRender);
        Modification::checkForCircularShapeModification(shapesToRender);
        checkForCircularShapeArrayVisibilityModification(shapesToRender);
    }
    if (mode::quadrangular)
    {
        Movement::checkForQuadrangularShapeMovement(shapesToRender);
        checkForQuadrangularShapeArrayVisibilityModification(shapesToRender);
    }
}

void handleShapeListEvents(DynamicList<std::shared_ptr<Figure>>& shapesToRender)
{
    if (mode::all)
    {

    }
    if (mode::circular)
    {

    }
    if (mode::quadrangular)
    {

    }
}
