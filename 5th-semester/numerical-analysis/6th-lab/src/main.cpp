#include <fstream>
#include <iomanip>
#include <iostream>
#include <numbers>

#include "Calculations.hpp"
#include "Constants.hpp"

int main()
{
    std::ofstream outputFile{ "output.csv" };

    outputFile << "n,J,Jтр,|J - Jтр|,Jc,|J - Jc|,Jг,|J - Jг|\n";
    outputFile << std::setprecision(15);
    outputFile << std::fixed;

    double integralValue{ getIntegralValue(std::numbers::pi / 4) - getIntegralValue(std::numbers::pi / 6) };
    double trapezoidalValue{ trapezoidalFormulaN4() };
    double trapezoidalDifference{ std::abs(integralValue - trapezoidalValue) };
    double simpsonValue{ simpsonFormulaN4() };
    double simpsonDifference{ std::abs(integralValue - simpsonValue) };
    double gaussValue{ gaussianFormulaN4() };
    double gaussDifference{ std::abs(integralValue - gaussValue) };
    outputFile << 4 << ',' << integralValue << ',' << trapezoidalValue << ','
               << trapezoidalDifference << ',' << simpsonValue << ','
               << simpsonDifference << ',' << gaussValue << ','
               << gaussDifference << '\n';

    trapezoidalValue = trapezoidalFormulaN8();
    trapezoidalDifference = std::abs(integralValue - trapezoidalValue);
    simpsonValue = simpsonFormulaN8();
    simpsonDifference = std::abs(integralValue - simpsonValue);
    gaussValue = gaussianFormulaN8();
    gaussDifference = std::abs(integralValue - gaussValue);
    outputFile << 8 << ',' << integralValue << ',' << trapezoidalValue << ','
               << trapezoidalDifference << ',' << simpsonValue << ','
               << simpsonDifference << ',' << gaussValue << ','
               << gaussDifference << '\n';

    return 0;
}
