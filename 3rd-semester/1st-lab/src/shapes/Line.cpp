#include "Line.h"

// default constructor, initialized with arbitrary values
Line::Line()
    : m_mainPointX{ rnd::getFloat(util::guiWidth, util::windowWidth - 100) },
    m_mainPointY{ rnd::getFloat(0, util::windowHeight - 100) },
    m_length{ 100.0f },
    m_color{ sf::Color::Magenta },
    m_isShown{ false }
{
    initializeSfSprite();
}

Line::Line(float mainPointX, float mainPointY, float length, const sf::Color& color)
    : m_mainPointX{ mainPointX },
    m_mainPointY{ mainPointY },
    m_length{ length },
    m_color{ color },
    m_isShown{ false }
{
    initializeSfSprite();
}

Line::Line(float mainPointX, float mainPointY, float length, const std::array<int, 4>& colorComponents)
    : m_mainPointX{ mainPointX },
    m_mainPointY{ mainPointY },
    m_length{ length },
    m_color{ sf::Color(colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]) },
    m_isShown{ false }
{
    initializeSfSprite();
}

void Line::show()
{
    // hide if already shown
    if (m_isShown)
    {
        m_isShown = false;
    }
    else
    {
        m_isShown = true;
    }
}

void Line::moveTo(float offsetX, float offsetY)
{
    m_mainPointX += offsetX;
    m_mainPointY += offsetY;

    updateSfSprite();
}

void Line::rotate(float angle)
{
    m_sprite.rotate(angle);
}

sf::RectangleShape Line::getSprite() const
{
    return m_sprite;
}

bool Line::isShown() const
{
    return m_isShown;
}

void Line::initializeSfSprite()
{
    m_sprite.setPosition(m_mainPointX, m_mainPointY);
    m_sprite.setFillColor(m_color);
    m_sprite.setSize(sf::Vector2f{ m_length, util::lineWidth });
}

void Line::updateSfSprite()
{
    m_sprite.setPosition(m_mainPointX, m_mainPointY);
}
