#ifndef ELLIPSE_PRIMITIVE_H
#define ELLIPSE_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <iostream>

#include "Figure.h"
#include "Circle.h"

class Ellipse : public Circle
{
public:
    Ellipse();
    Ellipse(float topLeftX, float topLeftY, float radius, const sf::Color& color);
    Ellipse(float topLeftX, float topLeftY, float radius, const std::array<int, 4>& colorComponents);

    ToShow show(bool modifyVisibility = true) override;

    void rotateByNinetyDegrees();

private:
    // the second radius
    float m_semiaxis{};

    float m_angle{};

    sf::CircleShape createSprite() const;
};

#endif
