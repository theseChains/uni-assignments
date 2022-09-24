#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window) : m_window{ window }
{}

template <typename ShapeType>
void Renderer::renderShapes(std::array<std::unique_ptr<ShapeType>, 3> &shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape.get() != nullptr && shape.get()->isShown())
        {
            m_window.get().draw(shape.get()->getSprite());
        }
    }
}

template void Renderer::renderShapes(std::array<std::unique_ptr<Circle>, 3>&);
template void Renderer::renderShapes(std::array<std::unique_ptr<Rectangle>, 3>&);
template void Renderer::renderShapes(std::array<std::unique_ptr<Line>, 3>&);

template <typename ShapeType>
void Renderer::renderShapeArrays(std::vector<std::array<std::unique_ptr<ShapeType>, 3>>& arraysToRender)
{
    for (const auto& shapeArray : arraysToRender)
    {
        for (const auto& shape : shapeArray)
        {
            if (shape.get() != nullptr && shape.get()->isShown())
            {
                m_window.get().draw(shape.get()->getSprite());
            }
        }
    }
}

template void Renderer::renderShapeArrays(VectorOfArrayOfCirclePtrs&);
template void Renderer::renderShapeArrays(VectorOfArrayOfRectanglePtrs&);
template void Renderer::renderShapeArrays(VectorOfArrayOfLinePtrs&);
