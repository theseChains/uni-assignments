#ifndef CIRCLE_PRIMITIVE_H
#define CIRCLE_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#include "../util.h"

namespace component
{
    inline constexpr int red{ 0 };
    inline constexpr int green{ 1 };
    inline constexpr int blue{ 2 };
    inline constexpr int alpha{ 3 };
}

class Circle
{
public:
    Circle();
    Circle(float centerX, float centerY, float radius, const sf::Color& color);
    Circle(float centerX, float centerY, float radius, const std::array<int, 4>& colorComponents);

    void show(std::vector<sf::CircleShape>& shapesToRender);

    void moveTo(float newCenterX, float newCenterY);
    void changeRadius(float newRadius);

    sf::CircleShape getSprite() const;

    bool m_isShown{};

private:
    sf::CircleShape m_sprite{};

    float m_centerX{};
    float m_centerY{};
    
    float m_radius{};

    sf::Color m_color{};

    void initializeSfSprite();
};

#endif
