#ifndef PRIMITIVE_VERTEX_H
#define PRIMITIVE_VERTEX_H

#include <iostream>

class Vertex 
{
public:
    Vertex() = default;
    Vertex(float x, float y);

    float getX() const;
    float getY() const;

    void setX(float newX);
    void setY(float newY);
    void setPosition(float newX, float newY);

private:
    float m_x{};
    float m_y{};
};

#endif
