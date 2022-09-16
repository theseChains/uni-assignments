#ifndef CIRCLE_PRIMITIVE_H
#define CIRCLE_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <algorithm>
#include <array>
#include <vector>

#include "../util.h"

class Circle
{
public:
    Circle();
    Circle(float centerX, float centerY, float radius, const sf::Color& color);
    Circle(float centerX, float centerY, float radius, const std::array<int, 4>& colorComponents);

    void show(std::vector<sf::CircleShape>& circlesToRender);

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
    void updateSfSprite();
};

#endif
