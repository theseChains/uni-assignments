#include "Circle.h"

// default constructor, initialized with arbitrary values
Circle::Circle() 
    : m_centerX{ rnd::getFloat(util::guiWidth, util::windowWidth - 100) }, 
    m_centerY{ rnd::getFloat(0, util::windowHeight - 100) },
    m_radius{ 50.0f }, 
    m_color{ sf::Color::Magenta },
    m_isShown{ false }
{
    initializeSfSprite(); 
}

Circle::Circle(float centerX, float centerY, float radius, const sf::Color& color)
    : m_centerX{ centerX },
    m_centerY{ centerY },
    m_radius{ radius },
    m_color{ color },
    m_isShown{ false }
{
    initializeSfSprite();
}

Circle::Circle(float centerX, float centerY, float radius, 
        const std::array<int, 4>& colorComponents)
    : m_centerX{ centerX },
    m_centerY{ centerY },
    m_radius{ radius },
    m_color{ sf::Color(colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]) },
    m_isShown{ false }
{
    initializeSfSprite(); 
}

void Circle::show()
{
    if (m_isShown)
    {
        m_isShown = false;
    }
    else
    {
        m_isShown = true;
    }
}

void Circle::moveTo(float offsetX, float offsetY)
{
    m_centerX += offsetX;
    m_centerY += offsetY;

    updateSfSprite();
}

void Circle::changeRadius(float radiusOffset)
{
    m_radius += radiusOffset;

    if (m_radius < 0.0f)
    {
        m_radius = 0.0f;
    }

    updateSfSprite();
}

sf::CircleShape Circle::getSprite() const
{
    return m_sprite;
}

bool Circle::isShown() const
{
    return m_isShown;
}

void Circle::initializeSfSprite()
{
    m_sprite.setPosition(m_centerX, m_centerY);
    m_sprite.setFillColor(m_color);
    m_sprite.setRadius(m_radius);
}

void Circle::updateSfSprite()
{
    m_sprite.setPosition(m_centerX, m_centerY);
    m_sprite.setRadius(m_radius);
}
