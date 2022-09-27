#include "Line.h"

// default constructor, initialized with arbitrary values
Line::Line()
    : m_vertex{ rnd::getFloat(util::guiWidth, util::windowWidth - 100),
        rnd::getFloat(0, util::windowHeight - 100) },
    m_length{ 100.0f },
    m_color{ sf::Color::Magenta },
    m_angle{ 0.0f },
    m_isShown{ false }
{
}

Line::Line(float mainPointX, float mainPointY, float length, const sf::Color& color)
    : m_vertex{ mainPointX, mainPointY },
    m_length{ length },
    m_color{ color },
    m_angle{ 0.0f },
    m_isShown{ false }
{
    checkForBounds();
    
    std::cout << "Line object created\n";
}

Line::Line(float mainPointX, float mainPointY, float length, const std::array<int, 4>& colorComponents)
    : m_vertex{ mainPointX, mainPointY },
    m_length{ length },
    m_color{ sf::Color(colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]) },
    m_angle{ 0.0f },
    m_isShown{ false }
{
    checkForBounds();

    std::cout << "Line object created\n";
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

void Line::moveTo(float offsetX, float offsetY)
{
    if (m_isShown)
    {
        show();

        m_vertex.setX(m_vertex.getX() + offsetX);
        m_vertex.setY(m_vertex.getY() + offsetY);

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

sf::RectangleShape Line::createSprite() const
{
    sf::RectangleShape lineSprite{};

    lineSprite.setPosition(m_vertex.getX(), m_vertex.getY());
    lineSprite.setFillColor(m_color);
    lineSprite.setSize(sf::Vector2f{ m_length, util::lineWidth });
    lineSprite.setRotation(m_angle);

    return lineSprite;
}

void Line::checkForBounds()
{
    float farRightX{ m_vertex.getX() + m_length * 2.0f };
    if (farRightX > static_cast<float>(util::windowWidth))
    {
        m_vertex.setX(m_vertex.getX() - (farRightX - static_cast<float>(util::windowWidth)));
    }

    float farDownY{ m_vertex.getY() + util::lineWidth * 2.0f };
    if (farDownY > static_cast<float>(util::windowHeight))
    {
        m_vertex.setY(m_vertex.getY() - (farDownY - static_cast<float>(util::windowHeight)));
    }
}
