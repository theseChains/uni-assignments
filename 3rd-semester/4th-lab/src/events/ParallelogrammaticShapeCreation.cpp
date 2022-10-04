#include "ParallelogrammaticShapeCreation.h"

template <typename ParallelogrammaticShape>
void Creation::checkForParallelogrammaticShapeCreation(
        std::array<std::unique_ptr<ParallelogrammaticShape>, 3>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        handleDefaultParallelogramCreation(shapesToRender[util::defaultShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        handleFirstConstructorParallelogramCreation(
                shapesToRender[util::firstConstructorShapeIndex]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
    {
        handleSecondConstructorParallelogramCreation(
                shapesToRender[util::secondConstructorShapeIndex]);
    }
    // deletion
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

template void Creation::checkForParallelogrammaticShapeCreation(
        std::array<std::unique_ptr<Rectangle>, 3>&);
template void Creation::checkForParallelogrammaticShapeCreation(
        std::array<std::unique_ptr<Rhombus>, 3>&);

template <typename ParallelogrammaticShape>
void Creation::createAndShowDefaultParallelogrammaticShape(
        std::unique_ptr<ParallelogrammaticShape>& newParallelogrammaticShapePtr)
{
    ParallelogrammaticShape defaultParallelogrammaticShape{};

    defaultParallelogrammaticShape.show();
    newParallelogrammaticShapePtr =
        std::make_unique<ParallelogrammaticShape>(defaultParallelogrammaticShape);
}

template <typename ParallelogrammaticShape>
ParallelogrammaticShape Creation::createFirstConstructorParallelogrammaticShape()
{
    float topLeftX{ rnd::getFloat(util::guiWidth, util::windowWidth - 100) };
    float topLeftY{ rnd::getFloat(0, util::windowHeight - 100) };
    float width{ rnd::getFloat(10, 100) };
    float height{ rnd::getFloat(10, 100) };

    Color parallelogramColor{ createRandomColor() };

    ParallelogrammaticShape firstConstructorParallelogrammaticShape{ topLeftX, topLeftY, width,
        height, sf::Color(parallelogramColor.m_redComponent, parallelogramColor.m_greenComponent,
            parallelogramColor.m_blueComponent) };

    return firstConstructorParallelogrammaticShape;
}

template <typename ParallelogrammaticShape>
ParallelogrammaticShape Creation::createSecondConstructorParallelogrammaticShape()
{
    float topLeftX{ rnd::getFloat(util::guiWidth, util::windowWidth - 100) };
    float topLeftY{ rnd::getFloat(0, util::windowHeight - 100) };
    float width{ rnd::getFloat(10, 100) };
    float height{ rnd::getFloat(10, 100) };

    Color parallelogramColor{ createRandomColor() };
    int alphaComponent{ rnd::getNumber(50, 255) };

    ParallelogrammaticShape secondConstructorParallelogrammaticShape{ topLeftX, topLeftY, width,
        height, std::array<int, 4>{
            parallelogramColor.m_redComponent, parallelogramColor.m_greenComponent,
            parallelogramColor.m_blueComponent, alphaComponent
        } };

    return secondConstructorParallelogrammaticShape;
}

template <typename ParallelogrammaticShape>
void Creation::handleDefaultParallelogramCreation(
        std::unique_ptr<ParallelogrammaticShape>& shapePtr)
{
    if (shapePtr != nullptr)
    {
        hideAndDeleteShape(shapePtr);
        createAndShowDefaultParallelogrammaticShape(shapePtr);
    }
    else
    {
        createAndShowDefaultParallelogrammaticShape(shapePtr);
    }
}

template <typename ParallelogrammaticShape>
void Creation::handleFirstConstructorParallelogramCreation(
        std::unique_ptr<ParallelogrammaticShape>& shapePtr)
{
    if (shapePtr != nullptr)
    {
        hideAndDeleteShape(shapePtr);
        ParallelogrammaticShape firstConstructorParallelogrammaticShape{
            createFirstConstructorParallelogrammaticShape<ParallelogrammaticShape>() };
        firstConstructorParallelogrammaticShape.show();
        shapePtr =
            std::make_unique<ParallelogrammaticShape>(firstConstructorParallelogrammaticShape);
    }
    else
    {
        ParallelogrammaticShape firstConstructorParallelogrammaticShape{
            createFirstConstructorParallelogrammaticShape<ParallelogrammaticShape>() };
        firstConstructorParallelogrammaticShape.show();
        shapePtr =
            std::make_unique<ParallelogrammaticShape>(firstConstructorParallelogrammaticShape);
    }
}

template <typename ParallelogrammaticShape>
void Creation::handleSecondConstructorParallelogramCreation(
        std::unique_ptr<ParallelogrammaticShape>& shapePtr)
{
    if (shapePtr != nullptr)
    {
        hideAndDeleteShape(shapePtr);
        ParallelogrammaticShape secondConstructorParallelogrammaticShape{
            createSecondConstructorParallelogrammaticShape<ParallelogrammaticShape>() };
        secondConstructorParallelogrammaticShape.show();
        shapePtr =
            std::make_unique<ParallelogrammaticShape>(secondConstructorParallelogrammaticShape);
    }
    else
    {
        ParallelogrammaticShape secondConstructorParallelogrammaticShape{
            createSecondConstructorParallelogrammaticShape<ParallelogrammaticShape>() };
        secondConstructorParallelogrammaticShape.show();
        shapePtr =
            std::make_unique<ParallelogrammaticShape>(secondConstructorParallelogrammaticShape);
    }
}
