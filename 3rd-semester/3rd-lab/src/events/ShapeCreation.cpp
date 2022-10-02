#include "ShapeCreation.h"

// gonna have to do a lot here.. might make the same constructor for a trapezoid and a rhombus

// Ellipse and Circle shape creation
template <typename CircularShape>
void Creation::checkForCircularShapeCreation(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        handleDefaultCircularShapeCreation(shapesToRender[util::defaultShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        handleFirstConstructorCircularShapeCreation(shapesToRender[util::firstConstructorShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        handleSecondConstructorCircularShapeCreation(shapesToRender[util::secondConstructorShapeIndex]);
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

template void Creation::checkForCircularShapeCreation(std::array<std::unique_ptr<Circle>, 3>&);
template void Creation::checkForCircularShapeCreation(std::array<std::unique_ptr<Ellipse>, 3>&);

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

// Ellipse and Circle shape creation auxiliary functions and structs
struct CirclePointAndRadius
{
    float m_mainPointX{};
    float m_mainPointY{};
    float m_radius{};
};

struct Color
{
    int m_redComponent{};
    int m_greenComponent{};
    int m_blueComponent{};
};

CirclePointAndRadius createRandomPointAndRadius()
{
    float mainPointX{ rnd::getFloat(util::guiWidth, util::windowWidth - 100) };
    float mainPointY{ rnd::getFloat(0, util::windowHeight - 100) };
    float radius{ rnd::getFloat(10, 100) };

    return { mainPointX, mainPointY, radius };
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

template <typename CircularShape>
void Creation::createAndShowDefaultCircularShape(std::unique_ptr<CircularShape>& newShapePtr)
{
    CircularShape defaultShape{};

    defaultShape.show();
    newShapePtr = std::make_unique<CircularShape>(defaultShape);
}

template <typename CircularShape>
CircularShape Creation::createFirstConstructorCircularShape()
{
    CirclePointAndRadius circleShapePointAndRadius{ createRandomPointAndRadius() };
    Color circleColor{ createRandomColor() };

    CircularShape firstConstructorShape{ circleShapePointAndRadius.m_mainPointX,
        circleShapePointAndRadius.m_mainPointY, circleShapePointAndRadius.m_radius,
        sf::Color(circleColor.m_redComponent, circleColor.m_greenComponent,
        circleColor.m_blueComponent) };

    return firstConstructorShape;
}

template <typename CircularShape>
CircularShape Creation::createSecondConstructorCircularShape()
{
    CirclePointAndRadius circleShapePointAndRadius{ createRandomPointAndRadius() };
    Color circleColor{ createRandomColor() };
    int alphaComponent{ rnd::getNumber(50, 255) };

    CircularShape secondConstructorShape{ circleShapePointAndRadius.m_mainPointX,
        circleShapePointAndRadius.m_mainPointY, circleShapePointAndRadius.m_radius,
        std::array<int, 4>{ circleColor.m_redComponent, circleColor.m_greenComponent,
        circleColor.m_blueComponent, alphaComponent } };

    return secondConstructorShape;
}

template <typename CircularShape>
void Creation::handleDefaultCircularShapeCreation(std::unique_ptr<CircularShape>& shapePtr)
{
    if (shapePtr != nullptr)
    {
        hideAndDeleteShape(shapePtr);
        createAndShowDefaultCircularShape(shapePtr);
    }
    else
    {
        createAndShowDefaultCircularShape(shapePtr);
    }
}

template <typename CircularShape>
void Creation::handleFirstConstructorCircularShapeCreation(std::unique_ptr<CircularShape>& shapePtr)
{
    if (shapePtr != nullptr)
    {
        hideAndDeleteShape(shapePtr);
        CircularShape firstConstructorShape{ createFirstConstructorCircularShape<CircularShape>() };
        firstConstructorShape.show();
        shapePtr = std::make_unique<CircularShape>(firstConstructorShape);
    }
    else
    {
        CircularShape firstConstructorShape{ createFirstConstructorCircularShape<CircularShape>() };
        firstConstructorShape.show();
        shapePtr = std::make_unique<CircularShape>(firstConstructorShape);
    }
}

template <typename CircularShape>
void Creation::handleSecondConstructorCircularShapeCreation(std::unique_ptr<CircularShape>& shapePtr)
{
    if (shapePtr != nullptr)
    {
        hideAndDeleteShape(shapePtr);
        CircularShape secondConstructorShape{ createSecondConstructorCircularShape<CircularShape>() };
        secondConstructorShape.show();
        shapePtr = std::make_unique<CircularShape>(secondConstructorShape);
    }
    else
    {
        CircularShape secondConstructorShape{ createSecondConstructorCircularShape<CircularShape>() };
        secondConstructorShape.show();
        shapePtr = std::make_unique<CircularShape>(secondConstructorShape);
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
        sf::Color(rectangleColor.m_redComponent, rectangleColor.m_greenComponent,
            rectangleColor.m_blueComponent) };

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
        std::array<int, 4>{ rectangleColor.m_redComponent, rectangleColor.m_greenComponent,
            rectangleColor.m_blueComponent, alphaComponent } };

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
