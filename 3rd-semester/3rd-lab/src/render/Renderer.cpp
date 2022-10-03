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

template <typename CircularShape>
void Renderer::renderCircleShapes(std::array<std::unique_ptr<CircularShape>, 3>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape.get() != nullptr && shape.get()->isShown())
        {
            m_window.get().draw(shape.get()->show(false).circleValue());
        }
    }
}

template void Renderer::renderCircleShapes(std::array<std::unique_ptr<Circle>, 3>&);
template void Renderer::renderCircleShapes(std::array<std::unique_ptr<Ellipse>, 3>&);

void Renderer::renderQuadrangleShapes(std::array<std::unique_ptr<Quadrangle>, 3>& quadranglesToRender)
{
    for (const auto& quadrangle : quadranglesToRender)
    {
        if (quadrangle.get() != nullptr && quadrangle.get()->isShown())
        {
            m_window.get().draw(quadrangle.get()->show(false).convexValue());
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

template <typename CircularShape>
void Renderer::renderCircleShapeArrays(VectorOfArrayOfCircularShapePtrs<CircularShape>& circleArraysToRender)
{
    for (auto& circleArray : circleArraysToRender)
    {
        renderCircleShapes(circleArray);
    }
}

template void Renderer::renderCircleShapeArrays(VectorOfArrayOfCirclePtrs&);
template void Renderer::renderCircleShapeArrays(VectorOfArrayOfEllipsePtrs&);

void Renderer::renderQuadrangleShapeArrays(VectorOfArrayOfQuadranglePtrs& quadrangleArraysToRender)
{
    for (auto& quadrangleArray : quadrangleArraysToRender)
    {
        renderQuadrangleShapes(quadrangleArray);
    }
}
