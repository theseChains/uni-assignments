#ifndef FIGURE_BASE_H
#define FIGURE_BASE_H

#include <SFML/Graphics.hpp>

#include <optional>

#include "Vertex.h"

class Figure
{
public:
    Figure(float mainPointX, float mainPointY);

    struct ToShow
    {
        bool modifyVisibility{};

        // overload std::optional<sf::CircleShape> cast - provide a way to convert this ToShow
        // struct to the optional<> type.
        // with this we can overload a funciton that differ only by return types
        operator std::optional<sf::CircleShape>() const;
        operator std::optional<sf::RectangleShape>() const;
    };

    virtual ToShow show(bool modifyVisibility = true) = 0;

    virtual void moveTo(float offsetX, float offsetY) = 0;

    Vertex getPosition() const;

    virtual ~Figure() = default;

protected:
    Vertex m_vertex{};
};

#endif
