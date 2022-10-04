#ifndef QUADRANGLE_BASE_H
#define QUADRANGLE_BASE_H

#include <SFML/Graphics.hpp>

#include <array>
#include <iostream>
#include <optional>

#include "../util.h"

#include "Figure.h"
#include "Vertex.h"

class Quadrangle : public Figure
{
public:
    Quadrangle();
    Quadrangle(float mainPointX, float mainPointY, const sf::Color& color);
    Quadrangle(float mainPointX, float mainPointY, const std::array<int, 4>& colorComponents);
    Quadrangle(float mainPointX, float mainPointY, float secondPointX, float secondPointY,
            float thirdPointX, float thirdPointY, float fourthPointX, float fourthPointY,
            const sf::Color& color);
    Quadrangle(float mainPointX, float mainPointY, float secondPointX, float secondPointY,
            float thirdPointX, float thirdPointY, float fourthPointX, float fourthPointY,
            const std::array<int, 4>& colorComponents);

    ToShow show(bool modifyVisibility = true) override;

    //void moveTo(float offsetX, float offsetY) override;

    bool isShown() const;

    virtual ~Quadrangle() = default;

protected:
    // auxiliary
    sf::ConvexShape createSprite() const;
    // initializes second, third and fourth vertices
    void initializeRandomVertices();
};

#endif
