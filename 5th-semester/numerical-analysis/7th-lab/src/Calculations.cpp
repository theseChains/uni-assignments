#include "Calculations.hpp"
#include "Constants.hpp"

#include <cmath>
#include <iostream>
#include <numbers>
#include <vector>

double getIntegralValue(double x)
{
    return (std::pow(x, 5) / 10 - std::pow(x, 4) / 4 - 11 * std::pow(x, 3) / 6 + 2 * x * x + 8 * x);
}

std::vector<std::vector<int>> getLambdaMatrix(std::size_t n, std::size_t m)
{
    std::vector<std::vector<int>> matrix(2 * m + 1, std::vector<int>(2 * n + 1, 0));

    matrix[0][0] = 1;
    matrix[2 * m][2 * n] = 1;
    matrix[2 * m][0] = 1;
    matrix[0][2 * n] = 1;

    for (std::size_t i{ 1 }; i < 2 * m; ++i)
    {
        if (((i - 1) % 2) == 1)
        {
            matrix[i][0] = 2;
            matrix[i][2 * n] = 2;
        }
        else
        {
            matrix[i][0] = 4;
            matrix[i][2 * n] = 4;
        }
    }

    for (std::size_t i{ 1 }; i < 2 * n; ++i)
    {
        if (((i - 1) % 2) == 1)
        {
            matrix[0][i] = 2;
            matrix[2 * m][i] = 2;
        }
        else
        {
            matrix[0][i] = 4;
            matrix[2 * m][i] = 4;
        }
    }

    for (std::size_t i{ 1 }; i < 2 * m; ++i)
    {
        for (std::size_t j{ 1 }; j < 2 * n; ++j)
        {
            matrix[i][j] = matrix[0][j] * matrix[i][0];
        }
    }

    return matrix;
}

double getFunctionValue(double x, double y)
{
    if (y >= x && (y <= 4 - x * x))
    {
        return (x + y);
    }

    return 0;
}

double getXi(double a, double A, std::size_t i, std::size_t n)
{
    return a + i * (A - a) / (2.0 * n);
}

double getYi(double b, double B, std::size_t j, std::size_t m)
{
    return b + j * (B - b) / (2.0 * m);
}

double simpsonFormula(std::size_t n, std::size_t m)
{
    double a{ (-1 - std::sqrt(17)) / 2 };
    double A{ (-1 + std::sqrt(17)) / 2 };
    double b{ (-1 - std::sqrt(17)) / 2 };
    double B{ 4 };

    double h{ (A - a) / (2.0 * n) };
    double k{ (B - b) / (2.0 * m) };
    std::vector<std::vector<int>> lambdaMatrix{ getLambdaMatrix(n, m) };

    double result{ 0.0 };
    for (std::size_t j{ 0 }; j <= 2 * m; ++j)
    {
        for (std::size_t i{ 0 }; i <= 2 * n; ++i)
        {
            double xi{ getXi(a, A, i, n) };
            double yi{ getYi(b, B, j, m) };
            result += h * k / 9.0 * lambdaMatrix[j][i] * getFunctionValue(xi, yi);
        }
    }

    return result;
}
