#include "Rectangle.h"

// default constructor, initialized with arbitrary values
Rectangle::Rectangle()
    : m_topLeftX{ util::windowWidth / 2.0f - 75.0f },
    m_topLeftY{ util::windowHeight / 2.0f - 50.0f },
    m_width{ 150.0f },
    m_height{ 100.0f },
    m_color{ sf::Color::Magenta }
{
    initializeSfSprite();
}

Rectangle::Rectangle(float topLeftX, float topLeftY, float width, float height,
        const sf::Color& color)
    : m_topLeftX{ topLeftX },
    m_topLeftY{ topLeftY },
    m_width{ width },
    m_height{ height },
    m_color{ color }
{
    initializeSfSprite();
}

Rectangle::Rectangle(float topLeftX, float topLeftY, float width, float height,
        const std::array<int, 4>& colorComponents)
    : m_topLeftX{ topLeftX },
    m_topLeftY{ topLeftY },
    m_width{ width },
    m_height{ height },
    m_color{ sf::Color(colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]) }
{
    initializeSfSprite();
}

void Rectangle::moveTo(float offsetX, float offsetY)
{
    m_topLeftX += offsetX;
    m_topLeftY += offsetY;

    updateSfSprite();
}

void Rectangle::changeWidth(float newWidth)
{
    m_width += newWidth;

    updateSfSprite();
}

void Rectangle::changeHeight(float newHeight)
{
    m_height += newHeight;

    updateSfSprite();
}

sf::RectangleShape Rectangle::getSprite() const
{
    return m_sprite;
}

void Rectangle::initializeSfSprite()
{
    m_sprite.setPosition(m_topLeftX, m_topLeftY);
    m_sprite.setFillColor(m_color);
    m_sprite.setSize(sf::Vector2f{ m_width, m_height });
}

void Rectangle::updateSfSprite()
{
    m_sprite.setPosition(m_topLeftX, m_topLeftY);
    m_sprite.setSize(sf::Vector2f{ m_width, m_height });
}
