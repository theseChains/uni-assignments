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

template <typename ParallelogrammaticShape>
void ArrayCreation::checkForParallelogramArrayCreation(
        VectorOfArrayOfParalellogramShapePtrs<ParallelogrammaticShape>& parallelogramArraysToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        handleParallelogramArrayCreation(parallelogramArraysToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
        if (!parallelogramArraysToRender.empty())
        {
            parallelogramArraysToRender.pop_back();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        parallelogramArraysToRender.clear();
    }
}

template void ArrayCreation::checkForParallelogramArrayCreation(VectorOfArrayOfRectanglePtrs&);
template void ArrayCreation::checkForParallelogramArrayCreation(VectorOfArrayOfRhombusPtrs&);

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

template <typename ParallelogrammaticShape>
void ArrayCreation::handleParallelogramArrayCreation(
        VectorOfArrayOfParalellogramShapePtrs<ParallelogrammaticShape>& parallelogramArraysToRender)
{
    ParallelogrammaticShape firstParallelogram{};
    ParallelogrammaticShape secondParallelogram{
        Creation::createFirstConstructorParallelogrammaticShape<ParallelogrammaticShape>() };
    ParallelogrammaticShape thirdParallelogram{
        Creation::createSecondConstructorParallelogrammaticShape<ParallelogrammaticShape>() };

    firstParallelogram.show();
    secondParallelogram.show();
    thirdParallelogram.show();

    parallelogramArraysToRender.push_back(std::array<std::unique_ptr<ParallelogrammaticShape>, 3>{
        std::make_unique<ParallelogrammaticShape>(firstParallelogram),
        std::make_unique<ParallelogrammaticShape>(secondParallelogram),
        std::make_unique<ParallelogrammaticShape>(thirdParallelogram)
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
