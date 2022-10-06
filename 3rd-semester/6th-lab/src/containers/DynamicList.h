#ifndef DYNAMIC_LIST_CONTAINER_H
#define DYNAMIC_LIST_CONTAINER_H

#include <memory>

#include "../shapes/Figure.h"

template <typename ShapeType>
class DynamicList
{
public:
    class Node
    {
    public:
        std::unique_ptr<ShapeType> m_shape{};
        Node* m_next{};

        Node(Node* currentNode) : m_next{ currentNode }
        {
        }

        Node(std::unique_ptr<ShapeType>& newShape) : m_shape{ std::move(newShape) }
        {
        }
    };

private:
    Node* m_head{};

public:
    DynamicList() = default;

    void insert(std::unique_ptr<ShapeType> newShape)
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
        Node* currentNode{ m_head };
        Node* nextNode{ nullptr };

        while (currentNode != nullptr)
        {
            nextNode = currentNode->m_next;
            delete currentNode;
            currentNode = nextNode;
        }

        m_head = nullptr;
    }

    Node* first()
    {
        return m_head;
    }
};

#endif
