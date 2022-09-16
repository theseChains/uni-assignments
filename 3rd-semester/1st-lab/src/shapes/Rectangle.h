#ifndef RECTANGLE_PRIMITIVE_H
#define RECTANGLE_PRIMITIVE_H

#include <SFML/Graphics.hpp>

#include <array>
#include <vector>

#include "../util.h"

class Rectangle
{
public:
    Rectangle();
    Rectangle(float topLeftX, float topLeftY, float width, float height, const sf::Color& color);
    Rectangle(float topLeftX, float topLeftY, float width, float height,
            const std::array<int, 4>& colorComponents);

    void show(std::vector<sf::RectangleShape>& rectanglesToRender);

    void moveTo(float offsetX, float offsetY);

    void changeWidth(float newWidth);
    void changeHeight(float newHeight);
    
    sf::RectangleShape getSprite() const;

    bool m_isShown{};

private:
    sf::RectangleShape m_sprite{};

    float m_topLeftX{};
    float m_topLeftY{};

    float m_width{};
    float m_height{};

    sf::Color m_color{};

    void initializeSfSprite();
    void updateSfSprite();
};

#endif
