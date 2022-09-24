#include "Circle.h"
#include <iostream>
// default constructor, initialized with arbitrary values
Circle::Circle() 
    : m_centerX{ util::windowWidth / 2.0f - rnd::getFloat(10, 200) }, 
    m_centerY{ util::windowHeight / 2.0f - rnd::getFloat(10, 200) },
    m_radius{ 50.0f }, 
    m_color{ sf::Color::Magenta },
    m_isShown{ false }
{
    std::cout << "default circle constructor called\n";
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

// copy constructor
Circle::Circle(Circle& circle)
   : m_centerX{ circle.m_centerX },
    m_centerY{ circle.m_centerY },
    m_radius{ circle.m_radius },
    m_color{ circle.m_color },
    m_isShown{ circle.m_isShown },
    m_sprite{ circle.m_sprite }
{}

// move constructor
Circle::Circle(Circle&& circle)
   : m_centerX{ circle.m_centerX },
    m_centerY{ circle.m_centerY },
    m_radius{ circle.m_radius },
    m_color{ circle.m_color },
    m_isShown{ circle.m_isShown },
    m_sprite{ circle.m_sprite }
{
    m_centerX = 0.0f;
    m_centerY = 0.0f;
    m_radius = 0.0f;
    m_color = sf::Color{};
    m_isShown = false;
    m_sprite = sf::CircleShape{};
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
