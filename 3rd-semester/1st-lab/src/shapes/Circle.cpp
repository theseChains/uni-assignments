#include "Circle.h"

// default constructor, initialized with arbitrary values
Circle::Circle() 
    : m_centerX{ util::windowWidth / 2.0f - 50.0f }, 
    m_centerY{ util::windowHeight / 2.0f - 50.0f },
    m_radius{ 50.0f }, 
    m_color{ sf::Color::Magenta }
{
    initializeSfSprite(); 
}

Circle::Circle(float centerX, float centerY, float radius, const sf::Color& color)
    : m_centerX{ centerX },
    m_centerY{ centerY },
    m_radius{ radius },
    m_color{ color }
{
    initializeSfSprite();
}

Circle::Circle(float centerX, float centerY, float radius, 
        const std::array<int, 4>& colorComponents)
    : m_centerX{ centerX },
    m_centerY{ centerY },
    m_radius{ radius },
    m_color{ sf::Color(colorComponents[component::red], colorComponents[component::green],
            colorComponents[component::blue], colorComponents[component::alpha]) }
{
    initializeSfSprite(); 
}

void Circle::show(std::vector<std::unique_ptr<Circle>>& circlesToRender)
{
    auto found{ std::ranges::find_if(circlesToRender, [this] (std::unique_ptr<Circle>& shapePtr)
            {
                return shapePtr.get() == this;
            }) };

    // remove the element if it was found, create it otherwise
    if (found != circlesToRender.end())
    {
        // erase() calls the destructor of the object, unique_ptr will free memory automatically
        circlesToRender.erase(found);
    }
    else
    {
        circlesToRender.push_back(std::move(std::make_unique<Circle>(*this)));
    }
}

void Circle::moveTo(float newCenterX, float newCenterY)
{
    m_centerX += newCenterX;
    m_centerY += newCenterY;

    updateSfSprite();
}

void Circle::changeRadius(float newRadius)
{
    m_radius += newRadius;

    updateSfSprite();
}

sf::CircleShape Circle::getSprite() const
{
    return m_sprite;
}

// needed for the find function
bool operator== (const Circle& first, const Circle& second)
{
    if (first.m_radius == second.m_radius && first.m_color == second.m_color
            && first.m_centerX == second.m_centerX && first.m_centerY == second.m_centerY)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Circle::initializeSfSprite()
{
    m_sprite.setPosition(m_centerX, m_centerY);
    m_sprite.setFillColor(m_color);
    m_sprite.setRadius(m_radius);
}

void Circle::updateSfSprite()
{
    m_sprite.setPosition(m_centerX, m_centerY);
    m_sprite.setRadius(m_radius);
}
