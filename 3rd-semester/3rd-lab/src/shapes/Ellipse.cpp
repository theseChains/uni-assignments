#include "Ellipse.h"

Ellipse::Ellipse() : Circle{}
{
    m_semiaxis = m_radius * 0.5;
}


Ellipse::Ellipse(float topLeftX, float topLeftY, float radius, const sf::Color& color)
    : Circle{ topLeftX, topLeftY, radius, color }
{
    m_semiaxis = m_radius * 0.5;
}

Ellipse::Ellipse(float topLeftX, float topLeftY, float radius,
        const std::array<int, 4>& colorComponents)
    : Circle{ topLeftX, topLeftY, radius, colorComponents }
{
    m_semiaxis = m_radius * 0.5;
}

Ellipse::ToShow Ellipse::show(bool modifyVisibility)
{
    if (modifyVisibility)
    {
        if (m_isShown)
        {
            m_isShown = false;

            return ToShow{};
        }
        else
        {
            m_isShown = true;

            return ToShow{ sf::CircleShape{ createSprite() } };
        }
    }
    // for rendering
    else
    {
        if (m_isShown)
        {
            return ToShow{ sf::CircleShape{ createSprite() } };
        }
        else
        {
            return ToShow{};
        }
    }
}

void Ellipse::moveTo(float offsetX, float offsetY)
{
    if (m_isShown)
    {
        show();

        m_vertex.setX(m_vertex.getX() + offsetX);
        m_vertex.setY(m_vertex.getY() + offsetY);

        show();
    }
}

void Ellipse::rotateByNinetyDegrees()
{
    if (m_isShown)
    {
        show();

        m_angle += 90.0f;

        show();
    }
}

sf::CircleShape Ellipse::createSprite() const
{
    sf::CircleShape ellipseSprite{};

    ellipseSprite.setPosition(m_vertex.getX(), m_vertex.getY());
    ellipseSprite.setFillColor(m_color);
    ellipseSprite.setRadius(m_radius);
    ellipseSprite.setScale(m_radius, m_semiaxis);
    ellipseSprite.setRotation(m_angle);

    return ellipseSprite;
}
