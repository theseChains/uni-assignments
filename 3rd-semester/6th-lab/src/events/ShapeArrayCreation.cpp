#include "ShapeArrayCreation.h"

void ArrayCreation::checkForShapeCreation(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        createRandomShapes(shapesToRender);
    }
}

void ArrayCreation::checkForShapeDeletion(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        deleteAllShapes(shapesToRender);
    }
}

void ArrayCreation::createRandomShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    for (auto& shape : shapesToRender)
    {
        int randomShapeIndex{ rnd::getNumber(1, 6) };

        if (randomShapeIndex == util::circleIndex)
        {
            shape = std::make_unique<Circle>(
                    Creation::createFirstConstructorCircularShape<Circle>());
        }
        else if (randomShapeIndex == util::rectangleIndex)
        {
            shape = std::make_unique<Rectangle>(
                    Creation::createFirstConstructorParallelogrammaticShape<Rectangle>());
        }
        else if (randomShapeIndex == util::ellipseIndex)
        {
            shape = std::make_unique<Ellipse>(
                    Creation::createFirstConstructorCircularShape<Ellipse>());
        }
        else if (randomShapeIndex == util::quadrangleIndex)
        {
            shape = std::make_unique<Quadrangle>(
                    Creation::createFirstConstructorQuadrangle());
        }
        else if (randomShapeIndex == util::rhombusIndex)
        {
            shape = std::make_unique<Rhombus>(
                    Creation::createFirstConstructorParallelogrammaticShape<Rhombus>());
        }
        else if (randomShapeIndex == util::trapezoidIndex)
        {
            shape = std::make_unique<Trapezoid>(
                    Creation::createFirstConstructorTrapezoid());
        }
    }
}

void ArrayCreation::deleteAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    for (auto& shape : shapesToRender)
    {
        Creation::hideAndDeleteShape(shape);
    }
}
