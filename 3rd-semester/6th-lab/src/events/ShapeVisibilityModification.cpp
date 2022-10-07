#include "ShapeVisibilityModification.h"

void checkForShapeArrayVisibilityModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        for (auto& shape : shapesToRender)
        {
            showShape(shape);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        for (auto& shape : shapesToRender)
        {
            hideShape(shape);
        }
    }
}

void checkForShapeListVisibilityModification(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            showShape(temp->m_data);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            hideShape(temp->m_data);
        }
    }
}

void checkForCircularShapeArrayVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        for (auto& shape : shapesToRender)
        {
            showCircularShape(shape);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        for (auto& shape : shapesToRender)
        {
            hideCircularShape(shape);
        }
    }
}

void checkForCircularShapeListVisibilityModification(
        DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            showCircularShape(temp->m_data);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            hideCircularShape(temp->m_data);
        }
    }
}

void checkForQuadrangularShapeArrayVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        for (auto& shape : shapesToRender)
        {
            showQuadrangularShape(shape);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        for (auto& shape : shapesToRender)
        {
            hideQuadrangularShape(shape);
        }
    }
}

void checkForQuadrangularShapeListVisibilityModification(
        DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            showQuadrangularShape(temp->m_data);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            hideQuadrangularShape(temp->m_data);
        }
    }
}

void showShape(std::unique_ptr<Figure>& shape)
{
    if (shape != nullptr && !shape->isShown())
    {
        shape->show();
    }
}

void hideShape(std::unique_ptr<Figure>& shape)
{
    if (shape != nullptr && shape->isShown())
    {
        shape->show();
    }
}

void showCircularShape(std::unique_ptr<Figure>& shape)
{
    Circle* circularShape{ dynamic_cast<Circle*>(shape.get()) };

    if (circularShape && !circularShape->isShown())
    {
        circularShape->show();
    }
}

void hideCircularShape(std::unique_ptr<Figure>& shape)
{
    Circle* circularShape{ dynamic_cast<Circle*>(shape.get()) };

    if (circularShape && circularShape->isShown())
    {
        circularShape->show();
    }
}

void showQuadrangularShape(std::unique_ptr<Figure>& shape)
{
    Quadrangle* quadrangularShape{ dynamic_cast<Quadrangle*>(shape.get()) };

    if (quadrangularShape && !quadrangularShape->isShown())
    {
        quadrangularShape->show();
    }
}

void hideQuadrangularShape(std::unique_ptr<Figure>& shape)
{
    Quadrangle* quadrangularShape{ dynamic_cast<Quadrangle*>(shape.get()) };

    if (quadrangularShape && quadrangularShape->isShown())
    {
        quadrangularShape->show();
    }
}
