#include "Ring.h"

Ring::Ring() : m_outerCircle{ Circle{} }
{
    std::cout << "default ring constructor, outer circle initialized\n";
    // initialize inner circle here in case outer circle changes its coordinates
    float mainPointOffset{ m_outerCircle.getRadius() - m_outerCircle.getRadius() *
        util::innerCircleRadiusMultiplier };
    float innerCircleX{ m_outerCircle.getPosition().getX() + mainPointOffset };
    float innerCircleY{ m_outerCircle.getPosition().getY() + mainPointOffset };

    m_innerCircle = Circle{ innerCircleX, innerCircleY, m_outerCircle.getRadius() *
        util::innerCircleRadiusMultiplier, sf::Color::Black };
    std::cout << "default ring constructor, inner circle initialized\n";

    std::cout << "Ring object created\n";
}

Ring::Ring(float topLeftX, float topLeftY, float radius, const sf::Color& color)
    : m_outerCircle{ Circle{ topLeftX, topLeftY, radius, color } }
{
    float mainPointOffset{ m_outerCircle.getRadius() - m_outerCircle.getRadius() *
        util::innerCircleRadiusMultiplier };
    float innerCircleX{ m_outerCircle.getPosition().getX() + mainPointOffset };
    float innerCircleY{ m_outerCircle.getPosition().getY() + mainPointOffset };

    m_innerCircle = Circle{ innerCircleX, innerCircleY, m_outerCircle.getRadius() *
        util::innerCircleRadiusMultiplier, sf::Color::Black };

    std::cout << "Ring object created\n";
}

Ring::Ring(float topLeftX, float topLeftY, float radius, const std::array<int, 4>& colorComponents)
    : m_outerCircle{ Circle{ topLeftX, topLeftY, radius, sf::Color(colorComponents[component::red],
            colorComponents[component::green], colorComponents[component::blue],
            colorComponents[component::alpha]) } }
{
    float mainPointOffset{ m_outerCircle.getRadius() - m_outerCircle.getRadius() *
        util::innerCircleRadiusMultiplier };
    float innerCircleX{ m_outerCircle.getPosition().getX() + mainPointOffset };
    float innerCircleY{ m_outerCircle.getPosition().getY() + mainPointOffset };

    m_innerCircle = Circle{ innerCircleX, innerCircleY, m_outerCircle.getRadius() *
        util::innerCircleRadiusMultiplier, sf::Color::Black };

    std::cout << "Ring object created\n";
}

Ring::OptCircles Ring::show(bool modifyVisibility)
{
    if (modifyVisibility)
    {
        if (m_isShown)
        {
            m_isShown = false;

            return { std::nullopt, std::nullopt };
        }
        else
        {
            m_isShown = true;

            return OptCircles{ createOuterCircleSprite(), createInnerCircleSprite() };
        }
    }
    else
    {
        if (m_isShown)
        {
            return OptCircles{ createOuterCircleSprite(), createInnerCircleSprite() };
        }
        else
        {
            return { std::nullopt, std::nullopt };
        }
    }
}

void Ring::moveTo(float offsetX, float offsetY)
{
    if (m_isShown)
    {
        show();

        m_outerCircle.getPosition().setX(m_outerCircle.getPosition().getX() + offsetX);
        m_outerCircle.getPosition().setY(m_outerCircle.getPosition().getY() + offsetY);

        m_innerCircle.getPosition().setX(m_innerCircle.getPosition().getX() + offsetX);
        m_innerCircle.getPosition().setY(m_innerCircle.getPosition().getY() + offsetY);

        show();
    }
}

bool Ring::isShown() const
{
    return m_isShown;
}

sf::CircleShape Ring::createOuterCircleSprite() const
{
    sf::CircleShape outerCircleSprite{};

    outerCircleSprite.setPosition(m_outerCircle.getPosition().getX(),
            m_outerCircle.getPosition().getY());
    outerCircleSprite.setFillColor(m_outerCircle.getColor());
    outerCircleSprite.setRadius(m_outerCircle.getRadius());

    return outerCircleSprite;
}

sf::CircleShape Ring::createInnerCircleSprite() const
{
    sf::CircleShape innerCircleSprite{};

    innerCircleSprite.setPosition(m_innerCircle.getPosition().getX(),
            m_innerCircle.getPosition().getY());
    innerCircleSprite.setFillColor(m_innerCircle.getColor());
    innerCircleSprite.setRadius(m_innerCircle.getRadius());

    return innerCircleSprite;
}
