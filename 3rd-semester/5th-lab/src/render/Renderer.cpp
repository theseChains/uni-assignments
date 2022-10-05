#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window) : m_window{ window }
{}

void Renderer::renderShapeArray(std::array<std::unique_ptr<Figure>, 30>& shapesToRender)
{
    for (const auto& shape : shapesToRender)
    {
        if (shape != nullptr && shape->isShown())
        {
            if (shape->isCircular())
            {
                m_window.get().draw(shape->show(false).circleValue());
            }
            else
            {
                m_window.get().draw(shape->show(false).convexValue());
            }
        }
    }
}
