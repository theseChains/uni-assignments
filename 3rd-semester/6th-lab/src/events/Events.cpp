#include "Events.h"

void handleShapeArrayEvents(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
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

void checkForShapeVisibilityModification(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
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
        std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
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
        std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
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

void showAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape != nullptr && !shape->isShown())
        {
            shape->show();
        }
    }
}

void hideAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape != nullptr && shape->isShown())
        {
            shape->show();
        }
    }
}

void showCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
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

void hideCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
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

void showQuadrangularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
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

void hideQuadrangularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
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
