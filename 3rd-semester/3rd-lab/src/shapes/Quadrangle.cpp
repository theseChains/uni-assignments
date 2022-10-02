#include "Quadrangle.h"

Quadrangle::Quadrangle()
    : Figure{ rnd::getFloat(util::guiWidth, util::windowWidth - 200),
        rnd::getFloat(0, util::windowHeight - 200), sf::Color::Magenta }
{
    initializeVertices();

    std::cout << "Quadrangle object created\n";
}

Quadrangle::Quadrangle(float mainPointX, float mainPointY, float secondPointX, float secondPointY,
        float thirdPointX, float thirdPointY, float fourthPointX, float fourthPointY,
        const sf::Color& color)
    : Figure{ mainPointX, mainPointY, color }
{
    initializeVertices();

    std::cout << "Quadrangle object created\n";
}

Quadrangle::Quadrangle(float mainPointX, float mainPointY, float secondPointX, float secondPointY,
        float thirdPointX, float thirdPointY, float fourthPointX, float fourthPointY,
        const std::array<int, 4>& colorComponents)
    : Figure{ mainPointX, mainPointY, sf::Color(
            colorComponents[component::red], colorComponents[component::blue],
            colorComponents[component::green], colorComponents[component::alpha]
            ) }
{
    initializeVertices();

    std::cout << "Quadrangle object created\n";
}

Figure::ToShow Quadrangle::show(bool modifyVisibility)
{

}

void Quadrangle::initializeVertices()
{
    m_secondVertex.setX(m_vertex.getX() + rnd::getFloat(10, 200));
    m_secondVertex.setY(m_vertex.getY() + rnd::getFloat(10, 50));

    m_thirdVertex.setX(m_secondVertex.getX() - rnd::getFloat(10, 50));
    m_thirdVertex.setY(m_secondVertex.getY() + rnd::getFloat(10, 200));

    m_fourthVertex.setX(m_thirdVertex.getX() - rnd::getFloat(10, 200));
    m_fourthVertex.setY(m_thirdVertex.getY() - rnd::getFloat(10, 50));
}
