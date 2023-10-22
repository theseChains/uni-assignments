#include "Calculations.hpp"

#include <cmath>
#include <numbers>

double getFunctionValue(double x)
{
    return (2.0 * std::sin(x) + std::pow(x, 2) - 1.5);
}

double getFirstDerivative(double x)
{
    return (2 * std::cos(x) + 2 * x);
}

double getSecondDerivative(double x)
{
    return (2 - 2 * std::sin(x));
}

double getNextXForIterativeMethod(double lastX)
{
    double functionValue{ getFunctionValue(lastX) };
    return (lastX + (-0.3 * functionValue));
}

double getNextXForNewtonsMethod(double lastX)
{
    double functionValue{ getFunctionValue(lastX) };
    double derivativeValue{ 2.0 * std::cos(lastX) + 2 * lastX };
    return (lastX - functionValue / derivativeValue);
}

double getNextXForModifiedNewtonsMethod(double lastX, double firstX)
{
    double functionValue{ getFunctionValue(lastX) };
    double denominatorValue{ getFirstDerivative(firstX) };
    return (lastX - functionValue / denominatorValue);
}
