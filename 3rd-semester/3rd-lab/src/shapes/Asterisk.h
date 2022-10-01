#ifndef ASTERISK_PRIMITIVE_H
#define ASTERISK_PRIMITIVE_H

#include <array>
#include <iostream>
#include <optional>

#include "../util.h"

#include "Line.h"

/* an asterisk, contains 6 lines each 60 degrees away from adjacent lines
 *  \ / - 300 degree line
 * -- -- - 0 degree line
 *  / \ - 60 degree line, and so on
 */

class Asterisk
{
public:
    Asterisk();
    Asterisk(float mainPointX, float mainPointY, float length, const sf::Color& color);
    Asterisk(float mainPointX, float mainPointY, float length, const std::array<int, 4>& colorComponents);

    struct OptAsterisk
    {
        std::optional<sf::RectangleShape> zeroDegreeLine{};
        std::optional<sf::RectangleShape> sixtyDegreeLine{};
        std::optional<sf::RectangleShape> oneTwentyDegreeLine{};
        std::optional<sf::RectangleShape> oneEightyDegreeLine{};
        std::optional<sf::RectangleShape> twoFortyDegreeLine{};
        std::optional<sf::RectangleShape> threeHundredDegreeLine{};
    };

    OptAsterisk show(bool modifyVisibility = true);

    void moveTo(float offsetX, float offsetY);

    void rotate(float angleOffset);

    bool isShown() const;

private:
    Line m_zeroDegreeLine{};
    Line m_sixtyDegreeLine{};
    Line m_oneTwentyDegreeLine{};
    Line m_oneEightyDegreeLine{};
    Line m_twoFortyDegreeLine{};
    Line m_threeHundredDegreeLine{};

    bool m_isShown{};

    float m_currentRotationAngle{};

    // auxiliary
    sf::RectangleShape createRotatedLineSprite(float rotationAngle) const;
    void initializeColorComponents(Line& line, const std::array<int, 4>& colorComponents);
};

#endif
