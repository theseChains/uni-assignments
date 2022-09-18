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

void Line::show(std::vector<std::unique_ptr<Line>>& linesToRender)
{
    auto erased{ std::erase_if(linesToRender, [this] (std::unique_ptr<Line>& shapePtr)
            {
                return *shapePtr.get() == *this;
            }) };

    if (!erased)
    {
        linesToRender.push_back(std::make_unique<Line>(*this));
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

bool operator== (const Line& first, const Line& second)
{
    return (first.m_color == second.m_color);
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
