#include "Events.h"

void handleShapeArrayEvents(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (container::array)
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
            Movement::checkForCircularShapeArrayMovement(shapesToRender);
            Modification::checkForCircularShapeArrayModification(shapesToRender);
            checkForCircularShapeArrayVisibilityModification(shapesToRender);
        }
        if (mode::quadrangular)
        {
            Movement::checkForQuadrangularShapeArrayMovement(shapesToRender);
            checkForQuadrangularShapeArrayVisibilityModification(shapesToRender);
        }
    }
}

void handleShapeListEvents(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (container::list)
    {
        if (mode::all)
        {
            ListCreation::checkForShapeCreation(shapesToRender);
            ListCreation::checkForShapeDeletion(shapesToRender);
            checkForShapeListVisibilityModification(shapesToRender);
            Movement::checkForShapeListMovement(shapesToRender);
        }
        if (mode::circular)
        {
            Movement::checkForCircularShapeListMovement(shapesToRender);
            Modification::checkForCircularShapeListModification(shapesToRender);
            checkForCircularShapeListVisibilityModification(shapesToRender);
        }
        if (mode::quadrangular)
        {
            Movement::checkForQuadrangularShapeListMovement(shapesToRender);
            checkForQuadrangularShapeListVisibilityModification(shapesToRender);
        }
    }
}
