#include "Calculations.hpp"

#include <cmath>
#include <numbers>

double getFunctionValue(double x)
{
    return (1 / 3 * std::pow(std::numbers::e, -(std::pow(x, 2) / 2)));
}

double getQ(double x)
{
    return ((x - 2.6) / 0.05);
}

double calculateFirstNewtonsInterpolationFormula(double x)
{
    double q{ getQ(x) };
    return (0.01134915158 + (-0.0013959627) * q +
            0.000149910438 * q * (q - 1) / 2 +
            (-0.000012934499) * q * (q - 1) * (q - 2) / 6 +
            0.000000672836 * q * (q - 1) * (q - 2) * (q - 3) / 24 +
            0.000000028787 * q * (q - 1) * (q - 2) * (q - 3)  * (q - 4) / 120);
}
