#include "Events.h"

void handleShapeArrayEvents(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
    {
        createRandomShapes(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        showAllShapes(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        hideAllShapes(shapesToRender);
    }
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        deleteAllShapes(shapesToRender);
    }
    if (mode::circular)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        {
            showCircularShapes(shapesToRender);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            hideCircularShapes(shapesToRender);
        }
    }
}

void createRandomShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
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

void showAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape != nullptr && !shape->isShown())
        {
            shape->show();
        }
    }
}

void hideAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape != nullptr && shape->isShown())
        {
            shape->show();
        }
    }
}

void moveAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender,
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

void deleteAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    for (auto& shape : shapesToRender)
    {
        Creation::hideAndDeleteShape(shape);
    }
}

void showCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        Circle* circleShape{ dynamic_cast<Circle*>(shape.get()) };

        if (circleShape && (!circleShape->isShown()))
        {
            circleShape->show();
        }
    }
}

void hideCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        Circle* circleShape{ dynamic_cast<Circle*>(shape.get()) };

        if (circleShape && circleShape->isShown())
        {
            circleShape->show();
        }
    }
}
