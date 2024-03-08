#include "ModifiedNewtonsMethod.hpp"

#include <algorithm>

#include "Calculations.hpp"
#include "Constants.hpp"

#include <iostream>

void printModifiedNewtonsMethodTableHeader(std::ofstream& outputFile,
                                           const double epsilon)
{
    outputFile << "Модифицированный метод Ньютона\n";
    outputFile << "точность: " << epsilon << ",k + 1" << ',' << "x_k" << ','
               << "x_k+1" << ',' << "|x_k+1 - x_k|" << ',' << "|f(x_k+1)|\n";
}

void runModifiedNewtonsMethodLoop(const double epsilon, const double delta,
                                  std::ofstream& outputFile, double lastX)
{
    int currentIteration{ 1 };
    bool keepGoing{ true };
    double secondDerivativeValue{ getSecondDerivative(lastX) };
    bool foundX{ true };
    double firstX{ lastX };
    if (getFunctionValue(lastX) * secondDerivativeValue < 0)
    {
        outputFile <<
            "не выполняется достаточное условие сходимости модифицированного метода Ньютона\n\n";
        keepGoing = false;
        foundX = false;
    }
    while (keepGoing)
    {
        if (getFirstDerivative(lastX) == 0.0)
        {
            outputFile << "значение производной обращается в 0\n\n";
            foundX = false;
            break;
        }

        double nextX{ getNextXForModifiedNewtonsMethod(lastX, firstX) };
        double xDifference{ std::abs(nextX - lastX) };
        double functionValue{ std::abs(getFunctionValue(nextX)) };

        outputFile << ',' << currentIteration << ',' << lastX << ',' << nextX
                   << ',' << xDifference << ',' << functionValue << '\n';

        lastX = nextX;
        ++currentIteration;

        if (xDifference <= epsilon && functionValue <= delta)
            keepGoing = false;
    }

    if (foundX)
    {
        outputFile << "Найденный приближённый корень:\n";
        outputFile << "x = " << lastX << '\n';
        outputFile << '\n';
    }
}

void runModifiedNewtonsMethod(std::ofstream& outputFile, double lastX)
{
    printModifiedNewtonsMethodTableHeader(outputFile, constants::firstEpsilon);
    runModifiedNewtonsMethodLoop(constants::firstEpsilon, constants::firstDelta,
                                 outputFile, lastX);
    printModifiedNewtonsMethodTableHeader(outputFile, constants::secondEpsilon);
    runModifiedNewtonsMethodLoop(constants::secondEpsilon,
                                 constants::secondDelta, outputFile, lastX);
}
