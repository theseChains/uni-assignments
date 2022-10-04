#include "CircularShapeCreation.h"

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

// Ellipse and Circle shape creation auxiliary functions
struct CirclePointAndRadius
{
    float m_mainPointX{};
    float m_mainPointY{};
    float m_radius{};
};

CirclePointAndRadius createRandomPointAndRadius()
{
    float mainPointX{ rnd::getFloat(util::guiWidth, util::windowWidth - 100) };
    float mainPointY{ rnd::getFloat(0, util::windowHeight - 100) };
    float radius{ rnd::getFloat(10, 100) };

    return { mainPointX, mainPointY, radius };
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
