#include "ShapeModification.h"

void Modification::checkForCircularShapeModification(
        std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        enlargeCircularShapes(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
        reduceCircularShapes(shapesToRender);
    }
}

void Modification::enlargeCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        Circle* circularShape{ dynamic_cast<Circle*>(shape.get()) };

        if (circularShape)
        {
            circularShape->changeRadius(2.0f);
        }
    }
}

void Modification::reduceCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        Circle* circularShape{ dynamic_cast<Circle*>(shape.get()) };

        if (circularShape)
        {
            circularShape->changeRadius(-2.0f);
        }
    }
}

