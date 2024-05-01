#include "constants.hpp"

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

void printHeader(std::ofstream& outputFile)
{
    outputFile << "t,x = 0.0,x = 0.1,x = 0.2,x = 0.3,x = 0.4,x = 0.5,x = 0.6,x = 0.7,x = 0.8,x = 0.9,x = 1.0\n";
}

void printResult(std::ofstream& outputFile, double k,
        const std::vector<std::vector<double>>& result,
        const std::vector<double>& virtualResult)
{
    printHeader(outputFile);

    outputFile << "Вирт. слой,,";
    for (int i{ 1 }; i < constants::n; ++i)
    {
        outputFile << virtualResult[i] << ',';
    }
    outputFile << '\n';

    for (int j{ 0 }; j <= constants::n; ++j)
    {
        outputFile << k * j << ',';
        for (int i{ 0 }; i <= constants::n; ++i)
        {
            outputFile << result[i][j] << ',';
        }
        outputFile << '\n';
    }
    outputFile << '\n';
}

double getFxValue(double x)
{
    return (constants::gamma * std::exp(constants::m * x) + std::cos(constants::gamma * x));
}

double getBigFxValue(double x)
{
    return (constants::alpha * std::exp(x) + std::cos(constants::gamma * x));
}

double getPhiTValue(double t)
{
    return (constants::alpha * t + std::sin(constants::beta * t));
}

double getPsiTValue(double t)
{
    return (std::exp(constants::bigN * t) + constants::bigM * std::sin(constants::bigN - constants::m * t));
}

void calculateAndPrintResult(std::ofstream& outputFile)
{
    std::vector<std::vector<double>> u(constants::n + 1, std::vector<double>(constants::n + 1));
    std::vector<double> virtualU(constants::n + 1);

    double x0{ 0.0 };
    for (int i{ 0 }; i <= constants::n; ++i)
    {
        u[i][0] = getFxValue(x0 + i * constants::h);
    }

    double k{ constants::h };
    for (int j{ 0 }; j <= constants::n; ++j)
    {
        u[0][j] = getPhiTValue(k * j);
        u[constants::n][j] = getPsiTValue(k * j);
    }

    for (int i{ 1 }; i < constants::n; ++i)
    {
        virtualU[i] = u[i][0] - k * getBigFxValue(x0 + i * constants::h);
    }

    for (int i{ 1 }; i < constants::n; ++i)
    {
        u[i][1] = u[i + 1][0] + u[i - 1][0] - virtualU[i];
    }

    for (int j{ 1 }; j < constants::n; ++j)
    {
        for (int i{ 1 }; i < constants::n; ++i)
        {
            u[i][j + 1] = u[i + 1][j] + u[i - 1][j] - u[i][j - 1];
        }
    }

    printResult(outputFile, k, u, virtualU);
}

int main()
{
    std::ofstream outputFile{ "output.csv" };
    calculateAndPrintResult(outputFile);

    return 0;
}
