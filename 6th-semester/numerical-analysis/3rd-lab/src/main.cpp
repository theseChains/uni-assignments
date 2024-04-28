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
    return (constants::gamma * std::exp(constants::m * x) + std::cos(constants::gamma * x));
}

double getPhiTValue(double t)
{
    return (constants::alpha * t + std::sin(constants::beta * t));
}

double getPsiTValue(double t)
{
    return (std::exp(constants::bigN * t) + constants::bigM * std::sin(constants::bigN - constants::m * t));
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

    outputFile << "Явная схема" << ',' << "шаг по t:," << k << '\n';
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

    outputFile << "Неявная схема, s = " << s << ',' << "шаг по t:," << k << '\n';
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
