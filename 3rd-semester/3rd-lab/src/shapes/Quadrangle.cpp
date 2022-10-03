#include "Quadrangle.h"

Quadrangle::Quadrangle()
    : Figure{ rnd::getFloat(util::guiWidth + 200, util::windowWidth - 200),
        rnd::getFloat(0, util::windowHeight - 200), sf::Color::Magenta }
{
    initializeRandomVertices();

    std::cout << "Quadrangle object created\n";
}

Quadrangle::Quadrangle(float mainPointX, float mainPointY, float secondPointX, float secondPointY,
        float thirdPointX, float thirdPointY, float fourthPointX, float fourthPointY,
        const sf::Color& color)
    : Figure{ mainPointX, mainPointY, color }
{
    m_secondVertex.setPosition(secondPointX, secondPointY);
    m_thirdVertex.setPosition(thirdPointX, thirdPointY);
    m_fourthVertex.setPosition(fourthPointX, fourthPointY);
    
    std::cout << "Quadrangle object created\n";
}

Quadrangle::Quadrangle(float mainPointX, float mainPointY, float secondPointX, float secondPointY,
        float thirdPointX, float thirdPointY, float fourthPointX, float fourthPointY,
        const std::array<int, 4>& colorComponents)
    : Figure{ mainPointX, mainPointY, colorComponents }
{
    m_secondVertex.setPosition(secondPointX, secondPointY);
    m_thirdVertex.setPosition(thirdPointX, thirdPointY);
    m_fourthVertex.setPosition(fourthPointX, fourthPointY);

    std::cout << "Quadrangle object created\n";
}

Figure::ToShow Quadrangle::show(bool modifyVisibility)
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

void Quadrangle::moveTo(float offsetX, float offsetY)
{
    if (m_isShown)
    {
        show();

        m_vertex.setX(m_vertex.getX() + offsetX);
        m_vertex.setY(m_vertex.getY() + offsetY);
        m_secondVertex.setX(m_secondVertex.getX() + offsetX);
        m_secondVertex.setY(m_secondVertex.getY() + offsetY);
        m_thirdVertex.setX(m_thirdVertex.getX() + offsetX);
        m_thirdVertex.setY(m_thirdVertex.getY() + offsetY);
        m_fourthVertex.setX(m_fourthVertex.getX() + offsetX);
        m_fourthVertex.setY(m_fourthVertex.getY() + offsetY);

        show();
    }
}

bool Quadrangle::isShown() const
{
    return m_isShown;
}

sf::ConvexShape Quadrangle::createSprite() const
{
    sf::ConvexShape quadrangleSprite{};

    quadrangleSprite.setPointCount(4);
    quadrangleSprite.setPoint(0, sf::Vector2f{ m_vertex.getX(), m_vertex.getY() });
    quadrangleSprite.setPoint(1, sf::Vector2f{ m_secondVertex.getX(), m_secondVertex.getY() });
    quadrangleSprite.setPoint(2, sf::Vector2f{ m_thirdVertex.getX(), m_thirdVertex.getY() });
    quadrangleSprite.setPoint(3, sf::Vector2f{ m_fourthVertex.getX(), m_fourthVertex.getY() });
    quadrangleSprite.setFillColor(m_color);

    return quadrangleSprite;
}

void Quadrangle::initializeRandomVertices()
{
    m_secondVertex.setX(m_vertex.getX() + rnd::getFloat(10, 200));
    m_secondVertex.setY(m_vertex.getY() + rnd::getFloat(10, 50));

    m_thirdVertex.setX(m_secondVertex.getX() - rnd::getFloat(10, 50));
    m_thirdVertex.setY(m_secondVertex.getY() + rnd::getFloat(10, 200));

    // this is a bit messy but whatever
    m_fourthVertex.setX(m_thirdVertex.getX() - rnd::getFloat(10, 200));
    m_fourthVertex.setY(m_secondVertex.getY() + rnd::getFloat(10, 50));
}
