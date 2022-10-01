#ifndef RECTANGLE_PRIMITIVE_H
#define RECTANGLE_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <array>
#include <iostream>
#include <optional>

#include "../util.h"

#include "Figure.h"
#include "Vertex.h"

class Rectangle : public Figure
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

    bool isShown() const;

    float getWidth() const;
    float getHeight() const;
    sf::Color getColor() const;

    void setPosition(float newX, float newY);

private:
    float m_width{};
    float m_height{};

    bool m_isShown{};

    // auxiliary
    sf::RectangleShape createSprite() const;
    void checkForBounds();
};

#endif
