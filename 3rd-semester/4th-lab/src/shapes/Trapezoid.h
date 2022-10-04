#ifndef TRAPEZOID_PRIMITIVE_H
#define TRAPEZOID_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <array>
#include <iostream>
#include <optional>

#include "../util.h"

#include "Quadrangle.h"

class Trapezoid : public Quadrangle
{
public:
    Trapezoid();
    Trapezoid(float mainPointX, float mainPointY, float topBaseLength, float bottomBaseLength,
            float height, const sf::Color& color);
    Trapezoid(float mainPointX, float mainPointY, float topBaseLength, float bottomBaseLength,
            float height, const std::array<int, 4>& colorComponents);

    ToShow show(bool modifyVisibility = true) override;

    void changeTopBase(float baseOffset);
    void changeBottomBase(float baseOffset);
    void changeHeight(float heightOffset);

private:
    float m_topBaseLength{};
    float m_bottomBaseLength{};
    float m_height{};

    // auxiliary
    sf::ConvexShape createSprite() const;
};

#endif
