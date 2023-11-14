#include "Calculations.hpp"

#include <cmath>
#include <numbers>

double getFunctionValue(double x)
{
    return (1.0 / 3.0 * (std::pow(std::numbers::e, -(std::pow(x, 2) / 2))));
}

double getQ(double x)
{
    return ((x - 2.6) / 0.05);
}

double getT(double x)
{
    return ((x - 2.85) / 0.05);
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

double calculateSecondNewtonsInterpolationFormula(double x)
{
    double t{ getT(x) };
    return (0.005742490437 + (-0.000871207811) * t +
            0.000113154236 * t * (t - 1) / 2 +
            (-0.00001156004) * t * (t - 1) * (t - 2) / 6 +
            0.000000701623 * t * (t - 1) * (t - 2) * (t - 3) / 24 +
            0.000000028787 * t * (t - 1) * (t - 2) * (t - 3)  * (t - 4) / 120);
}
