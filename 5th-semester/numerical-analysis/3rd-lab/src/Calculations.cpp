#include "Calculations.hpp"

#include <cmath>
#include <numbers>

double getFirstFunctionValue(double x, double y)
{
    return (std::pow(x, 2) + y - 6);
}

double getSecondFunctionValue(double x, double y)
{
    return (x + y - 4);
}

double getAlpha(double x)
{
    return (-1 / (2 * x - 1));
}

double getBeta(double x)
{
    return (1 / (2 * x - 1));
}

double getGamma(double x)
{
    return (1 / (2 * x - 1));
}

double getDelta(double x)
{
    return (-2 * x / (2 * x - 1));
}

double getNextXForIterativeMethod(double lastX, double lastY)
{
    double firstFunctionValue{ getFirstFunctionValue(lastX, lastY) };
    double secondFunctionValue{ getSecondFunctionValue(lastX, lastY) };
    return (lastX + getAlpha(lastX) * firstFunctionValue +
            getBeta(lastX) * secondFunctionValue);
}

double getNextYForIterativeMethod(double lastX, double lastY)
{
    double firstFunctionValue{ getFirstFunctionValue(lastX, lastY) };
    double secondFunctionValue{ getSecondFunctionValue(lastX, lastY) };
    return (lastY + getGamma(lastX) * firstFunctionValue +
            getDelta(lastX) * secondFunctionValue);
}

double getNextXForNewtonsMethod(double lastX, double lastY)
{
    double firstFunctionValue{ getFirstFunctionValue(lastX, lastY) };
    double secondFunctionValue{ getSecondFunctionValue(lastX, lastY) };
    return (lastX + getAlpha(lastX) * firstFunctionValue +
            getBeta(lastX) * secondFunctionValue);
}

double getNextYForNewtonsMethod(double lastX, double lastY)
{
    double firstFunctionValue{ getFirstFunctionValue(lastX, lastY) };
    double secondFunctionValue{ getSecondFunctionValue(lastX, lastY) };
    return (lastY + getGamma(lastX) * firstFunctionValue +
            getDelta(lastX) * secondFunctionValue);
}

double getNextXForModifiedNewtonsMethod(double lastX, double lastY,
                                        double firstX)
{
    double firstFunctionValue{ getFirstFunctionValue(lastX, lastY) };
    double secondFunctionValue{ getSecondFunctionValue(lastX, lastY) };
    return (lastX + getAlpha(firstX) * firstFunctionValue +
            getBeta(firstX) * secondFunctionValue);
}

double getNextYForModifiedNewtonsMethod(double lastX, double lastY,
                                        double firstX)
{
    double firstFunctionValue{ getFirstFunctionValue(lastX, lastY) };
    double secondFunctionValue{ getSecondFunctionValue(lastX, lastY) };
    return (lastY + getGamma(firstX) * firstFunctionValue +
            getDelta(firstX) * secondFunctionValue);
}
