#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window) : m_window{ window }
{}

void Renderer::renderShapeArray(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
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

void Renderer::renderShapeList(DynamicList& shapesToRender)
{
    if (shapesToRender.first() == nullptr)
    {
        return;
    }

    int index{ 0 };
    for (DynamicList::Node* temp{ shapesToRender.first() }; temp->getNode() != nullptr; temp = temp->m_next)
    {
        if (temp->m_shape != nullptr && temp->m_shape->isShown())
        {
            if (temp->m_shape->isCircular())
            {
                m_window.get().draw(temp->m_shape->show(false).circleValue());
            }
            else
            {
                m_window.get().draw(temp->m_shape->show(false).convexValue());
            }
        }
    }
}
