#ifndef LINE_PRIMITIVE_H
#define LINE_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <array>
#include <iostream>
#include <optional>

#include "../util.h"

#include "Figure.h"
#include "Vertex.h"

class Line : public Figure
{
public:
    Line();
    Line(float mainPointX, float mainPointY, float length, const sf::Color& color);
    Line(float mainPointX, float mainPointY, float length, const std::array<int, 4>& colorComponents);

    ToShow show(bool modifyVisibility = true);

    void moveTo(float offsetX, float offsetY);

    void rotate(float angleOffset);

    bool isShown() const;

    sf::Color getColor() const;
    float getLength() const;

    void setPosition(float newX, float newY);
    void setColor(const sf::Color& color);

private:
    float m_length{};

    sf::Color m_color{};

    float m_angle{};

    bool m_isShown{};

    // auxiliary
    sf::RectangleShape createSprite() const;
    void checkForBounds();
};

#endif
