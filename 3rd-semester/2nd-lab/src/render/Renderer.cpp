#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window) : m_window{ window }
{}

template <typename ShapeType>
void Renderer::renderShapes(std::array<std::unique_ptr<ShapeType>, 3>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape.get() != nullptr && shape.get()->isShown())
        {
            m_window.get().draw(shape.get()->show(false).value());
        }
    }
}

template void Renderer::renderShapes(std::array<std::unique_ptr<Circle>, 3>&);
template void Renderer::renderShapes(std::array<std::unique_ptr<Rectangle>, 3>&);
template void Renderer::renderShapes(std::array<std::unique_ptr<Line>, 3>&);

void Renderer::renderRings(std::array<std::unique_ptr<Ring>, 3>& ringsToRender)
{
    for (const auto& ring : ringsToRender)
    {
        if (ring.get() != nullptr && ring.get()->isShown())
        {
            m_window.get().draw(ring.get()->show(false).outerCircle.value());
            m_window.get().draw(ring.get()->show(false).innerCircle.value());
        }
    }
}

template <typename ShapeType>
void Renderer::renderShapeArrays(VectorOfArrayOfShapePtrs<ShapeType>& arraysToRender)
{
    for (auto& shapeArray : arraysToRender)
    {
        renderShapes(shapeArray);
    }
}

template void Renderer::renderShapeArrays(VectorOfArrayOfCirclePtrs&);
template void Renderer::renderShapeArrays(VectorOfArrayOfRectanglePtrs&);
template void Renderer::renderShapeArrays(VectorOfArrayOfLinePtrs&);

void Renderer::renderRingArrays(VectorOfArrayOfRingPtrs& ringArraysToRender)
{
    for (auto& ringArray : ringArraysToRender)
    {
        renderRings(ringArray);
    }
}
