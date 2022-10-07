#include "ShapeVisibilityModification.h"

void checkForShapeArrayVisibilityModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        showAllArrayShapes(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        hideAllArrayShapes(shapesToRender);
    }
}

void checkForCircularShapeArrayVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        showCircularArrayShapes(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        hideCircularArrayShapes(shapesToRender);
    }
}

void checkForQuadrangularShapeArrayVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        showQuadrangularArrayShapes(shapesToRender);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        hideQuadrangularArrayShapes(shapesToRender);
    }
}

void showAllArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape != nullptr && !shape->isShown())
        {
            shape->show();
        }
    }
}

void hideAllArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape != nullptr && shape->isShown())
        {
            shape->show();
        }
    }
}

void showCircularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    for (const auto& shapePtr : shapesToRender)
    {
        Circle* shape{ dynamic_cast<Circle*>(shapePtr.get()) };

        if (shape && !shape->isShown())
        {
            shape->show();
        }
    }
}

void hideCircularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    for (const auto& shapePtr : shapesToRender)
    {
        Circle* shape{ dynamic_cast<Circle*>(shapePtr.get()) };

        if (shape && shape->isShown())
        {
            shape->show();
        }
    }
}

void showQuadrangularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    for (const auto& shapePtr : shapesToRender)
    {
        Quadrangle* shape{ dynamic_cast<Quadrangle*>(shapePtr.get()) };

        if (shape && !shape->isShown())
        {
            shape->show();
        }
    }
}

void hideQuadrangularArrayShapes(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    for (const auto& shapePtr : shapesToRender)
    {
        Quadrangle* shape{ dynamic_cast<Quadrangle*>(shapePtr.get()) };

        if (shape && shape->isShown())
        {
            shape->show();
        }
    }
}

void checkForShapeListVisibilityModification(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{

}

void checkForSubShapeListVisibilityModification(
        DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{

}
