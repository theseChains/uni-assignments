#ifndef LINE_PRIMITIVE_H
#define LINE_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <array>
#include <vector>

#include "../util.h"

class Line
{
public:
    Line();
    Line(float mainPointX, float mainPointY, float length, const sf::Color& color);
    Line(float mainPointX, float mainPointY, float length, const std::array<int, 4>& colorComponents);

    void show(std::vector<sf::VertexArray>& linesToRender);

    void moveTo(float offsetX, float offsetY);

    void rotate(float angle);

    sf::RectangleShape getSprite() const;

    bool m_isShown{};

private:
    sf::RectangleShape m_sprite{};

    float m_mainPointX{};
    float m_mainPointY{};

    float m_length{};

    sf::Color m_color{};

    void initializeSfSprite();
};

#endif
