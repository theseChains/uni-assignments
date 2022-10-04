#include "Rhombus.h"

Rhombus::Rhombus()
    : Quadrangle{ rnd::getFloat(util::guiWidth, util::windowWidth - 100),
        rnd::getFloat(0, util::windowHeight - 100), sf::Color::Magenta },
    m_firstDiagonalLength{ 130.0f },
    m_secondDiagonalLength{ 85.0f }
{
    std::cout << "Rhombus object created\n\n";
}

Rhombus::Rhombus(float mainPointX, float mainPointY, float firstDiagonalLength,
            float secondDiagonalLength, const sf::Color& color)
    : Quadrangle{ mainPointX, mainPointY, color },
    m_firstDiagonalLength{ firstDiagonalLength },
    m_secondDiagonalLength{ secondDiagonalLength }
{
    std::cout << "Rhombus object created\n\n";
}

Rhombus::Rhombus(float mainPointX, float mainPointY, float firstDiagonalLength,
            float secondDiagonalLength, const std::array<int, 4>& colorComponents)
    : Quadrangle{ mainPointX, mainPointY, colorComponents },
    m_firstDiagonalLength{ firstDiagonalLength },
    m_secondDiagonalLength{ secondDiagonalLength }
{
    std::cout << "Rhombus object created\n\n";
}

Figure::ToShow Rhombus::show(bool modifyVisibility)
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

void Rhombus::changeFirstDiagonal(float diagonalOffset)
{
    if (m_isShown)
    {
        show();

        m_firstDiagonalLength += diagonalOffset;

        if (m_firstDiagonalLength <= 0.0f)
        {
            m_firstDiagonalLength = 0.0f;
        }

        show();
    }
}

void Rhombus::changeSecondDiagonal(float diagonalOffset)
{
    if (m_isShown)
    {
        show();

        m_secondDiagonalLength += diagonalOffset;

        if (m_secondDiagonalLength <= 0.0f)
        {
            m_secondDiagonalLength = 0.0f;
        }

        show();
    }
}

sf::ConvexShape Rhombus::createSprite() const
{
    sf::ConvexShape rhombusSprite{};

    rhombusSprite.setPointCount(4);
    rhombusSprite.setPoint(0, sf::Vector2f{ m_vertex.getX(), m_vertex.getY() });
    rhombusSprite.setPoint(1, sf::Vector2f{ m_vertex.getX() + m_firstDiagonalLength / 2,
            m_vertex.getY() - m_secondDiagonalLength / 2 });
    rhombusSprite.setPoint(2, sf::Vector2f{ m_vertex.getX() + m_firstDiagonalLength, m_vertex.getY() });
    rhombusSprite.setPoint(3, sf::Vector2f{ m_vertex.getX() + m_firstDiagonalLength / 2,
            m_vertex.getY() + m_secondDiagonalLength / 2 });
    rhombusSprite.setFillColor(m_color);

    return rhombusSprite;
}
