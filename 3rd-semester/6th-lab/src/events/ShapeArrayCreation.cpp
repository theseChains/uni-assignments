#include "ShapeArrayCreation.h"

void ArrayCreation::checkForShapeCreation(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        createRandomShapes(shapesToRender);
    }
}

void ArrayCreation::checkForShapeDeletion(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        deleteAllShapes(shapesToRender);
    }
}

void ArrayCreation::createRandomShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    for (auto& shape : shapesToRender)
    {
        int randomShapeIndex{ rnd::getNumber(1, 6) };

        switch (randomShapeIndex)
        {
            case util::circleIndex:
                shape = std::make_unique<Circle>(
                        Creation::createFirstConstructorCircularShape<Circle>());
                break;
            case util::rectangleIndex:
                shape = std::make_unique<Rectangle>(
                        Creation::createFirstConstructorParallelogrammaticShape<Rectangle>());
                break;
            case util::ellipseIndex:
                shape = std::make_unique<Ellipse>(
                        Creation::createFirstConstructorCircularShape<Ellipse>());
                break;
            case util::quadrangleIndex:
                shape = std::make_unique<Quadrangle>(
                        Creation::createFirstConstructorQuadrangle());
                break;
            case util::rhombusIndex:
                shape = std::make_unique<Rhombus>(
                        Creation::createFirstConstructorParallelogrammaticShape<Rhombus>());
                break;
            case util::trapezoidIndex:
                shape = std::make_unique<Trapezoid>(
                        Creation::createFirstConstructorTrapezoid());
                break;
            default:
                std::cout << "unknown shape index\n";
        }
    }
}

void ArrayCreation::deleteAllShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    for (auto& shape : shapesToRender)
    {
        Creation::hideAndDeleteShape(shape);
    }
}

void ListCreation::checkForShapeCreation(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        createRandomShapes(shapesToRender);
    }
}

void ListCreation::checkForShapeDeletion(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        deleteAllShapes(shapesToRender);
    }
}

void ListCreation::createRandomShapes(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    for (int i{ 0 }; i < 30; ++i)
    {
        int randomShapeIndex{ rnd::getNumber(1, 6) };

        switch (randomShapeIndex)
        {
            case util::circleIndex:
                shapesToRender.insert(std::make_unique<Circle>(
                        Creation::createFirstConstructorCircularShape<Circle>()));
                break;
            case util::rectangleIndex:
                shapesToRender.insert(std::make_unique<Rectangle>(
                        Creation::createFirstConstructorParallelogrammaticShape<Rectangle>()));
                break;
            case util::ellipseIndex:
                shapesToRender.insert(std::make_unique<Ellipse>(
                        Creation::createFirstConstructorCircularShape<Ellipse>()));
                break;
            case util::quadrangleIndex:
                shapesToRender.insert(std::make_unique<Quadrangle>(
                        Creation::createFirstConstructorQuadrangle()));
                break;
            case util::rhombusIndex:
                shapesToRender.insert(std::make_unique<Rhombus>(
                        Creation::createFirstConstructorParallelogrammaticShape<Rhombus>()));
                break;
            case util::trapezoidIndex:
                shapesToRender.insert(std::make_unique<Trapezoid>(
                        Creation::createFirstConstructorTrapezoid()));
                break;
            default:
                std::cout << "unknown shape index\n";
                break;
        }
    }
}

void ListCreation::deleteAllShapes(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
            temp != nullptr; temp = temp->m_next)
    {
        Creation::hideAndDeleteShape(temp->m_data);
    }
}
