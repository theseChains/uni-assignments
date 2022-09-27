#ifndef CIRCLE_PRIMITIVE_H
#define CIRCLE_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <array>
#include <iostream>
#include <optional>

#include "../util.h"

#include "Vertex.h"

class Circle
{
public:
    Circle();
    Circle(float topLeftX, float topLeftY, float radius, const sf::Color& color);
    Circle(float topLeftX, float topLeftY, float radius, const std::array<int, 4>& colorComponents);

    std::optional<sf::CircleShape> show(bool modifyVisibility = true);

    void moveTo(float offsetX, float offsetY);

    void changeRadius(float radiusOffset);

    bool isShown() const;

private:
    Vertex m_vertex{};

    float m_radius{};

    sf::Color m_color{};

    bool m_isShown{};

    // auxiliary
    sf::CircleShape createSprite();
    void checkForBounds();
};

#endif
