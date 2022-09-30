#ifndef UTIL_FUNCTIONS_H
#define UTIL_FUNCTIONS_H

#include <random>
#include <string>

namespace util
{
    inline constexpr int windowWidth{ 1600 };
    inline constexpr int windowHeight{ 900 };

    inline constexpr int guiWidth{ 408 };

    inline constexpr float lineWidth{ 2.0f };

    inline constexpr int defaultShapeIndex{ 0 };
    inline constexpr int firstConstructorShapeIndex{ 1 };
    inline constexpr int secondConstructorShapeIndex{ 2 };

    inline constexpr float innerCircleRadiusMultiplier{ 0.75 };
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

    // convenience function to avoid implicit conversions
    float getFloat(int min, int max);
}

namespace mode
{
    inline bool circles{ true };
    inline bool rectangles{ false };
    inline bool lines{ false };
    inline bool rings{ false };
    inline bool asterisks{ false };

    void shift();

    std::string get();
}

#endif
