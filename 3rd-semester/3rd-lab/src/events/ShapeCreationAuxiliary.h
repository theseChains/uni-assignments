#ifndef SHAPE_CREATION_AUXILIARY_H
#define SHAPE_CREATION_AUXILIARY_H

#include "../util.h"

#include "../shapes/Circle.h"
#include "../shapes/Ellipse.h"
#include "../shapes/Quadrangle.h"
#include "../shapes/Rectangle.h"
#include "../shapes/Rhombus.h"
#include "../shapes/Trapezoid.h"

namespace Creation
{
    template <typename ShapeType>
    void hideAndDeleteShape(std::unique_ptr<ShapeType>& shapePtr);

    struct Color
    {
        int m_redComponent{};
        int m_greenComponent{};
        int m_blueComponent{};
    };

    Color createRandomColor();
}

#endif
