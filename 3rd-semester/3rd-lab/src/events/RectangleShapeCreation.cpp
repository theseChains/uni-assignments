#include "RectangleShapeCreation.h"

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
