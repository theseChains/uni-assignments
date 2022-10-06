#include "Events.h"

void handleShapeArrayEvents(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (mode::all)
    {
        ArrayCreation::checkForShapeCreation(shapesToRender);
        ArrayCreation::checkForShapeDeletion(shapesToRender);
        Movement::checkForShapeArrayMovement(shapesToRender);
        checkForShapeVisibilityModification(shapesToRender);
    }
    if (mode::circular)
    {
        Movement::checkForCircularShapeMovement(shapesToRender);
        Modification::checkForCircularShapeModification(shapesToRender);
        checkForCircularShapeVisibilityModification(shapesToRender);
    }
    if (mode::quadrangular)
    {
        Movement::checkForQuadrangularShapeMovement(shapesToRender);
        checkForQuadrangularShapeVisibilityModification(shapesToRender);
    }
}

void checkForShapeVisibilityModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        showAllShapes(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        hideAllShapes(shapesToRender);
    }
}

void checkForCircularShapeVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        showCircularShapes(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        hideCircularShapes(shapesToRender);
    }
}

void checkForQuadrangularShapeVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        showQuadrangularShapes(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        hideQuadrangularShapes(shapesToRender);
    }
}

void showAllShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape != nullptr && !shape->isShown())
        {
            shape->show();
        }
    }
}

void hideAllShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape != nullptr && shape->isShown())
        {
            shape->show();
        }
    }
}

void showCircularShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        Circle* circleShape{ dynamic_cast<Circle*>(shape.get()) };

        if (circleShape && !circleShape->isShown())
        {
            circleShape->show();
        }
    }
}

void hideCircularShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        Circle* circleShape{ dynamic_cast<Circle*>(shape.get()) };

        if (circleShape && circleShape->isShown())
        {
            circleShape->show();
        }
    }
}

void showQuadrangularShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        Quadrangle* quadrangularShape{ dynamic_cast<Quadrangle*>(shape.get()) };

        if (quadrangularShape && !quadrangularShape->isShown())
        {
            quadrangularShape->show();
        }
    }
}

void hideQuadrangularShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        Quadrangle* quadrangularShape{ dynamic_cast<Quadrangle*>(shape.get()) };

        if (quadrangularShape && quadrangularShape->isShown())
        {
            quadrangularShape->show();
        }
    }
}
