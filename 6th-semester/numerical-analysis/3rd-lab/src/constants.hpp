#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace constants
{
    inline constexpr double gamma{ 1.3 };
    inline constexpr double m{ -1.2 };
    inline constexpr double alpha{ 2.9 };
    inline constexpr double beta{ 1 };
    inline constexpr double bigM{ 2.7 };
    inline constexpr double bigN{ -1.8 };

    inline constexpr int l{ 1 };
    inline constexpr int n{ 10 };
    inline constexpr double h{ l / static_cast<double>(n) };
}

#endif
