#include "ShapeCreation.h"

// Line and Circle shape creation
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
    float mainPointX{ rnd::getFloat(100, util::windowWidth - 100) };
    float mainPointY{ rnd::getFloat(100, util::windowHeight - 100) };
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

void hideAndDeleteRectangle(std::unique_ptr<Rectangle>& oldRectanglePtr)
{
    oldRectanglePtr.get()->show();
    oldRectanglePtr.reset();
}

void createAndShowDefaultRectangle(std::unique_ptr<Rectangle>& newRectanglePtr)
{
    Rectangle defaultRectangle{};
    
    defaultRectangle.show();
    newRectanglePtr = std::make_unique<Rectangle>(defaultRectangle);
}

void createAndShowFirstConstructorRectangle(std::unique_ptr<Rectangle>& newRectanglePtr)
{
    float topLeftX{ rnd::getFloat(100, util::windowWidth - 100) };
    float topLeftY{ rnd::getFloat(100, util::windowHeight - 100) };
    float width{ rnd::getFloat(10, 100) };
    float height{ rnd::getFloat(10, 100) };

    Color rectangleColor{ createRandomColor() };

    Rectangle firstConstructorRectangle{ topLeftX, topLeftY, width, height,
        sf::Color(rectangleColor.redComponent, rectangleColor.greenComponent, rectangleColor.blueComponent) };

    firstConstructorRectangle.show();
    newRectanglePtr = std::make_unique<Rectangle>(firstConstructorRectangle);
}

void createAndShowSecondConstructorRectangle(std::unique_ptr<Rectangle>& newRectanglePtr)
{
    float topLeftX{ rnd::getFloat(100, util::windowWidth - 100) };
    float topLeftY{ rnd::getFloat(100, util::windowHeight - 100) };
    float width{ rnd::getFloat(10, 100) };
    float height{ rnd::getFloat(10, 100) };

    Color rectangleColor{ createRandomColor() };
    int alphaComponent{ rnd::getNumber(50, 255) };

    Rectangle secondConstructorRectangle{ topLeftX, topLeftY, width, height, 
        std::array<int, 4>{ rectangleColor.redComponent, rectangleColor.greenComponent,
            rectangleColor.blueComponent, alphaComponent } };

    secondConstructorRectangle.show();
    newRectanglePtr = std::make_unique<Rectangle>(secondConstructorRectangle);
}

void checkForRectangleShapeCreation(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        if (rectanglesToRender[util::defaultShapeIndex] != nullptr)
        {
            hideAndDeleteRectangle(rectanglesToRender[util::defaultShapeIndex]);
            createAndShowDefaultRectangle(rectanglesToRender[util::defaultShapeIndex]);
        }
        else
        {
            createAndShowDefaultRectangle(rectanglesToRender[util::defaultShapeIndex]);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        if (rectanglesToRender[util::firstConstructorShapeIndex] != nullptr)
        {
            hideAndDeleteRectangle(rectanglesToRender[util::firstConstructorShapeIndex]);
            createAndShowFirstConstructorRectangle(rectanglesToRender[util::firstConstructorShapeIndex]); 
        }
        else
        {
            createAndShowFirstConstructorRectangle(rectanglesToRender[util::firstConstructorShapeIndex]);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        if (rectanglesToRender[util::secondConstructorShapeIndex] != nullptr)
        {
            hideAndDeleteRectangle(rectanglesToRender[util::secondConstructorShapeIndex]);
            createAndShowSecondConstructorRectangle(rectanglesToRender[util::secondConstructorShapeIndex]);
        }
        else
        {
            createAndShowSecondConstructorRectangle(rectanglesToRender[util::secondConstructorShapeIndex]);
        }
    }
}
