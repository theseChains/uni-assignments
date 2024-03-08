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
    return (lastX - (1 / (2 * lastX - 1)) * (std::pow(lastX, 2) + lastY - 6) +
            (1 / (2 * lastX - 1)) * (lastX + lastY - 4));
}

double getNextYForIterativeMethod(double lastX, double lastY)
{
    return (lastY + (1 / (2 * lastX - 1)) * (std::pow(lastX, 2) + lastY - 6) +
            (-2 * lastX / (2 * lastX - 1)) * (lastX + lastY - 4));
}

double getNextXForNewtonsMethod(double lastX, double lastY)
{
    return (lastX - ((1 / (2 * lastX - 1)) * (std::pow(lastX, 2) + lastY - 6) -
            (1 / (2 * lastX - 1)) * (lastX + lastY - 4)));
}

double getNextYForNewtonsMethod(double lastX, double lastY)
{
    return (lastY - ((-1 / (2 * lastX - 1)) * (std::pow(lastX, 2) + lastY - 6) +
            (2 * lastX / (2 * lastX - 1)) * (lastX + lastY - 4)));
}

double getNextXForModifiedNewtonsMethod(double lastX, double lastY,
                                        double firstX)
{
    return (lastX - ((1 / (2 * firstX - 1)) * (std::pow(lastX, 2) + lastY - 6) -
            (1 / (2 * firstX - 1)) * (lastX + lastY - 4)));
}

double getNextYForModifiedNewtonsMethod(double lastX, double lastY,
                                        double firstX)
{
    return (lastY - ((-1 / (2 * firstX - 1)) * (std::pow(lastX, 2) + lastY - 6) +
            (2 * firstX / (2 * firstX - 1)) * (lastX + lastY - 4)));
}
