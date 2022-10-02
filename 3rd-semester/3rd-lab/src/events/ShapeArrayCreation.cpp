#include "ShapeArrayCreation.h"

template <typename CircularShape>
void ArrayCreation::checkForShapeArrayCreation(VectorOfArrayOfCircularShapePtrs<CircularShape>& arraysToRender)
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
template void ArrayCreation::checkForShapeArrayCreation(VectorOfArrayOfEllipsePtrs&);

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

template <typename CircularShape>
void ArrayCreation::handleShapeArrayCreation(VectorOfArrayOfCircularShapePtrs<CircularShape>& arraysToRender)
{
    CircularShape firstShape{};
    CircularShape secondShape{ Creation::createFirstConstructorCircularShape<CircularShape>() };
    CircularShape thirdShape{ Creation::createSecondConstructorCircularShape<CircularShape>() };

    firstShape.show();
    secondShape.show();
    thirdShape.show();

    // i think i have to construct this in-place, otherwise std::construct_at fails
    arraysToRender.push_back(std::array<std::unique_ptr<CircularShape>, 3>{
        std::make_unique<CircularShape>(firstShape),
        std::make_unique<CircularShape>(secondShape),
        std::make_unique<CircularShape>(thirdShape)
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
