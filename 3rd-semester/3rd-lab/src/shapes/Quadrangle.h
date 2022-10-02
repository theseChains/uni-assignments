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
    Quadrangle(float mainPointX, float mainPointY, float secondPointX, float secondPointY,
            float thirdPointX, float thirdPointY, float fourthPointX, float fourthPointY,
            const sf::Color& color);
    Quadrangle(float mainPointX, float mainPointY, float secondPointX, float secondPointY,
            float thirdPointX, float thirdPointY, float fourthPointX, float fourthPointY,
            const std::array<int, 4>& colorComponents);

    ToShow show(bool modifyVisibility = true) override;

    void moveTo(float offsetX, float offsetY) override;

    bool isShown() const;

protected:
    Vertex m_secondVertex{};
    Vertex m_thirdVertex{};
    Vertex m_fourthVertex{};

    sf::Color m_color{};

    // initializes second, third and fourth vertices
    void initializeVertices();
};

#endif
