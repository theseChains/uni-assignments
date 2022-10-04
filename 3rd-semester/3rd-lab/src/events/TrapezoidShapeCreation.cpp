#include "TrapezoidShapeCreation.h"

void Creation::checkForTrapezoidShapeCreation(std::array<std::unique_ptr<Trapezoid>, 3>& trapezoidsToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        handleDefaultTrapezoidShapeCreation(trapezoidsToRender[util::defaultShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        handleFirstConstructorTrapezoidCreation(trapezoidsToRender[util::firstConstructorShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        handleSecondConstructorTrapezoidCreation(trapezoidsToRender[util::secondConstructorShapeIndex]);
    }
    // deletion
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        hideAndDeleteShape(trapezoidsToRender[util::defaultShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
    {
        hideAndDeleteShape(trapezoidsToRender[util::firstConstructorShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        hideAndDeleteShape(trapezoidsToRender[util::secondConstructorShapeIndex]);
    }
}

void Creation::createAndShowDefaultTrapezoid(std::unique_ptr<Trapezoid>& newTrapezoidPtr)
{
    Trapezoid defaultTrapezoid{};

    defaultTrapezoid.show();
    newTrapezoidPtr = std::make_unique<Trapezoid>(defaultTrapezoid);
}

struct TrapezoidProperties
{
    float m_mainX{};
    float m_mainY{};
    float m_topBaseLength{};
    float m_bottomBaseLength{};
    float m_height{};
};

TrapezoidProperties createRandomTrapezoidProperties()
{
    float mainX{ rnd::getFloat(util::guiWidth + 200, util::windowWidth - 200) };
    float mainY{ rnd::getFloat(0, util::windowHeight - 200) };
    float topBaseLength{ rnd::getFloat(20, 200) };
    float bottomBaseLength{ rnd::getFloat(20, 200) };
    float height{ rnd::getFloat(20, 200) };

    return { mainX, mainY, topBaseLength, bottomBaseLength, height };
}

Trapezoid Creation::createFirstConstructorTrapezoid()
{
    TrapezoidProperties properties{ createRandomTrapezoidProperties() };
    Color color{ createRandomColor() };

    Trapezoid mainConstructorTrapezoid{ properties.m_mainX, properties.m_mainY,
        properties.m_topBaseLength, properties.m_bottomBaseLength, properties.m_height,
        sf::Color(color.m_redComponent, color.m_greenComponent, color.m_blueComponent) };

    return mainConstructorTrapezoid;
}

Trapezoid Creation::createSecondConstructorTrapezoid()
{
    TrapezoidProperties properties{ createRandomTrapezoidProperties() };
    Color color{ createRandomColor() };

    int alphaComponent{ rnd::getNumber(50, 255) };

    Trapezoid secondConstructorTrapezoid{ properties.m_mainX, properties.m_mainY,
        properties.m_topBaseLength, properties.m_bottomBaseLength, properties.m_height,
        std::array{ color.m_redComponent, color.m_greenComponent, color.m_blueComponent,
            alphaComponent } };

    return secondConstructorTrapezoid;
}

void Creation::handleDefaultTrapezoidShapeCreation(std::unique_ptr<Trapezoid>& trapezoidPtr)
{
    if (trapezoidPtr != nullptr)
    {
        hideAndDeleteShape(trapezoidPtr);
        createAndShowDefaultTrapezoid(trapezoidPtr);
    }
    else
    {
        createAndShowDefaultTrapezoid(trapezoidPtr);
    }
}

void Creation::handleFirstConstructorTrapezoidCreation(std::unique_ptr<Trapezoid>& trapezoidPtr)
{
    if (trapezoidPtr != nullptr)
    {
        hideAndDeleteShape(trapezoidPtr);
        Trapezoid mainConstructorTrapezoid{ createFirstConstructorTrapezoid() };

        mainConstructorTrapezoid.show();
        trapezoidPtr = std::make_unique<Trapezoid>(mainConstructorTrapezoid);
    }
    else
    {
        Trapezoid mainConstructorTrapezoid{ createFirstConstructorTrapezoid() };

        mainConstructorTrapezoid.show();
        trapezoidPtr = std::make_unique<Trapezoid>(mainConstructorTrapezoid);
    }
}

void Creation::handleSecondConstructorTrapezoidCreation(std::unique_ptr<Trapezoid>& trapezoidPtr)
{
    if (trapezoidPtr != nullptr)
    {
        hideAndDeleteShape(trapezoidPtr);
        Trapezoid secondConstructorTrapezoid{ createSecondConstructorTrapezoid() };

        secondConstructorTrapezoid.show();
        trapezoidPtr = std::make_unique<Trapezoid>(secondConstructorTrapezoid);
    }
    else
    {
        Trapezoid secondConstructorTrapezoid{ createSecondConstructorTrapezoid() };

        secondConstructorTrapezoid.show();
        trapezoidPtr = std::make_unique<Trapezoid>(secondConstructorTrapezoid);
    }
}
