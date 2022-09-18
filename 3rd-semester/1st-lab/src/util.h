#ifndef UTIL_FUNCTIONS_H
#define UTIL_FUNCTIONS_H

#include <array>
#include <random>

namespace util
{
    inline constexpr int windowWidth{ 640 };
    inline constexpr int windowHeight{ 480 };

    inline constexpr std::array<int, 4> secondCircleColorComponents{ 34, 65, 89, 200 };
    inline constexpr std::array<int, 4> secondRectangleColorComponents{ 0, 176, 179, 255 };
    inline constexpr std::array<int, 4> secondLineColorComponents{ 55, 15, 0, 255 };
}

namespace component
{
    inline constexpr int red{ 0 };
    inline constexpr int green{ 1 };
    inline constexpr int blue{ 2 };
    inline constexpr int alpha{ 3 };
}

namespace rnd
{
    inline std::mt19937 mt{ std::random_device{}() };
    
    int getNumber(int min, int max);
}

namespace workspace
{
    inline bool circles{ true };
    inline bool rectangles{ false };
    inline bool lines{ false };

    void shift();
}

#endif
