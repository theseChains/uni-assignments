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

void Renderer::renderShapeList(DynamicList<std::shared_ptr<Figure>>& shapesToRender)
{
    if (shapesToRender.first() == nullptr)
    {
        return;
    }

    // only goes through once instead of twice for some reason
    for (DynamicList<std::shared_ptr<Figure>>::Node* temp{ shapesToRender.first() };
            temp != nullptr; temp = temp->m_next)
    {
        if (temp->m_data!= nullptr && temp->m_data->isShown())
        {
            if (temp->m_data->isCircular())
            {
                m_window.get().draw(temp->m_data->show(false).circleValue());
            }
            else
            {
                m_window.get().draw(temp->m_data->show(false).convexValue());
            }
        }
    }
}
