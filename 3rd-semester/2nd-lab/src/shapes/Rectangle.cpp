#include "Rectangle.h"

// default constructor, initialized with arbitrary values
Rectangle::Rectangle()
    : m_vertex{ rnd::getFloat(util::guiWidth, util::windowWidth - 100),
        rnd::getFloat(0, util::windowHeight - 100) },
    m_width{ 150.0f },
    m_height{ 100.0f },
    m_color{ sf::Color::Magenta },
    m_isShown{ false }
{
}

Rectangle::Rectangle(float topLeftX, float topLeftY, float width, float height,
        const sf::Color& color)
    : m_vertex{ topLeftX, topLeftY },
    m_width{ width },
    m_height{ height },
    m_color{ color },
    m_isShown{ false }
{
    checkForBounds();

    std::cout << "Rectangle object created\n";
}

Rectangle::Rectangle(float topLeftX, float topLeftY, float width, float height,
        const std::array<int, 4>& colorComponents)
    : m_vertex{ topLeftX, topLeftY },
    m_width{ width },
    m_height{ height },
    m_color{ sf::Color(colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]) },
    m_isShown{ false }
{
    checkForBounds();

    std::cout << "Rectangle object created\n";
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

            return sf::RectangleShape{ createSprite() };
        }
    }
    // for rendering
    else
    {
        if (m_isShown)
        {
            return sf::RectangleShape{ createSprite() };
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

        m_vertex.setX(m_vertex.getX() + offsetX);
        m_vertex.setY(m_vertex.getY() + offsetY);

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

sf::RectangleShape Rectangle::createSprite() const
{
    sf::RectangleShape rectangleSprite{};

    rectangleSprite.setPosition(m_vertex.getX(), m_vertex.getY());
    rectangleSprite.setFillColor(m_color);
    rectangleSprite.setSize(sf::Vector2f{ m_width, m_height });

    return rectangleSprite;
}

void Rectangle::checkForBounds()
{
    float farRightX{ m_vertex.getX() + m_width * 2.0f };
    if (farRightX > static_cast<float>(util::windowWidth))
    {
        m_vertex.setX(m_vertex.getX() - (farRightX - static_cast<float>(util::windowWidth)));
    }

    float farDownY{ m_vertex.getY() + m_height * 2.0f };
    if (farDownY > static_cast<float>(util::windowHeight))
    {
        m_vertex.setY(m_vertex.getY() - (farDownY - static_cast<float>(util::windowHeight)));
    }
}
