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

bool Figure::isShown() const
{
    return m_isShown;
}

bool Figure::isCircular() const
{
    return m_isCircular;
}

void Figure::moveTo(float offsetX, float offsetY)
{
    if (m_isShown && m_isQuadrangle)
    {
        show();

        m_vertex.setX(m_vertex.getX() + offsetX);
        m_vertex.setY(m_vertex.getY() + offsetY);
        m_secondVertex.setX(m_secondVertex.getX() + offsetX);
        m_secondVertex.setY(m_secondVertex.getY() + offsetY);
        m_thirdVertex.setX(m_thirdVertex.getX() + offsetX);
        m_thirdVertex.setY(m_thirdVertex.getY() + offsetY);
        m_fourthVertex.setX(m_fourthVertex.getX() + offsetX);
        m_fourthVertex.setY(m_fourthVertex.getY() + offsetY);

        show();
    }
    else if (m_isShown)
    {
        show();

        m_vertex.setX(m_vertex.getX() + offsetX);
        m_vertex.setY(m_vertex.getY() + offsetY);

        show();
    }
}

Figure::ToShow::ToShow(const std::optional<sf::CircleShape>& optCircleShape)
    : m_optCircleShape{ optCircleShape }
{
}

Figure::ToShow::ToShow(const std::optional<sf::ConvexShape>& optConvexShape)
    : m_optConvexShape{ optConvexShape }
{
}

sf::CircleShape Figure::ToShow::circleValue() const
{
    return m_optCircleShape.value();
}

sf::ConvexShape Figure::ToShow::convexValue() const
{
    return m_optConvexShape.value();
}
