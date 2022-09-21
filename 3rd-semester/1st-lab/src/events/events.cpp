#include "events.h"

void checkForCircleShapeCreation(std::vector<std::unique_ptr<Circle>>& circlesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        Circle defaultCircle{};
        defaultCircle.show(circlesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        Circle firstConstructorCircle{ 120.0f, 40.0f, 90.0f, sf::Color::Yellow };
        firstConstructorCircle.show(circlesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        Circle secondConstructorCircle{ 200.0f, 130.0f, 120.0f, util::secondCircleColorComponents };
        secondConstructorCircle.show(circlesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        
    }
}

void checkForRectangleShapeCreation(std::vector<std::unique_ptr<Rectangle>>& rectanglesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        Rectangle defaultRectangle{};
        defaultRectangle.show(rectanglesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        Rectangle firstConstructorRectangle{ 55.0f, 95.0f, 100.0f, 80.0f, sf::Color::Green };
        firstConstructorRectangle.show(rectanglesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        Rectangle secondConstructorRectangle{ 490.0f, 200.0f, 70.0f, 130.0f, util::secondRectangleColorComponents };
        secondConstructorRectangle.show(rectanglesToRender);
    }
}

void checkForLineShapeCreation(std::vector<std::unique_ptr<Line>>& linesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        Line defaultLine{};
        defaultLine.show(linesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        Line firstConstructorLine{ 380.0f, 300.0f, 85.0f, sf::Color::White };
        firstConstructorLine.show(linesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        Line secondConstructorLine{ 45.0f, 210.0f, 40.0f, util::secondLineColorComponents };
        secondConstructorLine.show(linesToRender);
    }
}

void checkForCircleModification(std::vector<std::unique_ptr<Circle>>& circlesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
    {
        for (const auto& circle : circlesToRender)
        {
            circle->changeRadius(2.0f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
    {
        for (const auto& circle : circlesToRender)
        {
            circle->changeRadius(-2.0f);
        }
    }
}

void checkForRectangleModification(std::vector<std::unique_ptr<Rectangle>>& rectanglesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        for (const auto& rectangle : rectanglesToRender)
        {
            rectangle->changeHeight(-2.0f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        for (const auto& rectangle : rectanglesToRender)
        {
            rectangle->changeWidth(-2.0f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        for (const auto& rectangle : rectanglesToRender)
        {
            rectangle->changeHeight(2.0f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        for (const auto& rectangle : rectanglesToRender)
        {
            rectangle->changeWidth(2.0f);
        }
    }
}

void checkForLineModification(std::vector<std::unique_ptr<Line>>& linesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        for (const auto& line : linesToRender)
        {
            line->rotate(2.0f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
    {
        for (const auto& line : linesToRender)
        {
            line->rotate(-2.0f);
        }
    }
}

template <typename ShapeType>
void Movement::checkForShapeMovement(std::vector<std::unique_ptr<ShapeType>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        for (const auto& shape : shapesToRender)
        {
            shape->moveTo(0.0f, -2.0f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        for (const auto& shape : shapesToRender)
        {
            shape->moveTo(-2.0f, 0.0f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        for (const auto& shape : shapesToRender)
        {
            shape->moveTo(0.0f, 2.0f);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        for (const auto& shape : shapesToRender)
        {
            shape->moveTo(2.0f, 0.0f);
        }
    }
}

template void Movement::checkForShapeMovement(std::vector<std::unique_ptr<Circle>>&);
template void Movement::checkForShapeMovement(std::vector<std::unique_ptr<Rectangle>>&);
template void Movement::checkForShapeMovement(std::vector<std::unique_ptr<Line>>&);
