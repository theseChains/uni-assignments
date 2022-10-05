#include "Trapezoid.h"

Trapezoid::Trapezoid()
    : Quadrangle{ rnd::getFloat(util::guiWidth, util::windowWidth - 100),
        rnd::getFloat(0, util::windowHeight - 100), sf::Color::Magenta },
    m_topBaseLength{ 120.0f },
    m_bottomBaseLength{ 180.0f },
    m_height{ 80.0f }
{
    std::cout << "Trapezoid object created\n\n";
}

Trapezoid::Trapezoid(float mainPointX, float mainPointY, float topBaseLength,
            float bottomBaseLength, float height, const sf::Color& color)
    : Quadrangle{ mainPointX, mainPointY, color },
    m_topBaseLength{ topBaseLength },
    m_bottomBaseLength{ bottomBaseLength },
    m_height{ height }
{
    std::cout << "Trapezoid object created\n\n";
}

Trapezoid::Trapezoid(float mainPointX, float mainPointY, float topBaseLength,
            float bottomBaseLength, float height, const std::array<int, 4>& colorComponents)
    : Quadrangle{ mainPointX, mainPointY, colorComponents },
    m_topBaseLength{ topBaseLength },
    m_bottomBaseLength{ bottomBaseLength },
    m_height{ height }
{
    std::cout << "Trapezoid object created\n\n";
}

Figure::ToShow Trapezoid::show(bool modifyVisibility)
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

            return ToShow{ sf::ConvexShape{ createSprite() } };
        }
    }
    // for rendering
    else
    {
        if (m_isShown)
        {
            return ToShow{ sf::ConvexShape{ createSprite() } };
        }
        else
        {
            return ToShow{};
        }
    }
}

void Trapezoid::changeTopBase(float baseOffset)
{
    if (m_isShown)
    {
        show();

        m_topBaseLength += baseOffset;

        if (m_topBaseLength <= 0.0f)
        {
            m_topBaseLength = 0.0f;
        }

        show();
    }
}

void Trapezoid::changeBottomBase(float baseOffset)
{
    if (m_isShown)
    {
        show();

        m_bottomBaseLength += baseOffset;

        if (m_bottomBaseLength <= 0.0f)
        {
            m_bottomBaseLength = 0.0f;
        }

        show();
    }
}

void Trapezoid::changeHeight(float heightOffset)
{
    if (m_isShown)
    {
        show();

        m_height += heightOffset;

        if (m_height <= 0.0f)
        {
            m_height = 0.0f;
        }

        show();
    }
}

sf::ConvexShape Trapezoid::createSprite() const
{
    sf::ConvexShape trapezoidSprite{};

    trapezoidSprite.setPointCount(4);
    trapezoidSprite.setPoint(0, sf::Vector2f{ m_vertex.getX(), m_vertex.getY() });
    trapezoidSprite.setPoint(1, sf::Vector2f{ m_vertex.getX() + m_topBaseLength, m_vertex.getY() });

    float baseDifference{ static_cast<float>(std::abs(m_bottomBaseLength - m_topBaseLength)) };
    trapezoidSprite.setPoint(2, sf::Vector2f{ m_vertex.getX() + m_topBaseLength +
            baseDifference / 2, m_vertex.getY() + m_height });
    trapezoidSprite.setPoint(3, sf::Vector2f{m_vertex.getX() - baseDifference / 2,
            m_vertex.getY() + m_height });
    trapezoidSprite.setFillColor(m_color);

    return trapezoidSprite;
}
