#ifndef ASTERISK_PRIMITIVE_H
#define ASTERISK_PRIMITIVE_H

#include <array>
#include <iostream>
#include <optional>

#include "../util.h"

#include "Line.h"

/* an asterisk, contains 6 lines each 60 degrees away from adjacent lines
 *  \ /
 * -- --
 *  / \
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

    bool isShown() const;

private:
    Line m_zeroDegreeLine{};
    Line m_sixtyDegreeLine{};
    Line m_oneTwentyDegreeLine{};
    Line m_oneEightyDegreeLine{};
    Line m_twoFortyDegreeLine{};
    Line m_threeHundredDegreeLine{};

    bool m_isShown{};

    // auxiliary
    sf::RectangleShape createZeroDegreeLine() const;
    sf::RectangleShape createSixtyDegreeLine() const;
    sf::RectangleShape createOneTwentyDegreeLine() const;
    sf::RectangleShape createOneEightyDegreeLine() const;
    sf::RectangleShape createTwoFortyDegreeLine() const;
    sf::RectangleShape createThreeHundredDegreeLine() const;
};

#endif
