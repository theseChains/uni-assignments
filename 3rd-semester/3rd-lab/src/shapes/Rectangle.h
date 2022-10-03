#ifndef RECTANGLE_PRIMITIVE_H
#define RECTANGLE_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <array>
#include <iostream>
#include <optional>

#include "../util.h"

#include "Quadrangle.h"

class Rectangle : public Quadrangle 
{
public:
    Rectangle();
    Rectangle(float topLeftX, float topLeftY, float width, float height, const sf::Color& color);
    Rectangle(float topLeftX, float topLeftY, float width, float height,
            const std::array<int, 4>& colorComponents);

    ToShow show(bool modifyVisibility = true) override;

    void moveTo(float offsetX, float offsetY) override;

    void changeWidth(float widthOffset);
    void changeHeight(float heightOffset);

    float getWidth() const;
    float getHeight() const;
    sf::Color getColor() const;

    void setPosition(float newX, float newY);

private:
    float m_width{};
    float m_height{};

    // auxiliary
    sf::RectangleShape createSprite() const;
    void checkForBounds();
};

#endif
