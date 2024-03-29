#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window) : m_window{ window }
{}

template <typename QuadrangularShape>
void Renderer::renderQuadrangularShapes(
        std::array<std::unique_ptr<QuadrangularShape>, 3>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape.get() != nullptr && shape.get()->isShown())
        {
            m_window.get().draw(shape.get()->show(false).convexValue());
        }
    }
}

template void Renderer::renderQuadrangularShapes(std::array<std::unique_ptr<Rectangle>, 3>&);
template void Renderer::renderQuadrangularShapes(std::array<std::unique_ptr<Rhombus>, 3>&);
template void Renderer::renderQuadrangularShapes(std::array<std::unique_ptr<Quadrangle>, 3>&);
template void Renderer::renderQuadrangularShapes(std::array<std::unique_ptr<Trapezoid>, 3>&);

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

template <typename QuadrangularShape>
void Renderer::renderQuadrangularShapeArrays(
        VectorOfArrayOfQuadrangularShapePtrs<QuadrangularShape>& arraysToRender)
{
    for (auto& shapeArray : arraysToRender)
    {
        renderQuadrangularShapes(shapeArray);
    }
}

template void Renderer::renderQuadrangularShapeArrays(VectorOfArrayOfRectanglePtrs&);
template void Renderer::renderQuadrangularShapeArrays(VectorOfArrayOfRhombusPtrs&);
template void Renderer::renderQuadrangularShapeArrays(VectorOfArrayOfQuadranglePtrs&);
template void Renderer::renderQuadrangularShapeArrays(VectorOfArrayOfTrapezoidPtrs&);

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
