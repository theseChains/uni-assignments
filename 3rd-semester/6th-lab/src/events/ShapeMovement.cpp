#include "ShapeMovement.h"

void Movement::checkForShapeArrayMovement(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        moveAllArrayShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        moveAllArrayShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        moveAllArrayShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveAllArrayShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        moveAllArrayShapes(shapesToRender);
    }
}

void Movement::checkForCircularShapeArrayMovement(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        moveCircularArrayShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        moveCircularArrayShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        moveCircularArrayShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveCircularArrayShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        moveCircularArrayShapes(shapesToRender);
    }
}

void Movement::checkForQuadrangularShapeArrayMovement(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        moveQuadrangularArrayShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        moveQuadrangularArrayShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        moveQuadrangularArrayShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveQuadrangularArrayShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        moveQuadrangularArrayShapes(shapesToRender);
    }
}

void Movement::checkForShapeListMovement(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        moveAllListShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        moveAllListShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        moveAllListShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveAllListShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        moveAllListShapes(shapesToRender);
    }
}

void Movement::checkForCircularShapeListMovement(
        DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        moveCircularListShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        moveCircularListShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        moveCircularListShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveCircularListShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        moveCircularListShapes(shapesToRender);
    }
}

void Movement::checkForQuadrangularShapeListMovement(
        DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        moveQuadrangularListShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        moveQuadrangularListShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        moveQuadrangularListShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveQuadrangularListShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        moveQuadrangularListShapes(shapesToRender);
    }
}

void Movement::moveAllArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender,
        float verticalDirection, float horizontalDirection)
{
    if (verticalDirection == 0.0f && horizontalDirection == 0.0f)
    {
        for (const auto& shape : shapesToRender)
        {
            if (shape != nullptr)
            {
                shape->moveTo(rnd::getFloat(-50, 50), rnd::getFloat(-50, 50));
            }
        }
    }
    else
    {
        for (const auto& shape : shapesToRender)
        {
            if (shape != nullptr)
            {
                shape->moveTo(verticalDirection, horizontalDirection);
            }
        }
    }
}

void Movement::moveCircularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender,
        float verticalDirection, float horizontalDirection)
{
    if (verticalDirection == 0.0f && horizontalDirection == 0.0f)
    {
        for (const auto& shape : shapesToRender)
        {
            Circle* circularArrayShape{ dynamic_cast<Circle*>(shape.get()) };

            if (circularArrayShape)
            {
                circularArrayShape->moveTo(rnd::getFloat(-50, 50), rnd::getFloat(-50, 50));
            }
        }
    }
    else
    {
        for (const auto& shape : shapesToRender)
        {
            Circle* circularArrayShape{ dynamic_cast<Circle*>(shape.get()) };

            if (circularArrayShape)
            {
                circularArrayShape->moveTo(verticalDirection, horizontalDirection);
            }
        }
    }
}

void Movement::moveQuadrangularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender,
        float verticalDirection, float horizontalDirection)
{
    if (verticalDirection == 0.0f && horizontalDirection == 0.0f)
    {
        for (const auto& shape : shapesToRender)
        {
            Quadrangle* quadrangularArrayShape{ dynamic_cast<Quadrangle*>(shape.get()) };

            if (quadrangularArrayShape)
            {
                quadrangularArrayShape->moveTo(rnd::getFloat(-50, 50), rnd::getFloat(-50, 50));
            }
        }
    }
    else
    {
        for (const auto& shape : shapesToRender)
        {
            Quadrangle* quadrangularArrayShape{ dynamic_cast<Quadrangle*>(shape.get()) };

            if (quadrangularArrayShape)
            {
                quadrangularArrayShape->moveTo(verticalDirection, horizontalDirection);
            }
        }
    }
}

void Movement::moveAllListShapes(DynamicList<std::unique_ptr<Figure>>& shapesToRender,
        float verticalDirection, float horizontalDirection)
{
    if (verticalDirection == 0.0f && horizontalDirection == 0.0f)
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            if (temp->m_data != nullptr)
            {
                temp->m_data->moveTo(rnd::getFloat(-50, 50), rnd::getFloat(-50, 50));
            }
        }
    }
    else
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            if (temp->m_data != nullptr)
            {
                temp->m_data->moveTo(verticalDirection, horizontalDirection);
            }
        }
    }
}

void Movement::moveCircularListShapes(DynamicList<std::unique_ptr<Figure>>& shapesToRender,
        float verticalDirection, float horizontalDirection)
{
    if (verticalDirection == 0.0f && horizontalDirection == 0.0f)
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            Circle* circularListShape{ dynamic_cast<Circle*>(temp->m_data.get()) };

            if (circularListShape)
            {
                circularListShape->moveTo(rnd::getFloat(-50, 50), rnd::getFloat(-50, 50));
            }
        }
    }
    else
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            Circle* circularListShape{ dynamic_cast<Circle*>(temp->m_data.get()) };

            if (circularListShape)
            {
                circularListShape->moveTo(verticalDirection, horizontalDirection);
            }
        }
    }
}

void Movement::moveQuadrangularListShapes(DynamicList<std::unique_ptr<Figure>>& shapesToRender,
        float verticalDirection, float horizontalDirection)
{
    if (verticalDirection == 0.0f && horizontalDirection == 0.0f)
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            Quadrangle* quadrangularListShape{ dynamic_cast<Quadrangle*>(temp->m_data.get()) };

            if (quadrangularListShape)
            {
                quadrangularListShape->moveTo(rnd::getFloat(-50, 50), rnd::getFloat(-50, 50));
            }
        }
    }
    else
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            Quadrangle* quadrangularListShape{ dynamic_cast<Quadrangle*>(temp->m_data.get()) };

            if (quadrangularListShape)
            {
                quadrangularListShape->moveTo(verticalDirection, horizontalDirection);
            }
        }
    }
}
