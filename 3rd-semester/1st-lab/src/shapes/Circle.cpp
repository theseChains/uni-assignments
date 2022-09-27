#include "Circle.h"

// default constructor, initialized with arbitrary values
Circle::Circle()
    : m_topLeftX{ rnd::getFloat(util::guiWidth, util::windowWidth - 100) },
    m_topLeftY{ rnd::getFloat(0, util::windowHeight - 100) },
    m_radius{ 50.0f },
    m_color{ sf::Color::Magenta },
    m_isShown{ false }
{
}

Circle::Circle(float topLeftX, float topLeftY, float radius, const sf::Color& color)
    : m_topLeftX{ topLeftX },
    m_topLeftY{ topLeftY },
    m_radius{ radius },
    m_color{ color },
    m_isShown{ false }
{
}

Circle::Circle(float topLeftX, float topLeftY, float radius,
        const std::array<int, 4>& colorComponents)
    : m_topLeftX{ topLeftX },
    m_topLeftY{ topLeftY },
    m_radius{ radius },
    m_color{ sf::Color(colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]) },
    m_isShown{ false }
{
}

std::optional<sf::CircleShape> Circle::show(bool modifyVisibility)
{
    if (modifyVisibility)
    {
        if (m_isShown)
        {
            m_isShown = false;

            return std::nullopt;
        }
        else
        {
            m_isShown = true;

            sf::CircleShape circleSprite{};

            circleSprite.setPosition(m_topLeftX, m_topLeftY);
            circleSprite.setFillColor(m_color);
            circleSprite.setRadius(m_radius);

            return circleSprite;
        }
    }
    else
    {
        if (m_isShown)
        {
            sf::CircleShape circleSprite{};

            circleSprite.setPosition(m_topLeftX, m_topLeftY);
            circleSprite.setFillColor(m_color);
            circleSprite.setRadius(m_radius);

            return circleSprite;
        }
        else
        {
            return std::nullopt;
        }
    }
}

void Circle::moveTo(float offsetX, float offsetY)
{
    if (m_isShown)
    {
        show();

        m_topLeftX += offsetX;
        m_topLeftY += offsetY;

        show();
    }
}

void Circle::changeRadius(float radiusOffset)
{
    if (m_isShown)
    {
        show();

        m_radius += radiusOffset;

        if (m_radius < 0.0f)
        {
            m_radius = 0.0f;
        }

        show();
    }
}

bool Circle::isShown() const
{
    return m_isShown;
}
