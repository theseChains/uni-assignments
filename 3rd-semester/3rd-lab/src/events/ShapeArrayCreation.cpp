#include "ShapeArrayCreation.h"

template <typename CircularShape>
void ArrayCreation::checkForCircularShapeArrayCreation(
        VectorOfArrayOfCircularShapePtrs<CircularShape>& arraysToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        handleCircularShapeArrayCreation(arraysToRender);
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

template void ArrayCreation::checkForCircularShapeArrayCreation(VectorOfArrayOfCirclePtrs&);
template void ArrayCreation::checkForCircularShapeArrayCreation(VectorOfArrayOfEllipsePtrs&);

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

void ArrayCreation::checkForQuadrangleArrayCreation(
        VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        handleQuadrangleArrayCreation(quadrangleArraysToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
        if (!quadrangleArraysToRender.empty())
        {
            quadrangleArraysToRender.pop_back();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        quadrangleArraysToRender.clear();
    }
}

template <typename CircularShape>
void ArrayCreation::handleCircularShapeArrayCreation(
        VectorOfArrayOfCircularShapePtrs<CircularShape>& arraysToRender)
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

void ArrayCreation::handleQuadrangleArrayCreation(VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender)
{
    Quadrangle firstQuadrangle{};
    Quadrangle secondQuadrangle{ Creation::createFirstConstructorQuadrangle() };
    Quadrangle thirdQuadrangle{ Creation::createSecondConstructorQuadrangle() };

    firstQuadrangle.show();
    secondQuadrangle.show();
    thirdQuadrangle.show();

    quadrangleArraysToRender.push_back(std::array<std::unique_ptr<Quadrangle>, 3>{
            std::make_unique<Quadrangle>(firstQuadrangle),
            std::make_unique<Quadrangle>(secondQuadrangle),
            std::make_unique<Quadrangle>(thirdQuadrangle)
    });
}
