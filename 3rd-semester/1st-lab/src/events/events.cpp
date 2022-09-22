#include "events.h"

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

template <typename ShapeType>
void Creation::hideAndDelete(std::unique_ptr<ShapeType>& oldShapePtr)
{
    // hide the shape with another call to show() (not really necessary)
    oldShapePtr.get()->show();
    oldShapePtr.reset();
}

template <typename ShapeType>
void Creation::createAndShowDefaultShape(std::unique_ptr<ShapeType>& newShapePtr)
{
    ShapeType defaultShape{};
    defaultShape.show();
    newShapePtr = std::make_unique<ShapeType>(defaultShape);
}

struct Dimensions
{
    float mainPointX{};
    float mainPointY{};
    float size{};
};

struct Color
{
    int redComponent{};
    int greenComponent{};
    int blueComponent{};
};

Dimensions createRandomDimensions()
{
    float mainPointX{ rnd::getFloat(100, 540) };
    float mainPointY{ rnd::getFloat(100, 380) };
    float size{ rnd::getFloat(10, 100) };

    return { mainPointX, mainPointY, size };
}

Color createRandomColor()
{
    int redComponent{ rnd::getNumber(0, 255) };
    int greenComponent{ rnd::getNumber(0, 255) };
    int blueComponent{ rnd::getNumber(0, 255) };

    return { redComponent, greenComponent, blueComponent };
}

template <typename ShapeType>
void Creation::createAndShowFirstConstructorShape(std::unique_ptr<ShapeType>& newShapePtr)
{
    Dimensions shapeDimensions{ createRandomDimensions() };
    Color shapeColor{ createRandomColor() };
    
    ShapeType firstConstructorShape{ shapeDimensions.mainPointX, shapeDimensions.mainPointY,
        shapeDimensions.size, sf::Color(shapeColor.redComponent, shapeColor.greenComponent,
        shapeColor.blueComponent) };

    firstConstructorShape.show();
    newShapePtr = std::make_unique<ShapeType>(firstConstructorShape);
}

template <typename ShapeType>
void Creation::createAndShowSecondConstructorShape(std::unique_ptr<ShapeType>& newShapePtr)
{
    Dimensions shapeDimensions{ createRandomDimensions() };
    Color shapeColor{ createRandomColor() };
    int alphaComponent{ rnd::getNumber(50, 255) };

    ShapeType secondConstructorShape{ shapeDimensions.mainPointX, shapeDimensions.mainPointY,
        shapeDimensions.size, std::array<int, 4>{ shapeColor.redComponent,
        shapeColor.greenComponent, shapeColor.blueComponent, alphaComponent } };

    secondConstructorShape.show();
    newShapePtr = std::make_unique<ShapeType>(secondConstructorShape);
}

template <typename ShapeType>
void Creation::checkForShapeCreation(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        if (shapesToRender[util::defaultShapeIndex] != nullptr)
        {
            hideAndDelete(shapesToRender[util::defaultShapeIndex]);
            createAndShowDefaultShape(shapesToRender[util::defaultShapeIndex]);
        }
        else
        {
            createAndShowDefaultShape(shapesToRender[util::defaultShapeIndex]);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        if (shapesToRender[util::firstConstructorShapeIndex] != nullptr)
        {
            hideAndDelete(shapesToRender[util::firstConstructorShapeIndex]);
            createAndShowFirstConstructorShape(shapesToRender[util::firstConstructorShapeIndex]);
        }
        else
        {
            createAndShowFirstConstructorShape(shapesToRender[util::firstConstructorShapeIndex]);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        if (shapesToRender[util::secondConstructorShapeIndex] != nullptr)
        {
            hideAndDelete(shapesToRender[util::secondConstructorShapeIndex]);
            createAndShowSecondConstructorShape(shapesToRender[util::secondConstructorShapeIndex]);
        }
        else
        {
            createAndShowSecondConstructorShape(shapesToRender[util::secondConstructorShapeIndex]);
        }
    }
}

template void Creation::checkForShapeCreation(std::array<std::unique_ptr<Line>, 3>&);
template void Creation::checkForShapeCreation(std::array<std::unique_ptr<Circle>, 3>&);

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

void checkForLineModification(std::array<std::unique_ptr<Line>, 3>& linesToRender)
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
