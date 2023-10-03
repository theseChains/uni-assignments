#include "Calculations.hpp"

#include <cmath>
#include <numbers>

double getFunctionValue(double x)
{
    return (2.0 * std::sin(x) + std::pow(x, 2) - 1.5);
}

double getNextXForIterativeMethod(double lastX)
{
    double functionValue{ getFunctionValue(lastX) };
    return (lastX - (-0.2 * functionValue));
}

double getNextXForNewtonsMethod(double lastX)
{
    double functionValue{ getFunctionValue(lastX) };
    double derivativeValue{ 2.0 * std::cos(lastX) + 2 * lastX };
    return (lastX - functionValue / derivativeValue);
}

double getNextXForModifiedNewtonsMethod(double lastX)
{
    double functionValue{ getFunctionValue(lastX) };
    double denominatorValue{ 1 + 2 * std::numbers::pi / 3 };
    return (lastX - functionValue / denominatorValue);
}
