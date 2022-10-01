#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window) : m_window{ window }
{}

template <typename RectangleShape>
void Renderer::renderRectangleShapes(std::array<std::unique_ptr<RectangleShape>, 3>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape.get() != nullptr && shape.get()->isShown())
        {
            m_window.get().draw(shape.get()->show(false).rectValue());
        }
    }
}

template void Renderer::renderRectangleShapes(std::array<std::unique_ptr<Rectangle>, 3>&);
template void Renderer::renderRectangleShapes(std::array<std::unique_ptr<Line>, 3>&);

void Renderer::renderCircleShapes(std::array<std::unique_ptr<Circle>, 3>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape.get() != nullptr && shape.get()->isShown())
        {
            m_window.get().draw(shape.get()->show(false).circleValue());
        }
    }
}

template <typename RectangleShape>
void Renderer::renderRectangleShapeArrays(VectorOfArrayOfShapePtrs<RectangleShape>& arraysToRender)
{
    for (auto& shapeArray : arraysToRender)
    {
        renderRectangleShapes(shapeArray);
    }
}

template void Renderer::renderRectangleShapeArrays(VectorOfArrayOfRectanglePtrs&);
template void Renderer::renderRectangleShapeArrays(VectorOfArrayOfLinePtrs&);

void Renderer::renderCircleShapeArrays(VectorOfArrayOfCirclePtrs& circleArraysToRender)
{
    for (auto& circleArray : circleArraysToRender)
    {
        renderCircleShapes(circleArray);
    }
}
