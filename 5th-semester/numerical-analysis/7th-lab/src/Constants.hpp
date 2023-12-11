#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <array>
#include <numbers>

namespace constants
{
    inline constexpr double a{ std::numbers::pi / 6 };
    inline constexpr double b{ std::numbers::pi / 4 };

    inline constexpr std::array<double, 4> A1{ 0.34785484, 0.65214516, 0.65214516, 0.34785484 };
    inline constexpr std::array<double, 8> A2{ 0.10122854, 0.22238104, 0.31370664, 0.36268378,
                                               0.36268378, 0.31370664, 0.22238104, 0.10122854 };

    inline constexpr std::array<double, 4> t1{ -0.86113631, -0.33998104, 0.33998104, 0.86113631 };
    inline constexpr std::array<double, 8> t2{ -0.96028986, -0.79666648, -0.52553242, -0.18343464,
                                               0.18343464, 0.52553242, 0.79666648, 0.96028986 };
}

#endif
