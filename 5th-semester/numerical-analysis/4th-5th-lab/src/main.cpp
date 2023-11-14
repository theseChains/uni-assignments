#include <array>
#include <fstream>
#include <iostream>

#include "Constants.hpp"
#include "Calculations.hpp"

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

    outputFile << "x,y,PI(x),q\n";
    for (int i{ 0 }; i < 3; ++i)
    {
        double functionValue{ getFunctionValue(inputValues[i]) };
        double q{ getQ(inputValues[i]) };
        double interpolationFormulaValue{
            calculateFirstNewtonsInterpolationFormula(inputValues[i]) };
        outputFile << inputValues[i] << ',' << functionValue << ',' <<
            interpolationFormulaValue << ',' << q << '\n';
    }

    return 0;
}
