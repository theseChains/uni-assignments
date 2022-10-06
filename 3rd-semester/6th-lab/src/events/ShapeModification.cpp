#include "ShapeModification.h"

void Modification::checkForCircularShapeModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
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

void Modification::enlargeCircularShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
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

void Modification::reduceCircularShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
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

