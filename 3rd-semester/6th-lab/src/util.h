#ifndef UTIL_FUNCTIONS_H
#define UTIL_FUNCTIONS_H

#include <random>
#include <string>

namespace util
{
    inline constexpr int windowWidth{ 1600 };
    inline constexpr int windowHeight{ 900 };

    inline constexpr int guiWidth{ 408 };

    inline constexpr int defaultShapeIndex{ 0 };
    inline constexpr int firstConstructorShapeIndex{ 1 };
    inline constexpr int secondConstructorShapeIndex{ 2 };

    inline constexpr int circleIndex{ 1 };
    inline constexpr int rectangleIndex{ 2 };
    inline constexpr int ellipseIndex{ 3 };
    inline constexpr int quadrangleIndex{ 4 };
    inline constexpr int rhombusIndex{ 5 };
    inline constexpr int trapezoidIndex{ 6 };
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

    float getRealNumber(float min, float max);
}

namespace mode
{
    inline bool all{ true };
    inline bool circular{ false };
    inline bool quadrangular{ false };

    void shift();

    std::string get();
}

#endif
