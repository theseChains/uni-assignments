#include "GuiShapeVisibilityModification.h"

void guiCheckForShapeArrayVisibilityModification(DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Show all shapes (G)"))
    {
        for (auto& shape : shapesToRender)
        {
            showShape(shape);
        }
    }
    if (ImGui::Button("Hide all shapes (H)"))
    {
        for (auto& shape : shapesToRender)
        {
            hideShape(shape);
        }
    }
}

void guiCheckForCircularShapeArrayVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Show circular shapes (G)"))
    {
        for (auto& shape : shapesToRender)
        {
            showCircularShape(shape);
        }
    }
    if (ImGui::Button("Hide circular shapes (H)"))
    {
        for (auto& shape : shapesToRender)
        {
            hideCircularShape(shape);
        }
    }
}

void guiCheckForQuadrangularShapeArrayVisibilityModification(
        DynamicArray<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Show quadrangular shapes (G)"))
    {
        for (auto& shape : shapesToRender)
        {
            showQuadrangularShape(shape);
        }
    }
    if (ImGui::Button("Hide quadrangular shapes (H)"))
    {
        for (auto& shape : shapesToRender)
        {
            hideQuadrangularShape(shape);
        }
    }
}

void guiCheckForShapeListVisibilityModification(DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Show all shapes (G)"))
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            showShape(temp->m_data);
        }
    }
    if (ImGui::Button("Hide all shapes (H)"))
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            hideShape(temp->m_data);
        }
    }
}

void guiCheckForCircularShapeListVisibilityModification(
        DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Show circular shapes (G)"))
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            showCircularShape(temp->m_data);
        }
    }
    if (ImGui::Button("Hide circular shapes (H)"))
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            hideCircularShape(temp->m_data);
        }
    }
}

void guiCheckForQuadrangularShapeListVisibilityModification(
        DynamicList<std::unique_ptr<Figure>>& shapesToRender)
{
    if (ImGui::Button("Show quadrangular shapes (G)"))
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            showQuadrangularShape(temp->m_data);
        }
    }
    if (ImGui::Button("Hide quadrangular shapes (H)"))
    {
        for (DynamicList<std::unique_ptr<Figure>>::Node* temp{ shapesToRender.first() };
                temp != nullptr; temp = temp->m_next)
        {
            hideQuadrangularShape(temp->m_data);
        }
    }
}
