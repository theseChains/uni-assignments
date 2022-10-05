#ifndef DYNAMIC_ARRAY_CONTAINER_H
#define DYNAMIC_ARRAY_CONTAINER_H

#include <cassert>

template <typename ShapeType>
class DynamicArray
{
public:
    // to make sure that the range based for loops work, we need to add begin() and end() functions
    // that return something that behaves like an iterator
    class MyIterator
    {
    private:
        ShapeType* m_ptr{};

    public:
        MyIterator(ShapeType* ptr) : m_ptr{ ptr }
        {
        }

        MyIterator operator++()
        {
            ++m_ptr;
            return *this;
        }

        bool operator!=(const MyIterator& other)
        {
            return m_ptr != other.m_ptr;
        }

        const ShapeType& operator*() const
        {
            return *m_ptr;
        }

        // non-const iterators
        ShapeType& operator*()
        {
            return *m_ptr;
        }
    };

private:
    int m_size{};
    ShapeType* m_data{};

public:
    DynamicArray() = default;

    DynamicArray(int size) : m_size{ size }
    {
        assert(size >= 0);

        if (size > 0)
        {
            m_data = new ShapeType[size]{};
        }
    }

    ~DynamicArray()
    {
        delete[] m_data;
    }

    void clear()
    {
        delete[] m_data;

        // set to nullptr otherwise it will be pointing at deallocated memory
        m_data = nullptr;
        m_size = 0;
    }

    MyIterator begin() const
    {
        return MyIterator{ m_data };
    }

    MyIterator end() const
    {
        return MyIterator{ m_data + m_size };
    }

    int size() const
    {
        return m_size;
    }
};

#endif
