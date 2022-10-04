#ifndef RHOMBUS_PRIMITIVE_H
#define RHOMBUS_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <array>
#include <iostream>
#include <optional>

#include "../util.h"

#include "Quadrangle.h"

class Rhombus : public Quadrangle
{
public:
    Rhombus();
    Rhombus(float mainPointX, float mainPointY, float firstDiagonalLength,
            float secondDiagonalLength, const sf::Color& color);
    Rhombus(float mainPointX, float mainPointY, float firstDiagonalLength,
            float secondDiagonalLength, const std::array<int, 4>& colorComponents);

    ToShow show(bool modifyVisibility = true) override;

    void moveTo(float offsetX, float offsetY) override;

    void changeFirstDiagonal(float diagonalOffset);
    void changeSecondDiagonal(float diagonalOffset);

private:
    float m_firstDiagonalLength{};
    float m_secondDiagonalLength{};

    // auxiliary
    sf::ConvexShape createSprite() const;
};

#endif
