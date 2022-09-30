#ifndef ASTERISK_PRIMITIVE_H
#define ASTERISK_PRIMITIVE_H

#include <array>
#include <iostream>
#include <optional>

#include "../util.h"

#include "Rectangle.h"

class Asterisk
{
public:
    Asterisk();
    Asterisk(float topLeftX, float topLeftY, float width, float height, const sf::Color& color);
    Asterisk(float topLeftX, float topLeftY, float width, float height,
            const std::array<int, 4>& colorComponents);

    struct OptAsterisk
    {
        std::optional<sf::RectangleShape> verticalRectangle{};
        std::optional<sf::RectangleShape> thirtyDegreeRectangle{};
        std::optional<sf::RectangleShape> sixtyDegreeRectangle{};
    };

    OptAsterisk show(bool modifyVisibility = true);

    void moveTo(float offsetX, float offsetY);

    bool isShown() const;

private:
    Rectangle m_verticalRectangle{};
    Rectangle m_thirtyDegreeRectangle{};
    Rectangle m_sixtyDegreeRectangle{};

    bool m_isShown{};

    // auxiliary
    sf::RectangleShape createVerticalRectangle() const;
    sf::RectangleShape createThirtyDegreeRectangle() const;
    sf::RectangleShape createSixtyDegreeRectangle() const;
};

#endif
