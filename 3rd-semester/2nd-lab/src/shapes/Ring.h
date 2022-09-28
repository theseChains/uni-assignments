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
    Ring() = default;
    Ring(const Circle& outerCircle);
    Ring(const Circle& outerCircle, const Circle& innerCircle);

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
};

#endif
