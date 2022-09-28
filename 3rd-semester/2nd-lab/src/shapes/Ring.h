#ifndef RING_PRIMITIVE_H
#define RING_PRIMITIVE_H

#include <array>
#include <iostream>
#include <optional>

#include "../util.h"

#include "Circle.h"

class Ring
{
public:
    Ring();
    Ring(float topLeftX, float topLeftY, float radius, const sf::Color& color);
    Ring(float topLeftX, float topLeftY, float radius, const std::array<int, 4>& colorComponents);

    struct OptCircles
    {
        std::optional<sf::CircleShape> outerCircle{};
        std::optional<sf::CircleShape> innerCircle{};
    };

    OptCircles show(bool modifyVisibility = true);

    void moveTo(float offsetX, float offsetY);

    bool isShown() const;

private:
    Circle m_outerCircle{};
    Circle m_innerCircle{};

    bool m_isShown{};

    // auxiliary
    sf::CircleShape createOuterCircleSprite() const;
    sf::CircleShape createInnerCircleSprite() const;
};

#endif
