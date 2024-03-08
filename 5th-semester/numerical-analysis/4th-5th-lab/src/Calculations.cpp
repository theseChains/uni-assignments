#include "Calculations.hpp"

#include <cmath>
#include <iostream>
#include <numbers>
#include <vector>

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
            0.000000028787 * q * (q - 1) * (q - 2) * (q - 3) * (q - 4) / 120);
}

double calculateSecondNewtonsInterpolationFormula(double x)
{
    double t{ getT(x) };
    return (0.005742490437 + (-0.000871207811) * t +
            0.000113154236 * t * (t - 1) / 2 +
            (-0.00001156004) * t * (t - 1) * (t - 2) / 6 +
            0.000000701623 * t * (t - 1) * (t - 2) * (t - 3) / 24 +
            0.000000028787 * t * (t - 1) * (t - 2) * (t - 3) * (t - 4) / 120);
}

double calculateLagrangeInterpolationFormula(double x)
{
    return (
        -302.6440421333 * (x - 2.65) * (x - 2.7) * (x - 2.75) * (x - 2.8) * (x - 2.85) +
        1327.0918506666 * (x - 2.6) * (x - 2.7) * (x - 2.75) * (x - 2.8) * (x - 2.85) +
        (-2321.903098133) * (x - 2.6) * (x - 2.65) * (x - 2.75) * (x - 2.8) *
            (x - 2.85) +
        2026.149412 * (x - 2.6) * (x - 2.65) * (x - 2.7) * (x - 2.8) * (x - 2.85) +
        (-881.8264330666) * (x - 2.6) * (x - 2.65) * (x - 2.7) * (x - 2.75) *
            (x - 2.85) +
        153.13307832 * (x - 2.6) * (x - 2.65) * (x - 2.7) * (x - 2.75) * (x - 2.8));
}

double getDerivativeValue(double x)
{
    return (-x / 3.0 * (std::pow(std::numbers::e, -(std::pow(x, 2) / 2))));
}

double getClosestX0(double x)
{
    std::vector<double> values{ 2.6, 2.65, 2.7, 2.75, 2.8, 2.85 };
    double x0{};

    for (int i{ 0 }; i < 5; ++i)
    {
        double leftDifference{ std::abs(x - values[i]) };
        double rightDifference{ std::abs(x - values[i + 1]) };
        if (std::abs(leftDifference - rightDifference) < 0.000000001)
        {
            x0 = values[i];
            break;
        }
        else if (x >= values[i] && x <= values[i + 1])
        {
            if (leftDifference < rightDifference)
                x0 = values[i];
            else
                x0 = values[i + 1];
        }
    }

    return x0;
}

double getClosestXn(double x)
{
    std::vector<double> values{ 2.6, 2.65, 2.7, 2.75, 2.8, 2.85 };
    double x0{};

    for (int i{ 0 }; i < 5; ++i)
    {
        double leftDifference{ std::abs(x - values[i]) };
        double rightDifference{ std::abs(x - values[i + 1]) };
        if (std::abs(leftDifference - rightDifference) < 0.000000001)
        {
            x0 = values[i + 1];
            break;
        }
        else if (x >= values[i] && x <= values[i + 1])
        {
            if (leftDifference < rightDifference)
                x0 = values[i];
            else
                x0 = values[i + 1];
        }
    }

    return x0;
}

double calculateDerivativeFirstNewtonsInterpolation(double x)
{
    double x0{ getClosestX0(x) };
    double q{ (x - x0) / 0.05 };
    return (1.0 / 0.05 * (-0.0013959627 + 0.000149910438 * (2 * q - 1) / 2 +
            (-0.000012934499) * (3 * q * q - 6 * q + 2) / 6 +
            0.000000672836 * (4 * q * q * q - 18 * q * q + 22 * q - 6) / 24 +
            0.000000028787 * (5 * q * q * q * q - 40 * q * q * q + 105 * q * q - 100 * q + 24) / 120));
}

double calculateDerivativeSecondNewtonsInterpolation(double x)
{
    double xn{ getClosestXn(x) };
    double t{ (x - xn) / 0.05 };
    return (1.0 / 0.05 * (-0.000871207811 + 0.000113154236 * (2 * t + 1) / 2 +
            (-0.00001156004) * (3 * t * t + 6 * t + 2) / 6 +
             0.000000701623 * (4 * t * t * t + 18 * t * t + 22 * t + 6) / 24 +
             0.000000028787 * (5 * t * t * t * t + 40 * t * t * t + 105 * t * t + 100 * t + 24) / 120));
}
