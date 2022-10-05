#include "ShapeMovement.h"

void moveAllShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender,
        float verticalDirection, float horizontalDirection)
{
    if (verticalDirection == 0.0f && horizontalDirection == 0.0f)
    {
        for (const auto& shape : shapesToRender)
        {
            if (shape != nullptr)
            {
                shape->moveTo(rnd::getFloat(-50, 50), rnd::getFloat(-50, 50));
            }
        }
    }
    else
    {
        for (const auto& shape : shapesToRender)
        {
            if (shape != nullptr)
            {
                shape->moveTo(verticalDirection, horizontalDirection);
            }
        }
    }
}

void moveCircularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender,
        float verticalDirection, float horizontalDirection)
{
    if (verticalDirection == 0.0f && horizontalDirection == 0.0f)
    {
        for (const auto& shape : shapesToRender)
        {
            Circle* circularShape{ dynamic_cast<Circle*>(shape.get()) };

            if (circularShape)
            {
                circularShape->moveTo(rnd::getFloat(-50, 50), rnd::getFloat(-50, 50));
            }
        }
    }
    else
    {
        for (const auto& shape : shapesToRender)
        {
            Circle* circularShape{ dynamic_cast<Circle*>(shape.get()) };

            if (circularShape)
            {
                circularShape->moveTo(verticalDirection, horizontalDirection);
            }
        }
    }
}

void moveQuadrangularShapes(std::array<std::unique_ptr<Figure>, 30>& shapesToRender,
        float verticalDirection, float horizontalDirection)
{
    if (verticalDirection == 0.0f && horizontalDirection == 0.0f)
    {
        for (const auto& shape : shapesToRender)
        {
            Quadrangle* quadrangularShape{ dynamic_cast<Quadrangle*>(shape.get()) };

            if (quadrangularShape)
            {
                quadrangularShape->moveTo(rnd::getFloat(-50, 50), rnd::getFloat(-50, 50));
            }
        }
    }
    else
    {
        for (const auto& shape : shapesToRender)
        {
            Quadrangle* quadrangularShape{ dynamic_cast<Quadrangle*>(shape.get()) };

            if (quadrangularShape)
            {
                quadrangularShape->moveTo(verticalDirection, horizontalDirection);
            }
        }
    }
}
