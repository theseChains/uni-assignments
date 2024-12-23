#ifndef CIRCLE_PRIMITIVE_H
#define CIRCLE_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <array>
#include <iostream>
#include <optional>

#include "../util.h"

#include "Figure.h"
#include "Vertex.h"

class Circle : public Figure
{
public:
    Circle();
    Circle(float topLeftX, float topLeftY, float radius, const sf::Color& color);
    Circle(float topLeftX, float topLeftY, float radius, const std::array<int, 4>& colorComponents);

    ToShow show(bool modifyVisibility = true) override;

    void changeRadius(float radiusOffset);

    bool isShown() const;

    float getRadius() const;
    sf::Color getColor() const;

    void setPosition(float newX, float newY);
    void setColor(const sf::Color& color);
    void setRadius(float newRadius);

    virtual ~Circle() = default;

protected:
    float m_radius{};

    bool m_isShown{};

    // auxiliary
    sf::CircleShape createSprite() const;
    void checkForBounds();
};

#endif
