#include "ShapeMovement.h"

void Movement::checkForShapeArrayMovement(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        moveAllShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        moveAllShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        moveAllShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveAllShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        moveAllShapes(shapesToRender);
    }
}

void Movement::checkForCircularShapeMovement(
        std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        moveCircularShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        moveCircularShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        moveCircularShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveCircularShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        moveCircularShapes(shapesToRender);
    }
}

void Movement::checkForQuadrangularShapeMovement(
        std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        moveQuadrangularShapes(shapesToRender, 0.0f, -2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        moveQuadrangularShapes(shapesToRender, -2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        moveQuadrangularShapes(shapesToRender, 0.0f, 2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveQuadrangularShapes(shapesToRender, 2.0f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        moveQuadrangularShapes(shapesToRender);
    }
}

void Movement::moveAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender,
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

void Movement::moveCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender,
        float verticalDirection, float horizontalDirection)
{
    if (verticalDirection == 0.0f && horizontalDirection == 0.0f)
    {
        for (const auto& shape : shapesToRender)
        {
            Circle* circularShape{ dynamic_cast<Circle*>(shape.get()) };

            if (circularShape)
            {
                circularShape->moveTo(rnd::getFloat(-50, 50), rnd::getFloat(-50, 50));
            }
        }
    }
    else
    {
        for (const auto& shape : shapesToRender)
        {
            Circle* circularShape{ dynamic_cast<Circle*>(shape.get()) };

            if (circularShape)
            {
                circularShape->moveTo(verticalDirection, horizontalDirection);
            }
        }
    }
}

void Movement::moveQuadrangularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender,
        float verticalDirection, float horizontalDirection)
{
    if (verticalDirection == 0.0f && horizontalDirection == 0.0f)
    {
        for (const auto& shape : shapesToRender)
        {
            Quadrangle* quadrangularShape{ dynamic_cast<Quadrangle*>(shape.get()) };

            if (quadrangularShape)
            {
                quadrangularShape->moveTo(rnd::getFloat(-50, 50), rnd::getFloat(-50, 50));
            }
        }
    }
    else
    {
        for (const auto& shape : shapesToRender)
        {
            Quadrangle* quadrangularShape{ dynamic_cast<Quadrangle*>(shape.get()) };

            if (quadrangularShape)
            {
                quadrangularShape->moveTo(verticalDirection, horizontalDirection);
            }
        }
    }
}
