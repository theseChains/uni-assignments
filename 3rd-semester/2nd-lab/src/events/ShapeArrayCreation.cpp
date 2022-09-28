#include "ShapeArrayCreation.h"

template <typename ShapeType>
void ArrayCreation::checkForShapeArrayCreation(VectorOfArrayOfShapePtrs<ShapeType>& arraysToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        handleShapeArrayCreation(arraysToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
        if (!arraysToRender.empty())
        {
            arraysToRender.pop_back();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        arraysToRender.clear();
    }
}

template void ArrayCreation::checkForShapeArrayCreation(VectorOfArrayOfCirclePtrs&);
template void ArrayCreation::checkForShapeArrayCreation(VectorOfArrayOfLinePtrs&);
template void ArrayCreation::checkForShapeArrayCreation(VectorOfArrayOfRingPtrs&);

void ArrayCreation::checkForRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        handleRectangleArrayCreation(rectangleArraysToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
        if (!rectangleArraysToRender.empty())
        {
            rectangleArraysToRender.pop_back();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        rectangleArraysToRender.clear();
    }
}

template <typename ShapeType>
void ArrayCreation::handleShapeArrayCreation(VectorOfArrayOfShapePtrs<ShapeType>& arraysToRender)
{
    ShapeType firstShape{};
    ShapeType secondShape{ Creation::createFirstConstructorShape<ShapeType>() };
    ShapeType thirdShape{ Creation::createSecondConstructorShape<ShapeType>() };

    firstShape.show();
    secondShape.show();
    thirdShape.show();

    // i think i have to construct this in-place, otherwise std::construct_at fails
    arraysToRender.push_back(std::array<std::unique_ptr<ShapeType>, 3>{
        std::make_unique<ShapeType>(firstShape),
        std::make_unique<ShapeType>(secondShape),
        std::make_unique<ShapeType>(thirdShape)
    });
}

void ArrayCreation::handleRectangleArrayCreation(VectorOfArrayOfRectanglePtrs& rectangleArraysToRender)
{
    Rectangle firstRectangle{};
    Rectangle secondRectangle{ Creation::createFirstConstructorRectangle() };
    Rectangle thirdRectangle{ Creation::createSecondConstructorRectangle() };

    firstRectangle.show();
    secondRectangle.show();
    thirdRectangle.show();

    rectangleArraysToRender.push_back(std::array<std::unique_ptr<Rectangle>, 3>{
        std::make_unique<Rectangle>(firstRectangle),
        std::make_unique<Rectangle>(secondRectangle),
        std::make_unique<Rectangle>(thirdRectangle)
    });
}
