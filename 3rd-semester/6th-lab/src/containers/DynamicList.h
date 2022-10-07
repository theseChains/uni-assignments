#ifndef DYNAMIC_LIST_CONTAINER_H
#define DYNAMIC_LIST_CONTAINER_H

#include <memory>

#include "../shapes/Figure.h"

template <typename T>
class DynamicList
{
public:
    class Node
    {
    public:
        T m_data{};
        Node* m_next{};

        Node(Node* currentNode) : m_next{ currentNode }
        {
        }

        Node(T&& newData) : m_data{ std::move(newData) }
        {
        }
    };

private:
    Node* m_head{};

public:
    DynamicList() = default;

    void insert(const T& newData)
    {
        Node* newNode{ new Node{ newData } };

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

    void insert(T&& newData)
    {
        Node* newNode{ new Node{ std::move(newData) } };

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
