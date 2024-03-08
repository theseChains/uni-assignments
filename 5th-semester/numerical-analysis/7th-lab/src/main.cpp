#include <fstream>
#include <iomanip>
#include <iostream>
#include <numbers>
#include <cmath>

#include "Calculations.hpp"
#include "Constants.hpp"

int main()
{
    std::ofstream outputFile{ "output.csv" };

    outputFile << "n,m,Jточн,Jc,|Jточн - Jc|\n";
    outputFile << std::setprecision(15);
    outputFile << std::fixed;

    for (int i{ 0 }; i < 3; ++i)
    {
        std::cout << "2n = ";
        std::size_t n{};
        std::cin >> n;
        while (n % 2 == 1)
        {
            std::cout << "2n должно быть четным\n2n = ";
            std::cin >> n;
        }

        std::cout << "2m = ";
        std::size_t m{};
        std::cin >> m;
        while (m % 2 == 1)
        {
            std::cout << "2m должно быть четным\n2m = ";
            std::cin >> m;
        }

        double integralValue{ getIntegralValue((-1 + std::sqrt(17)) / 2) -
            getIntegralValue((-1 - std::sqrt(17)) / 2) };
        double simpsonValue{ simpsonFormula(n, m) };
        double simpsonDifference{ std::abs(integralValue - simpsonValue) };
        outputFile << n << ',' << m << ',' << integralValue << ',' << simpsonValue
            << ',' << simpsonDifference << '\n';
    }

    return 0;
}
