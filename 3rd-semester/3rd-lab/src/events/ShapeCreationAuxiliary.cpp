#include "ShapeCreationAuxiliary.h"

template <typename ShapeType>
void Creation::hideAndDeleteShape(std::unique_ptr<ShapeType>& shapePtr)
{
    if (shapePtr.get() != nullptr)
    {
        shapePtr.get()->show();
        shapePtr.reset();
    }
}

template void Creation::hideAndDeleteShape(std::unique_ptr<Circle>&);
template void Creation::hideAndDeleteShape(std::unique_ptr<Ellipse>&);
template void Creation::hideAndDeleteShape(std::unique_ptr<Rectangle>&);
template void Creation::hideAndDeleteShape(std::unique_ptr<Quadrangle>&);
template void Creation::hideAndDeleteShape(std::unique_ptr<Rhombus>&);
template void Creation::hideAndDeleteShape(std::unique_ptr<Trapezoid>&);

Creation::Color Creation::createRandomColor()
{
    int redComponent{ rnd::getNumber(0, 255) };
    int greenComponent{ rnd::getNumber(0, 255) };
    int blueComponent{ rnd::getNumber(0, 255) };

    return { redComponent, greenComponent, blueComponent };
}
