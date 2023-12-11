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

    outputFile << "n,m,Jточн,,Jc,|Jточн - Jc|\n";
    outputFile << std::setprecision(15);
    outputFile << std::fixed;

    std::cout << "n = ";
    std::size_t n{};
    std::cin >> n;

    std::cout << "m = ";
    std::size_t m{};
    std::cin >> m;

    double integralValue{ getIntegralValue((-1 + std::sqrt(17)) / 2) -
                          getIntegralValue((-1 - std::sqrt(17)) / 2) };
    double simpsonValue{ simpsonFormula(n, m) };
    double simpsonDifference{ std::abs(integralValue - simpsonValue) };
    outputFile << n << ',' << m << ',' << integralValue << ',' << simpsonValue
               << ',' << simpsonDifference << '\n';

    return 0;
}
