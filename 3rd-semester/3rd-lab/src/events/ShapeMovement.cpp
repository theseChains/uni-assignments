#include "ShapeMovement.h"

template <typename ShapeType>
void Movement::checkForShapeMovement(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        moveShapeArrayUp(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        moveShapeArrayLeft(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        moveShapeArrayDown(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveShapeArrayRight(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        moveShapeArrayToRandomPoint(shapesToRender);
    }
}

template void Movement::checkForShapeMovement(std::array<std::unique_ptr<Circle>, 3>&);
template void Movement::checkForShapeMovement(std::array<std::unique_ptr<Rectangle>, 3>&);
template void Movement::checkForShapeMovement(std::array<std::unique_ptr<Line>, 3>&);
template void Movement::checkForShapeMovement(std::array<std::unique_ptr<Ellipse>, 3>&);

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
template void Movement::checkForShapeArrayMovement(VectorOfArrayOfEllipsePtrs&);

template <typename ShapeType>
void Movement::moveShapeArrayUp(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender)
{
    for (auto& shape : shapesToRender)
    {
        if (shape.get() != nullptr)
        {
            shape->moveTo(0.0f, -2.0f);
        }
    }
}

template <typename ShapeType>
void Movement::moveShapeArrayLeft(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender)
{
    for (auto& shape : shapesToRender)
    {
        if (shape.get() != nullptr)
        {
            shape->moveTo(-2.0f, 0.0f);
        }
    }
}

template <typename ShapeType>
void Movement::moveShapeArrayDown(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender)
{
    for (auto& shape : shapesToRender)
    {
        if (shape.get() != nullptr)
        {
            shape->moveTo(0.0f, 2.0f);
        }
    }
}

template <typename ShapeType>
void Movement::moveShapeArrayRight(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender)
{
    for (auto& shape : shapesToRender)
    {
        if (shape.get() != nullptr)
        {
            shape->moveTo(2.0f, 0.0f);
        }
    }
}

template <typename ShapeType>
void Movement::moveShapeArrayToRandomPoint(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender)
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
