#include "Figure.h"

Figure::Figure(float mainPointX, float mainPointY, const sf::Color& color)
    : m_vertex{ mainPointX, mainPointY }, m_color{ color }
{
}

Vertex Figure::getPosition() const
{
    return m_vertex;
}

Figure::ToShow::ToShow(const std::optional<sf::CircleShape>& optCircleShape)
    : m_optCircleShape{ optCircleShape }
{
}

Figure::ToShow::ToShow(const std::optional<sf::RectangleShape>& optRectangleShape)
    : m_optRectangleShape{ optRectangleShape }
{
}

sf::RectangleShape Figure::ToShow::rectValue() const
{
    return m_optRectangleShape.value();
}

sf::CircleShape Figure::ToShow::circleValue() const
{
    return m_optCircleShape.value();
}
