#include "Rectangle.h"

// default constructor, initialized with arbitrary values
Rectangle::Rectangle()
    : m_topLeftX{ rnd::getFloat(util::guiWidth, util::windowWidth - 100) },
    m_topLeftY{ rnd::getFloat(0, util::windowHeight - 100) },
    m_width{ 150.0f },
    m_height{ 100.0f },
    m_color{ sf::Color::Magenta },
    m_isShown{ false }
{
}

Rectangle::Rectangle(float topLeftX, float topLeftY, float width, float height,
        const sf::Color& color)
    : m_topLeftX{ topLeftX },
    m_topLeftY{ topLeftY },
    m_width{ width },
    m_height{ height },
    m_color{ color },
    m_isShown{ false }
{
}

Rectangle::Rectangle(float topLeftX, float topLeftY, float width, float height,
        const std::array<int, 4>& colorComponents)
    : m_topLeftX{ topLeftX },
    m_topLeftY{ topLeftY },
    m_width{ width },
    m_height{ height },
    m_color{ sf::Color(colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]) },
    m_isShown{ false }
{
}

std::optional<sf::RectangleShape> Rectangle::show(bool modifyVisibility)
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

            sf::RectangleShape rectangleSprite{};

            rectangleSprite.setPosition(m_topLeftX, m_topLeftY);
            rectangleSprite.setFillColor(m_color);
            rectangleSprite.setSize(sf::Vector2f{ m_width, m_height });

            return rectangleSprite;
        }
    }
    else
    {
        if (m_isShown)
        {
            sf::RectangleShape rectangleSprite{};

            rectangleSprite.setPosition(m_topLeftX, m_topLeftY);
            rectangleSprite.setFillColor(m_color);
            rectangleSprite.setSize(sf::Vector2f{ m_width, m_height });

            return rectangleSprite;
        }
        else
        {
            return std::nullopt;
        }
    }
}

void Rectangle::moveTo(float offsetX, float offsetY)
{
    if (m_isShown)
    {
        show();

        m_topLeftX += offsetX;
        m_topLeftY += offsetY;

        show();
    }
}

void Rectangle::changeWidth(float widthOffset)
{
    if (m_isShown)
    {
        show();

        m_width += widthOffset;

        if (m_width < 0.0f)
        {
            m_width = 0.0f;
        }

        show();
    }
}

void Rectangle::changeHeight(float heightOffset)
{
    if (m_isShown)
    {
        show();

        m_height += heightOffset;

        if (m_height < 0.0f)
        {
            m_height = 0.0f;
        }

        show();
    }
}

bool Rectangle::isShown() const
{
    return m_isShown;
}
