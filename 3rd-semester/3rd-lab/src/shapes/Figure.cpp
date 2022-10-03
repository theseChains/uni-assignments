#include "Figure.h"

Figure::Figure(float mainPointX, float mainPointY, const sf::Color& color)
    : m_vertex{ mainPointX, mainPointY }, m_color{ color }
{
}

Figure::Figure(float mainPointX, float mainPointY, const std::array<int, 4>& colorComponents)
    : m_vertex{ mainPointX, mainPointY }, m_color{ sf::Color(
            colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]
            ) }
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

Figure::ToShow::ToShow(const std::optional<sf::ConvexShape>& optConvexShape)
    : m_optConvexShape{ optConvexShape }
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

sf::ConvexShape Figure::ToShow::convexValue() const
{
    return m_optConvexShape.value();
}
