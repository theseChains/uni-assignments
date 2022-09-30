#include "Asterisk.h"

Asterisk::Asterisk() : m_verticalRectangle{ Rectangle{} }, m_thirtyDegreeRectangle{ Rectangle{} },
    m_sixtyDegreeRectangle{ Rectangle{} }
{
    m_thirtyDegreeRectangle.setPosition(m_verticalRectangle.getPosition().getX(),
            m_verticalRectangle.getPosition().getY() + 1000);
    m_sixtyDegreeRectangle.setPosition(m_verticalRectangle.getPosition().getX() +
            m_verticalRectangle.getHeight() / 2,
            m_verticalRectangle.getPosition().getY() + (m_verticalRectangle.getWidth() / 2 + 
            m_verticalRectangle.getWidth() / util::twoBySqrtOfTwo +
            m_verticalRectangle.getHeight() / util::twoBySqrtOfTwo)); 

    std::cout << "Asterisk object created\n\n";
}

Asterisk::Asterisk(float topLeftX, float topLeftY, float width, float height, const sf::Color& color)
    : m_verticalRectangle{ Rectangle{ topLeftX, topLeftY, width, height, color } },
    m_thirtyDegreeRectangle{ Rectangle{ topLeftX, topLeftY, width, height, color } },
    m_sixtyDegreeRectangle{ Rectangle{ topLeftX, topLeftY, width, height, color } }
{
    std::cout << "Asterisk object created\n\n";
}

Asterisk::Asterisk(float topLeftX, float topLeftY, float width, float height,
        const std::array<int, 4>& colorComponents)
    : m_verticalRectangle{ Rectangle{ topLeftX, topLeftY, width, height, sf::Color(
            colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]
            ) } },
    m_thirtyDegreeRectangle{ Rectangle{ topLeftX, topLeftY, width, height, sf::Color(
            colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]
            ) } },
    m_sixtyDegreeRectangle{ Rectangle{ topLeftX, topLeftY, width, height, sf::Color(
            colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]
            ) } }
{
    std::cout << "Asterisk object created\n\n";
}

Asterisk::OptAsterisk Asterisk::show(bool modifyVisibility)
{
    if (modifyVisibility)
    {
        if (m_isShown)
        {
            m_isShown = false;

            return { std::nullopt, std::nullopt, std::nullopt };
        }
        else
        {
            m_isShown = true;

            return OptAsterisk{ createVerticalRectangle(), createThirtyDegreeRectangle(),
                createSixtyDegreeRectangle() };
        }
    }
    // for rendering
    else
    {
        if (m_isShown)
        {
            return OptAsterisk{ createVerticalRectangle(), createThirtyDegreeRectangle(),
                createSixtyDegreeRectangle() };
        }
        else
        {
            return { std::nullopt, std::nullopt, std::nullopt };
        }
    }
}

void Asterisk::moveTo(float offsetX, float offsetY)
{
    if (m_isShown)
    {
        show();

        m_verticalRectangle.setPosition(m_verticalRectangle.getPosition().getX() + offsetX,
                m_verticalRectangle.getPosition().getY() + offsetY);
        m_thirtyDegreeRectangle.setPosition(m_verticalRectangle.getPosition().getX() + offsetX,
                m_verticalRectangle.getPosition().getY() + offsetY);
        m_sixtyDegreeRectangle.setPosition(m_verticalRectangle.getPosition().getX() + offsetX,
                m_verticalRectangle.getPosition().getY() + offsetY);

        show();
    }
}

bool Asterisk::isShown() const
{
    return m_isShown;
}

sf::RectangleShape Asterisk::createVerticalRectangle() const
{
    sf::RectangleShape verticalRectangleSprite{};

    verticalRectangleSprite.setPosition(m_verticalRectangle.getPosition().getX(),
            m_verticalRectangle.getPosition().getY());
    verticalRectangleSprite.setFillColor(m_verticalRectangle.getColor());
    verticalRectangleSprite.setSize(sf::Vector2f{ m_verticalRectangle.getWidth(),
            m_verticalRectangle.getHeight() });

    if (m_verticalRectangle.getHeight() < m_verticalRectangle.getWidth())
    {
        verticalRectangleSprite.setRotation(90.0f);
    }

    return verticalRectangleSprite;
}

sf::RectangleShape Asterisk::createThirtyDegreeRectangle() const
{
    sf::RectangleShape thirtyDegreeRectangleSprite{};

    thirtyDegreeRectangleSprite.setPosition(m_thirtyDegreeRectangle.getPosition().getX(),
            m_thirtyDegreeRectangle.getPosition().getY());
    thirtyDegreeRectangleSprite.setFillColor(m_thirtyDegreeRectangle.getColor());
    thirtyDegreeRectangleSprite.setSize(sf::Vector2f{ m_thirtyDegreeRectangle.getWidth(),
            m_thirtyDegreeRectangle.getHeight() });

    if (m_verticalRectangle.getHeight() < m_verticalRectangle.getWidth())
    {
        thirtyDegreeRectangleSprite.setRotation(135.0f);
    }
    else
    {
        thirtyDegreeRectangleSprite.setRotation(30.0f);
    }

    return thirtyDegreeRectangleSprite;
}

sf::RectangleShape Asterisk::createSixtyDegreeRectangle() const
{
    sf::RectangleShape sixtyDegreeRectangleSprite{};

    sixtyDegreeRectangleSprite.setPosition(m_sixtyDegreeRectangle.getPosition().getX(),
            m_sixtyDegreeRectangle.getPosition().getY());
    sixtyDegreeRectangleSprite.setFillColor(m_sixtyDegreeRectangle.getColor());
    sixtyDegreeRectangleSprite.setSize(sf::Vector2f{ m_sixtyDegreeRectangle.getWidth(),
            m_sixtyDegreeRectangle.getHeight() });

    if (m_verticalRectangle.getHeight() < m_verticalRectangle.getWidth())
    {
        sixtyDegreeRectangleSprite.setRotation(-135.0f);
    }
    else
    {
        sixtyDegreeRectangleSprite.setRotation(-30.0f);
    }

    return sixtyDegreeRectangleSprite;
}
