#include "Line.h"

// default constructor, initialized with arbitrary values
Line::Line()
    : m_mainPointX{ util::windowWidth / 2.0f - 200.0f },
    m_mainPointY{ util::windowHeight / 2.0f },
    m_length{ 100.0f },
    m_color{ sf::Color::Magenta }
{
    initializeSfSprite();
}

Line::Line(float mainPointX, float mainPointY, float length, const sf::Color& color)
    : m_mainPointX{ mainPointX },
    m_mainPointY{ mainPointY },
    m_length{ length },
    m_color{ color }
{
    initializeSfSprite();
}

Line::Line(float mainPointX, float mainPointY, float length, const std::array<int, 4>& colorComponents)
    : m_mainPointX{ mainPointX },
    m_mainPointY{ mainPointY },
    m_length{ length },
    m_color{ sf::Color(colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]) }
{
    initializeSfSprite();
}

void Line::rotate(float angle)
{
    m_sprite.rotate(angle);
}

sf::RectangleShape Line::getSprite() const
{
    return m_sprite;
}

void Line::initializeSfSprite()
{
    m_sprite.setPosition(m_mainPointX, m_mainPointY);
    m_sprite.setFillColor(m_color);
    m_sprite.setSize(sf::Vector2f{ m_length, 2.0f });
}
