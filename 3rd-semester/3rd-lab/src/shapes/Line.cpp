#include "Line.h"

// default constructor, initialized with arbitrary values
Line::Line()
    : Figure{ rnd::getFloat(util::guiWidth, util::windowWidth - 100),
        rnd::getFloat(0, util::windowHeight - 100) },
    m_length{ 100.0f },
    m_color{ sf::Color::Magenta },
    m_angle{ 0.0f },
    m_isShown{ false }
{
    std::cout << "Line object created\n";
}

Line::Line(float mainPointX, float mainPointY, float length, const sf::Color& color)
    : Figure{ mainPointX, mainPointY },
    m_length{ length },
    m_color{ color },
    m_angle{ 0.0f },
    m_isShown{ false }
{
    checkForBounds();

    std::cout << "Line object created\n";
}

Line::Line(float mainPointX, float mainPointY, float length, const std::array<int, 4>& colorComponents)
    : Figure{ mainPointX, mainPointY },
    m_length{ length },
    m_color{ sf::Color(colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]) },
    m_angle{ 0.0f },
    m_isShown{ false }
{
    checkForBounds();

    std::cout << "Line object created\n";
}

Figure::ToShow Line::show(bool modifyVisibility)
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

sf::Color Line::getColor() const
{
    return m_color;
}

float Line::getLength() const
{
    return m_length;
}

void Line::setPosition(float newX, float newY)
{
    m_vertex.setX(newX);
    m_vertex.setY(newY);
}

void Line::setColor(const sf::Color& color)
{
    m_color = color;
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
