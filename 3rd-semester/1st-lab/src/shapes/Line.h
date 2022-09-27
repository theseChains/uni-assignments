#ifndef LINE_PRIMITIVE_H
#define LINE_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <array>
#include <optional>

#include "../util.h"

class Line
{
public:
    Line();
    Line(float mainPointX, float mainPointY, float length, const sf::Color& color);
    Line(float mainPointX, float mainPointY, float length, const std::array<int, 4>& colorComponents);

    std::optional<sf::RectangleShape> show(bool modifyVisibility = true);

    void moveTo(float offsetX, float offsetY);

    void rotate(float angleOffset);

    bool isShown() const;

private:
    float m_mainPointX{};
    float m_mainPointY{};

    float m_length{};

    sf::Color m_color{};
    
    float m_angle{};

    bool m_isShown{};
};

#endif
