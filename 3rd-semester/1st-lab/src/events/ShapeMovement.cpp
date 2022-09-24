#include "ShapeMovement.h"

template <typename ShapeType>
void Movement::checkForShapeMovement(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        for (const auto& shape : shapesToRender)
        {
            if (shape.get() != nullptr)
            {
                shape->moveTo(0.0f, -2.0f);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        for (const auto& shape : shapesToRender)
        {
            if (shape.get() != nullptr)
            {
                shape->moveTo(-2.0f, 0.0f);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        for (const auto& shape : shapesToRender)
        {
            if (shape.get() != nullptr)
            {
                shape->moveTo(0.0f, 2.0f);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        for (const auto& shape : shapesToRender)
        {
            if (shape.get() != nullptr)
            {
                shape->moveTo(2.0f, 0.0f);
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        for (const auto& shape : shapesToRender)
        {
            if (shape.get() != nullptr)
            {
                float randomOffsetX{ rnd::getFloat(-50, 50) };
                float randomOffsetY{ rnd::getFloat(-50, 50) };
                
                shape->moveTo(randomOffsetX, randomOffsetY);
            }
        }
    }
}

template void Movement::checkForShapeMovement(std::array<std::unique_ptr<Circle>, 3>&);
template void Movement::checkForShapeMovement(std::array<std::unique_ptr<Rectangle>, 3>&);
template void Movement::checkForShapeMovement(std::array<std::unique_ptr<Line>, 3>&);

template <typename ShapeType>
void Movement::checkForShapeArrayMovement(VectorOfArrayOfShapePtrs<ShapeType>& shapeArraysToRender)
{
    for (auto& shapeArray : shapeArraysToRender)
    {
        Movement::checkForShapeMovement(shapeArray);
    }
}

template void Movement::checkForShapeArrayMovement(VectorOfArrayOfCirclePtrs&);
template void Movement::checkForShapeArrayMovement(VectorOfArrayOfRectanglePtrs&);
template void Movement::checkForShapeArrayMovement(VectorOfArrayOfLinePtrs&);
