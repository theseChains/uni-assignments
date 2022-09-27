#include "Line.h"

// default constructor, initialized with arbitrary values
Line::Line()
    : m_mainPointX{ rnd::getFloat(util::guiWidth, util::windowWidth - 100) },
    m_mainPointY{ rnd::getFloat(0, util::windowHeight - 100) },
    m_length{ 100.0f },
    m_color{ sf::Color::Magenta },
    m_angle{ 0.0f },
    m_isShown{ false }
{
}

Line::Line(float mainPointX, float mainPointY, float length, const sf::Color& color)
    : m_mainPointX{ mainPointX },
    m_mainPointY{ mainPointY },
    m_length{ length },
    m_color{ color },
    m_angle{ 0.0f },
    m_isShown{ false }
{
}

Line::Line(float mainPointX, float mainPointY, float length, const std::array<int, 4>& colorComponents)
    : m_mainPointX{ mainPointX },
    m_mainPointY{ mainPointY },
    m_length{ length },
    m_color{ sf::Color(colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]) },
    m_angle{ 0.0f },
    m_isShown{ false }
{
}

std::optional<sf::RectangleShape> Line::show(bool modifyVisibility)
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

            sf::RectangleShape lineSprite{};

            lineSprite.setPosition(m_mainPointX, m_mainPointY);
            lineSprite.setFillColor(m_color);
            lineSprite.setSize(sf::Vector2f{ m_length, util::lineWidth });
            lineSprite.setRotation(m_angle);

            return lineSprite;
        }
    }
    else
    {
        if (m_isShown)
        {
            sf::RectangleShape lineSprite{};

            lineSprite.setPosition(m_mainPointX, m_mainPointY);
            lineSprite.setFillColor(m_color);
            lineSprite.setSize(sf::Vector2f{ m_length, util::lineWidth });
            lineSprite.setRotation(m_angle);

            return lineSprite;
        }
        else
        {
            return std::nullopt;
        }
    }
}

void Line::moveTo(float offsetX, float offsetY)
{
    if (m_isShown)
    {
        show();

        m_mainPointX += offsetX;
        m_mainPointY += offsetY;

        show();
    }
}

void Line::rotate(float angleOffset)
{
    if (m_isShown)
    {
        show();

        m_angle += angleOffset;

        show();
    }
}

bool Line::isShown() const
{
    return m_isShown;
}
