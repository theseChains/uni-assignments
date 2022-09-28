#include "Circle.h"

// default constructor, initialized with arbitrary values
Circle::Circle()
    : m_vertex{ rnd::getFloat(util::guiWidth, util::windowWidth - 100),
        rnd::getFloat(0, util::windowHeight - 100) },
    m_radius{ 50.0f },
    m_color{ sf::Color::Magenta },
    m_isShown{ false }
{
    std::cout << "Circle object created\n";
}

Circle::Circle(float topLeftX, float topLeftY, float radius, const sf::Color& color)
    : m_vertex{ topLeftX, topLeftY },
    m_radius{ radius },
    m_color{ color },
    m_isShown{ false }
{
    checkForBounds();

    std::cout << "Circle object created\n";
}

Circle::Circle(float topLeftX, float topLeftY, float radius,
        const std::array<int, 4>& colorComponents)
    : m_vertex{ topLeftX, topLeftY },
    m_radius{ radius },
    m_color{ sf::Color(colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]) },
    m_isShown{ false }
{
    checkForBounds();

    std::cout << "Circle object created\n";
}

std::optional<sf::CircleShape> Circle::show(bool modifyVisibility)
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

            return sf::CircleShape{ createSprite() };
        }
    }
    // for rendering
    else
    {
        if (m_isShown)
        {
            return sf::CircleShape{ createSprite() };
        }
        else
        {
            return std::nullopt;
        }
    }
}

void Circle::moveTo(float offsetX, float offsetY)
{
    if (m_isShown)
    {
        show();

        m_vertex.setX(m_vertex.getX() + offsetX);
        m_vertex.setY(m_vertex.getY() + offsetY);

        show();
    }
}

void Circle::changeRadius(float radiusOffset)
{
    if (m_isShown)
    {
        show();

        m_radius += radiusOffset;

        if (m_radius < 0.0f)
        {
            m_radius = 0.0f;
        }

        show();
    }
}

bool Circle::isShown() const
{
    return m_isShown;
}

Vertex Circle::getPosition() const
{
    return m_vertex;
}

float Circle::getRadius() const
{
    return m_radius;
}

sf::Color Circle::getColor() const
{
    return m_color;
}

void Circle::setPosition(float newX, float newY)
{
    m_vertex.setX(newX);
    m_vertex.setY(newY);
}

void Circle::setColor(const sf::Color& color)
{
    m_color = color;
}

void Circle::setRadius(float newRadius)
{
    m_radius = newRadius;
}

sf::CircleShape Circle::createSprite() const
{
    sf::CircleShape circleSprite{};

    circleSprite.setPosition(m_vertex.getX(), m_vertex.getY());
    circleSprite.setFillColor(m_color);
    circleSprite.setRadius(m_radius);

    return circleSprite;
}

void Circle::checkForBounds()
{
    float farRightX{ m_vertex.getX() + m_radius * 2.0f };
    if (farRightX > static_cast<float>(util::windowWidth))
    {
        m_vertex.setX(m_vertex.getX() - (farRightX - static_cast<float>(util::windowWidth)));
    }

    float farDownY{ m_vertex.getY() + m_radius * 2.0f };
    if (farDownY > static_cast<float>(util::windowHeight))
    {
        m_vertex.setY(m_vertex.getY() - (farDownY - static_cast<float>(util::windowHeight)));
    }
}
