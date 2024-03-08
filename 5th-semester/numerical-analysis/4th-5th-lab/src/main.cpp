#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "Calculations.hpp"
#include "Constants.hpp"

int main()
{
    std::ofstream outputFile{ "output.csv" };

    std::array<double, 3> inputValues{};
    for (int i{ 0 }; i < 3; ++i)
    {
        std::cout << "x" << i << " = ";
        std::cin >> inputValues[i];
        while (inputValues[i] > constants::rightEndOfRange ||
               inputValues[i] < constants::leftEndOfRange)
        {
            std::cout << "Значения должны принадлежать отрезку [2.6; 2.85]\n";
            std::cout << "x" << i << " = ";
            std::cin >> inputValues[i];
        }
    }

    outputFile << "x,y(x),PI(x),|y(x)-PI(x)|,q,PII(x),|y(x)-PII(x)|,t,L(x),|y("
                  "x) - L(x)|\n";
    outputFile << std::setprecision(25);
    outputFile << std::fixed;
    for (int i{ 0 }; i < 3; ++i)
    {
        double functionValue{ getFunctionValue(inputValues[i]) };

        double q{ getQ(inputValues[i]) };
        double firstInterpolationFormulaValue{
            calculateFirstNewtonsInterpolationFormula(inputValues[i])
        };
        double firstYDifference{ std::abs(functionValue -
                                          firstInterpolationFormulaValue) };

        double t{ getT(inputValues[i]) };
        double secondInterpolationFormulaValue{
            calculateSecondNewtonsInterpolationFormula(inputValues[i])
        };
        double secondYDifference{ std::abs(functionValue -
                                           secondInterpolationFormulaValue) };

        double lagrangeInterpolationFormulaValue{
            calculateLagrangeInterpolationFormula(inputValues[i])
        };
        double thirdYDifference{ std::abs(functionValue -
                                          lagrangeInterpolationFormulaValue) };

        outputFile << inputValues[i] << ',' << functionValue << ','
                   << firstInterpolationFormulaValue << ',' << firstYDifference
                   << ',' << q << ',' << secondInterpolationFormulaValue << ','
                   << secondYDifference << ',' << t << ','
                   << lagrangeInterpolationFormulaValue << ','
                   << thirdYDifference << '\n';
    }

    outputFile << "\nx,y'(x),(PI(x))',x0,q,|y'(x)-(PI(x))'|,(PII(x))',xn,t,|y'(x)-(PII(x))'|\n";
    for (int i{ 0 }; i < 3; ++i)
    {
        double derivativeValue{ getDerivativeValue(inputValues[i]) };

        double x0{ getClosestX0(inputValues[i]) };
        double q{ (inputValues[i] - x0) / 0.05 };
        double derivativeFirstInterpolationFormula{
            calculateDerivativeFirstNewtonsInterpolation(inputValues[i]) };
        double firstDerivativeDifference{ std::abs(derivativeValue -
                                          derivativeFirstInterpolationFormula) };

        double xn{ getClosestXn(inputValues[i]) };
        double t{ (inputValues[i] - xn) / 0.05 };
        double derivativeSecondInterpolationFormula{
            calculateDerivativeSecondNewtonsInterpolation(inputValues[i]) };
        double secondDerivativeDifference{ std::abs(derivativeValue -
                                           derivativeSecondInterpolationFormula) };

        outputFile << inputValues[i] << ',' << derivativeValue << ','
                   << derivativeFirstInterpolationFormula << ','
                   << x0 << ',' << q << ',' << firstDerivativeDifference
                   << ',' << derivativeSecondInterpolationFormula << ','
                   << xn << ',' << t << ',' << secondDerivativeDifference << '\n';
    }
    return 0;
}
