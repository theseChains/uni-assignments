#include "ShapeModification.h"

void Modification::checkForCircularShapeArrayModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        enlargeCircularArrayShapes(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
        reduceCircularArrayShapes(shapesToRender);
    }
}

void Modification::checkForCircularShapeListModification(
        DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        enlargeCircularListShapes(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
        reduceCircularListShapes(shapesToRender);
    }
}

void Modification::enlargeCircularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
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

void Modification::reduceCircularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
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

void Modification::enlargeCircularListShapes(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
            temp != nullptr; temp = temp->m_next)
    {
        Circle* circularShape{ dynamic_cast<Circle*>(temp->m_data.get()) };

        if (circularShape)
        {
            circularShape->changeRadius(2.0f);
        }
    }
}

void Modification::reduceCircularListShapes(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
            temp != nullptr; temp = temp->m_next)
    {
        Circle* circularShape{ dynamic_cast<Circle*>(temp->m_data.get()) };

        if (circularShape)
        {
            circularShape->changeRadius(-2.0f);
        }
    }
}

