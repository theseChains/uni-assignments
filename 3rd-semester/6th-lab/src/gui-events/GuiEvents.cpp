#include "GuiEvents.h"

void guiHandleShapeArrayEvents(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (container::array)
    {
        if (mode::all)
        {
            GuiArrayCreation::checkForShapeArrayCreation(shapesToRender);
            GuiArrayCreation::checkForShapeArrayDeletion(shapesToRender);
            guiCheckForShapeArrayMovement(shapesToRender);
            guiCheckForShapeArrayVisibilityModification(shapesToRender);
        }
        if (mode::circular)
        {
            guiCheckForCircularShapeArrayMovement(shapesToRender);
            guiCheckForCircularShapeArrayModification(shapesToRender);
            guiCheckForCircularShapeArrayVisibilityModification(shapesToRender);
        }
        if (mode::quadrangular)
        {
            guiCheckForQuadrangularShapeArrayMovement(shapesToRender);
            guiCheckForQuadrangularShapeArrayVisibilityModification(shapesToRender);
        }
    }
}

void guiHandleShapeListEvents(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (container::list)
    {
        if (mode::all)
        {
            GuiArrayCreation::checkForShapeListCreation(shapesToRender);
            GuiArrayCreation::checkForShapeListDeletion(shapesToRender);
            guiCheckForShapeListMovement(shapesToRender);
            guiCheckForShapeListVisibilityModification(shapesToRender);
        }
        if (mode::circular)
        {
            guiCheckForCircularShapeListMovement(shapesToRender);
            guiCheckForCircularShapeListModification(shapesToRender);
            guiCheckForCircularShapeListVisibilityModification(shapesToRender);
        }
        if (mode::quadrangular)
        {
            guiCheckForQuadrangularShapeListMovement(shapesToRender);
            guiCheckForQuadrangularShapeListVisibilityModification(shapesToRender);
        }
    }
}
