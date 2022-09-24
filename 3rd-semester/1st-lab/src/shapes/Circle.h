#ifndef CIRCLE_PRIMITIVE_H
#define CIRCLE_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <array>

#include "../util.h"

class Circle
{
public:
    Circle();
    Circle(float centerX, float centerY, float radius, const sf::Color& color);
    Circle(float centerX, float centerY, float radius, const std::array<int, 4>& colorComponents);

    void show();

    void moveTo(float offsetX, float offsetY);

    void changeRadius(float radiusOffset);

    sf::CircleShape getSprite() const;

    bool isShown() const;

private:
    sf::CircleShape m_sprite{};

    float m_centerX{};
    float m_centerY{};

    float m_radius{};

    sf::Color m_color{};

    bool m_isShown{};

    void initializeSfSprite();
    void updateSfSprite();
};

#endif
