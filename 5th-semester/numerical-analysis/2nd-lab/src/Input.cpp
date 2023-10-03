#include "Input.hpp"

#include <iostream>

std::array<double, 3> getInitialValues()
{
    std::cout << "x0 = ";
    double firstX{};
    std::cin >> firstX;

    std::cout << "y0 = ";
    double firstY{};
    std::cin >> firstY;

    std::cout << "z0 = ";
    double firstZ{};
    std::cin >> firstZ;

    return { firstX, firstY, firstZ };
}
