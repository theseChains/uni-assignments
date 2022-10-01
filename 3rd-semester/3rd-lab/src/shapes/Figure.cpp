#include "Figure.h"

Figure::Figure(float mainPointX, float mainPointY) : m_vertex{ mainPointX, mainPointY }
{
}

Vertex Figure::getPosition() const
{
    return m_vertex;
}
