#include "Events.h"

void handleShapeArrayEvents(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    if (mode::all)
    {
        ArrayCreation::checkForShapeCreation(shapesToRender);
        ArrayCreation::checkForShapeDeletion(shapesToRender);
        // showing
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            showAllShapes(shapesToRender);
        }
        // hiding
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
        {
            hideAllShapes(shapesToRender);
        }
        // deletion
        Movement::checkForShapeArrayMovement(shapesToRender);
    }
    if (mode::circular)
    {
        Movement::checkForCircularShapeMovement(shapesToRender);
    }
    if (mode::quadrangular)
    {
        Movement::checkForQuadrangularShapeMovement(shapesToRender);
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

void deleteAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    for (auto& shape : shapesToRender)
    {
        Creation::hideAndDeleteShape(shape);
    }
}

void showCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        Circle* circleShape{ dynamic_cast<Circle*>(shape.get()) };

        if (circleShape && (!circleShape->isShown()))
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
