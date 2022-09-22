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

void checkForLineShapeCreation(std::array<std::unique_ptr<Line>, 3>& linesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        if (linesToRender[0])
        {
            // hide if the object already exists
            linesToRender[0].get()->show();
            // remove the old object
            Line* linePtr{ linesToRender[0].release() }; 
            delete linePtr;
            // create the new object
            Line defaultLine{};
            defaultLine.show();
            linesToRender[0] = std::make_unique<Line>(defaultLine);
        }
        else
        {
            Line defaultLine{};
            defaultLine.show();
            linesToRender[0] = std::make_unique<Line>(defaultLine);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        if (linesToRender[1])
        {
            // hide if the object already exists
            linesToRender[1].get()->show();
            // remove the old object
            Line* linePtr{ linesToRender[1].release() };
            delete linePtr;
            // create the new object       
            Line firstConstructorLine{ 380.0f, 300.0f, 85.0f, sf::Color::White };
            firstConstructorLine.show();
            linesToRender[1] = std::make_unique<Line>(firstConstructorLine);
        }
        else
        {
            Line firstConstructorLine{ 380.0f, 300.0f, 85.0f, sf::Color::White };
            firstConstructorLine.show();
            linesToRender[1] = std::make_unique<Line>(firstConstructorLine);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        if (linesToRender[2])
        {
            // hide if the object already exists
            linesToRender[2].get()->show();
            // remove the old object
            Line* linePtr{ linesToRender[2].release() };
            delete linePtr;
            // create the new object
            Line secondConstructorLine{ 45.0f, 210.0f, 40.0f, util::secondLineColorComponents };
            secondConstructorLine.show();
            linesToRender[2] = std::make_unique<Line>(secondConstructorLine);
        }
        else
        {
            Line secondConstructorLine{ 45.0f, 210.0f, 40.0f, util::secondLineColorComponents };
            secondConstructorLine.show();
            linesToRender[2] = std::make_unique<Line>(secondConstructorLine);
        }
    }
    // i think i need to be able to create a random circle an infinite amount of times here..
    // what i have right now seems to be working but it's not quite how i would like it to work
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
