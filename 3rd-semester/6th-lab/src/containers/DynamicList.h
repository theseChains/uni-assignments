#ifndef DYNAMIC_LIST_CONTAINER_H
#define DYNAMIC_LIST_CONTAINER_H

#include <memory>

#include "../shapes/Figure.h"

class DynamicList
{
public:
    class Node
    {
    public:
        std::unique_ptr<Figure> m_shape{};
        Node* m_next{};

        Node(Node* currentNode) : m_next{ currentNode }
        {
        }

        Node(std::unique_ptr<Figure>& newShape) : m_shape{ std::move(newShape) }
        {
        }

        Node* getNode()
        {
            return m_next;
        }
    };

private:
    Node* m_head{};

public:
    DynamicList() = default;

    void insert(std::unique_ptr<Figure> newShape)
    {
        Node* newNode{ new Node{ newShape } };

        if (m_head == nullptr)
        {
            m_head = newNode;
            return;
        }

        // traverse till the end and insert
        Node* temp{ m_head };
        while (temp->m_next != nullptr)
        {
            temp = temp->m_next;
        }

        temp->m_next = newNode;
    }

    void clear()
    {

    }

    Node* first()
    {
        return m_head;
    }

    //void render(Renderer& renderer)
    //{
    //    if (m_head == nullptr)
    //    {
    //        return;
    //    }

    //    Node* temp{ m_head };
    //    while (temp->next != nullptr)
    //    {
    //        renderer.renderShapeList(std::move(temp->m_shape));
    //        temp = temp->next;
    //    }
    //}
};

#endif
