#include "Vertex.h"

Vertex::Vertex(float x, float y)
    : m_x{ x },
    m_y{ y }
{
    std::cout << "Vertex object initialized\n"; 
}

float Vertex::getX() const
{
    return m_x;
}

float Vertex::getY() const
{
    return m_y;
}

void Vertex::setX(float newX)
{
    m_x = newX;
}

void Vertex::setY(float newY)
{
    m_y = newY;
}

void Vertex::setPosition(float newX, float newY)
{
    m_x = newX;
    m_y = newY;
}
