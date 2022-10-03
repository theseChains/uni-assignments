#include "Rectangle.h"

// default constructor, initialized with arbitrary values
Rectangle::Rectangle()
    : Quadrangle{ rnd::getFloat(util::guiWidth, util::windowWidth - 100),
        rnd::getFloat(0, util::windowHeight - 100), sf::Color::Magenta },
    m_width{ 150.0f },
    m_height{ 40.0f },
    m_isShown{ false }
{
    std::cout << "Rectangle object created\n";
}

Rectangle::Rectangle(float topLeftX, float topLeftY, float width, float height,
        const sf::Color& color)
    : Quadrangle{ topLeftX, topLeftY, color },
    m_width{ width },
    m_height{ height },
    m_isShown{ false }
{
    checkForBounds();

    std::cout << "Rectangle object created\n";
}

Rectangle::Rectangle(float topLeftX, float topLeftY, float width, float height,
        const std::array<int, 4>& colorComponents)
    : Quadrangle{ topLeftX, topLeftY, colorComponents },
    m_width{ width },
    m_height{ height },
    m_isShown{ false }
{
    checkForBounds();

    std::cout << "Rectangle object created\n";
}

Figure::ToShow Rectangle::show(bool modifyVisibility)
{
    if (modifyVisibility)
    {
        if (m_isShown)
        {
            m_isShown = false;

            return ToShow{};
        }
        else
        {
            m_isShown = true;

            return ToShow{ sf::RectangleShape{ createSprite() } };
        }
    }
    // for rendering
    else
    {
        if (m_isShown)
        {
            return ToShow{ sf::RectangleShape{ createSprite() } };
        }
        else
        {
            return ToShow{};
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

float Rectangle::getWidth() const
{
    return m_width;
}

float Rectangle::getHeight() const
{
    return m_height;
}

sf::Color Rectangle::getColor() const
{
    return m_color;
}

void Rectangle::setPosition(float newX, float newY)
{
    m_vertex.setX(newX);
    m_vertex.setY(newY);
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
