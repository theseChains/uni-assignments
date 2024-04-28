#include "constants.hpp"

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

void printHeader(std::ofstream& outputFile)
{
    outputFile << "t,x = 0.0,x = 0.1,x = 0.2,x = 0.3,x = 0.4,x = 0.5,x = 0.6,x = 0.7,x = 0.8,x = 0.9,x = 1.0\n";
}

void printResult(std::ofstream& outputFile, double k, const std::vector<std::vector<double>>& result)
{
    printHeader(outputFile);
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
    return (1.3 * std::exp(-1.2 * x) + std::cos(1.3 * x));
}

double getPhiTValue(double t)
{
    return (2.9 * t + std::sin(t));
}

double getPsiTValue(double t)
{
    return (std::exp(-1.8 * t) + 2.7 * std::sin(-1.8 - 1.2 * t));
}

void runExplicitScheme(std::ofstream& outputFile)
{
    double k{ std::pow(constants::h, 2) / 6 };
    std::vector<std::vector<double>> u(constants::n + 1, std::vector<double>(constants::n + 1));

    double x0 = 0.0;
    for (int i{ 0 }; i <= constants::n; ++i)
    {
        u[i][0] = getFxValue(x0 + i * constants::h);
    }

    for (int j{ 0 }; j <= constants::n; ++j)
    {
        u[0][j] = getPhiTValue(k * j);
        u[constants::n][j] = getPsiTValue(k * j);
    }

    for (int j{ 0 }; j < constants::n; ++j)
    {
        for (int i{ 1 }; i < constants::n; ++i)
        {
            u[i][j + 1] = 1.0 / 6.0 * (u[i - 1][j] + 4 * u[i][j] + u[i + 1][j]);
        }
    }

    printResult(outputFile, k, u);
}

void runImplicitScheme(std::ofstream& outputFile, int s)
{
    double k{ std::pow(constants::h, 2) / s };

    std::vector<std::vector<double>> u(constants::n + 1, std::vector<double>(constants::n + 1));
    std::vector<std::vector<double>> a(constants::n + 1, std::vector<double>(constants::n + 1));
    std::vector<std::vector<double>> b(constants::n + 1, std::vector<double>(constants::n + 1));

    double x0 = 0.0;
    for (int i{ 0 }; i <= constants::n; ++i)
    {
        u[i][0] = getFxValue(x0 + i * constants::h);
    }

    for (int j{ 0 }; j <= constants::n; ++j)
    {
        u[0][j] = getPhiTValue(k * j);
        u[constants::n][j] = getPsiTValue(k * j);
    }

    for (int j{ 0 }; j < constants::n; ++j)
    {
        a[1][j + 1] = 1.0 / (2.0 + s);
        b[1][j + 1] = getPhiTValue(k * j) + s * u[1][j];
    }

    for (int j{ 0 }; j < constants::n; ++j)
    {
        for (int i{ 2 }; i < constants::n; ++i)
        {
            a[i][j + 1] = 1.0 / (2.0 + s - a[i - 1][j + 1]);
            b[i][j + 1] = a[i - 1][j + 1] * b[i - 1][j + 1] + s * u[i][j];
        }

        for (int i{ constants::n - 1 }; i > 0; --i)
        {
            u[i][j + 1] = a[i][j + 1] * (b[i][j + 1] + u[i + 1][j + 1]);
        }
    }

    printResult(outputFile, k, u);
}

int main()
{
    std::ofstream outputFile{ "output.csv" };

    for (int i { 0 }; i < 3; ++i)
    {
        runExplicitScheme(outputFile);
        std::cout << "S = ";
        int s{};
        std::cin >> s;
        runImplicitScheme(outputFile, s);
    }

    return 0;
}
