#include "Calculations.hpp"
#include "Constants.hpp"

#include <cmath>
#include <iostream>
#include <numbers>
#include <vector>

double getFunctionValue(double x)
{
    return ((x + 1) * std::sin(5 * x - 2));
}

double getIntegralValue(double x)
{
    return (std::sin(5 * x - 2) / 25 - (x + 1) * std::cos(5 * x - 2) / 5);
}

double trapezoidalFormulaN4()
{
    double h1{ (constants::b - constants::a) / 4 };
    double y0{ getFunctionValue(constants::a) };
    double y1{ getFunctionValue(constants::a + h1) };
    double y2{ getFunctionValue(constants::a + h1 * 2) };
    double y3{ getFunctionValue(constants::a + h1 * 3) };
    double y4{ getFunctionValue(constants::b) };

    return h1 * ((y0 + y4) / 2 + y1 + y2 + y3);
}

double trapezoidalFormulaN8()
{
    double h2{ (constants::b - constants::a) / 8 };
    double y0{ getFunctionValue(constants::a) };
    double y1{ getFunctionValue(constants::a + h2) };
    double y2{ getFunctionValue(constants::a + h2 * 2) };
    double y3{ getFunctionValue(constants::a + h2 * 3) };
    double y4{ getFunctionValue(constants::a + h2 * 4) };
    double y5{ getFunctionValue(constants::a + h2 * 5) };
    double y6{ getFunctionValue(constants::a + h2 * 6) };
    double y7{ getFunctionValue(constants::a + h2 * 7) };
    double y8{ getFunctionValue(constants::b) };

    return h2 * ((y0 + y8) / 2 + y1 + y2 + y3 + y4 + y5 + y6 + y7);
}

double simpsonFormulaN4()
{
    double h1{ (constants::b - constants::a) / 4 };
    double y0{ getFunctionValue(constants::a) };
    double y1{ getFunctionValue(constants::a + h1) };
    double y2{ getFunctionValue(constants::a + h1 * 2) };
    double y3{ getFunctionValue(constants::a + h1 * 3) };
    double y4{ getFunctionValue(constants::b) };

    return h1 / 3.0 * (y0 + y4 + 2 * y2 + 4 * (y1 + y3));
}

double simpsonFormulaN8()
{
    double h2{ (constants::b - constants::a) / 8 };
    double y0{ getFunctionValue(constants::a) };
    double y1{ getFunctionValue(constants::a + h2) };
    double y2{ getFunctionValue(constants::a + h2 * 2) };
    double y3{ getFunctionValue(constants::a + h2 * 3) };
    double y4{ getFunctionValue(constants::a + h2 * 4) };
    double y5{ getFunctionValue(constants::a + h2 * 5) };
    double y6{ getFunctionValue(constants::a + h2 * 6) };
    double y7{ getFunctionValue(constants::a + h2 * 7) };
    double y8{ getFunctionValue(constants::b) };

    return h2 / 3.0 * (y0 + y8 + 2 * (y2 + y4 + y6) + 4 * (y1 + y3 + y5 + y7));
}

double gaussianFormulaN4()
{
    double a{ std::numbers::pi / 6 };
    double b{ std::numbers::pi / 4 };
    double sum{ 0.0 };
    for (std::size_t i = 0; i < 4; ++i)
    {
        double xi{ (b + a) / 2 + (b - a) / 2 * constants::t1[i] };
        sum += constants::A1[i] * (xi + 1) * std::sin(5 * xi - 2);
    }

    return ((constants::b - constants::a) / 2 * sum);
}

double gaussianFormulaN8()
{
    double a{ std::numbers::pi / 6 };
    double b{ std::numbers::pi / 4 };
    double sum{ 0.0 };
    for (std::size_t i = 0; i < 8; ++i)
    {
        double xi{ (b + a) / 2 + (b - a) / 2 * constants::t2[i] };
        sum += constants::A2[i] * (xi + 1) * std::sin(5 * xi - 2);
    }

    return ((constants::b - constants::a) / 2 * sum);
}
