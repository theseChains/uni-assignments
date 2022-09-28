#include "ShapeCreation.h"

// Line and Circle shape creation
template <typename ShapeType>
void Creation::checkForShapeCreation(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        handleDefaultShapeCreation(shapesToRender[util::defaultShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        handleFirstConstructorShapeCreation(shapesToRender[util::firstConstructorShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        handleSecondConstructorShapeCreation(shapesToRender[util::secondConstructorShapeIndex]);
    }
    // also put the deletion here, too lazy to move this somewhere else
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        hideAndDeleteShape(shapesToRender[util::defaultShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
    {
        hideAndDeleteShape(shapesToRender[util::firstConstructorShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        hideAndDeleteShape(shapesToRender[util::secondConstructorShapeIndex]);
    }
}

template void Creation::checkForShapeCreation(std::array<std::unique_ptr<Line>, 3>&);
template void Creation::checkForShapeCreation(std::array<std::unique_ptr<Circle>, 3>&);
template void Creation::checkForShapeCreation(std::array<std::unique_ptr<Ring>, 3>&);

// Rectangle shape creation
void Creation::checkForRectangleShapeCreation(std::array<std::unique_ptr<Rectangle>, 3>& rectanglesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        handleDefaultRectangleCreation(rectanglesToRender[util::defaultShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        handleFirstConstructorRectangleCreation(rectanglesToRender[util::firstConstructorShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        handleSecondConstructorRectangleCreation(rectanglesToRender[util::secondConstructorShapeIndex]);
    }
    // deletion
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        hideAndDeleteShape(rectanglesToRender[util::defaultShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
    {
        hideAndDeleteShape(rectanglesToRender[util::firstConstructorShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        hideAndDeleteShape(rectanglesToRender[util::secondConstructorShapeIndex]);
    }
}

// Line and Circle shape creation auxiliary functions and structs
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
    float mainPointX{ rnd::getFloat(util::guiWidth, util::windowWidth - 100) };
    float mainPointY{ rnd::getFloat(0, util::windowHeight - 100) };
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
void Creation::hideAndDeleteShape(std::unique_ptr<ShapeType>& oldShapePtr)
{
    // hide the shape with another call to show() (not really necessary but the assignment says so)
    if (oldShapePtr.get() != nullptr)
    {
        oldShapePtr.get()->show();
        oldShapePtr.reset();
    }
}

template <typename ShapeType>
void Creation::createAndShowDefaultShape(std::unique_ptr<ShapeType>& newShapePtr)
{
    ShapeType defaultShape{};

    defaultShape.show();
    newShapePtr = std::make_unique<ShapeType>(defaultShape);
}

template <typename ShapeType>
ShapeType Creation::createFirstConstructorShape()
{
    Dimensions shapeDimensions{ createRandomDimensions() };
    Color shapeColor{ createRandomColor() };

    ShapeType firstConstructorShape{ shapeDimensions.mainPointX, shapeDimensions.mainPointY,
        shapeDimensions.size, sf::Color(shapeColor.redComponent, shapeColor.greenComponent,
        shapeColor.blueComponent) };

    return firstConstructorShape;
}

template <typename ShapeType>
ShapeType Creation::createSecondConstructorShape()
{
    Dimensions shapeDimensions{ createRandomDimensions() };
    Color shapeColor{ createRandomColor() };
    int alphaComponent{ rnd::getNumber(50, 255) };

    ShapeType secondConstructorShape{ shapeDimensions.mainPointX, shapeDimensions.mainPointY,
        shapeDimensions.size, std::array<int, 4>{ shapeColor.redComponent,
        shapeColor.greenComponent, shapeColor.blueComponent, alphaComponent } };

    return secondConstructorShape;
}

template <typename ShapeType>
void Creation::handleDefaultShapeCreation(std::unique_ptr<ShapeType>& shapePtr)
{
    if (shapePtr != nullptr)
    {
        hideAndDeleteShape(shapePtr);
        createAndShowDefaultShape(shapePtr);
    }
    else
    {
        createAndShowDefaultShape(shapePtr);
    }
}

template <typename ShapeType>
void Creation::handleFirstConstructorShapeCreation(std::unique_ptr<ShapeType>& shapePtr)
{
    if (shapePtr != nullptr)
    {
        hideAndDeleteShape(shapePtr);
        ShapeType firstConstructorShape{ createFirstConstructorShape<ShapeType>() };
        firstConstructorShape.show();
        shapePtr = std::make_unique<ShapeType>(firstConstructorShape);
    }
    else
    {
        ShapeType firstConstructorShape{ createFirstConstructorShape<ShapeType>() };
        firstConstructorShape.show();
        shapePtr = std::make_unique<ShapeType>(firstConstructorShape);
    }
}

template <typename ShapeType>
void Creation::handleSecondConstructorShapeCreation(std::unique_ptr<ShapeType>& shapePtr)
{
    if (shapePtr != nullptr)
    {
        hideAndDeleteShape(shapePtr);
        ShapeType secondConstructorShape{ createSecondConstructorShape<ShapeType>() };
        secondConstructorShape.show();
        shapePtr = std::make_unique<ShapeType>(secondConstructorShape);
    }
    else
    {
        ShapeType secondConstructorShape{ createSecondConstructorShape<ShapeType>() };
        secondConstructorShape.show();
        shapePtr = std::make_unique<ShapeType>(secondConstructorShape);
    }
}

// rectangle creation auxiliary functions
void Creation::createAndShowDefaultRectangle(std::unique_ptr<Rectangle>& newRectanglePtr)
{
    Rectangle defaultRectangle{};

    defaultRectangle.show();
    newRectanglePtr = std::make_unique<Rectangle>(defaultRectangle);
}

Rectangle Creation::createFirstConstructorRectangle()
{
    float topLeftX{ rnd::getFloat(util::guiWidth, util::windowWidth - 100) };
    float topLeftY{ rnd::getFloat(0, util::windowHeight - 100) };
    float width{ rnd::getFloat(10, 100) };
    float height{ rnd::getFloat(10, 100) };

    Color rectangleColor{ createRandomColor() };

    Rectangle firstConstructorRectangle{ topLeftX, topLeftY, width, height,
        sf::Color(rectangleColor.redComponent, rectangleColor.greenComponent,
            rectangleColor.blueComponent) };

    return firstConstructorRectangle;
}

Rectangle Creation::createSecondConstructorRectangle()
{
    float topLeftX{ rnd::getFloat(util::guiWidth, util::windowWidth - 100) };
    float topLeftY{ rnd::getFloat(0, util::windowHeight - 100) };
    float width{ rnd::getFloat(10, 100) };
    float height{ rnd::getFloat(10, 100) };

    Color rectangleColor{ createRandomColor() };
    int alphaComponent{ rnd::getNumber(50, 255) };

    Rectangle secondConstructorRectangle{ topLeftX, topLeftY, width, height,
        std::array<int, 4>{ rectangleColor.redComponent, rectangleColor.greenComponent,
            rectangleColor.blueComponent, alphaComponent } };

    return secondConstructorRectangle;
}


void Creation::handleDefaultRectangleCreation(std::unique_ptr<Rectangle>& rectanglePtr)
{
    if (rectanglePtr != nullptr)
    {
        hideAndDeleteShape(rectanglePtr);
        createAndShowDefaultRectangle(rectanglePtr);
    }
    else
    {
        createAndShowDefaultRectangle(rectanglePtr);
    }
}

void Creation::handleFirstConstructorRectangleCreation(std::unique_ptr<Rectangle>& rectanglePtr)
{
    if (rectanglePtr != nullptr)
    {
        hideAndDeleteShape(rectanglePtr);
        Rectangle firstConstructorRectangle{ createFirstConstructorRectangle() };
        firstConstructorRectangle.show();
        rectanglePtr = std::make_unique<Rectangle>(firstConstructorRectangle);
    }
    else
    {
        Rectangle firstConstructorRectangle{ createFirstConstructorRectangle() };
        firstConstructorRectangle.show();
        rectanglePtr = std::make_unique<Rectangle>(firstConstructorRectangle);
    }
}

void Creation::handleSecondConstructorRectangleCreation(std::unique_ptr<Rectangle>& rectanglePtr)
{
    if (rectanglePtr != nullptr)
    {
        hideAndDeleteShape(rectanglePtr);
        Rectangle secondConstructorRectangle{ createSecondConstructorRectangle() };
        secondConstructorRectangle.show();
        rectanglePtr = std::make_unique<Rectangle>(secondConstructorRectangle);
    }
    else
    {
        Rectangle secondConstructorRectangle{ createSecondConstructorRectangle() };
        secondConstructorRectangle.show();
        rectanglePtr = std::make_unique<Rectangle>(secondConstructorRectangle);
    }
}
