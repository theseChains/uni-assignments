#include "ModifiedNewtonsMethod.hpp"

#include <algorithm>
#include <iostream>
#include <cmath>

#include "Calculations.hpp"
#include "Constants.hpp"

void printModifiedNewtonsMethodTableHeader(std::ofstream& outputFile,
                                           const double epsilon)
{
    outputFile << "Модифицированный метод Ньютона\n";
    outputFile << "точность: " << epsilon << ",k + 1" << ',' << "x_k" << ','
               << "x_k+1" << ',' << "|x_k+1 - x_k|" << ',' << "y_k" << ','
               << "y_k+1" << ',' << "|y_k+1 - y_k|" << ','
               << "\"|f1(x_k+1,y_k+1)|\"" << ',' << "\"|f2(x_k+1,y_k+1)|\"\n";
}

void runModifiedNewtonsMethodLoop(const double epsilon, const double delta,
                                  std::ofstream& outputFile, double lastX,
                                  double lastY)
{
    int currentIteration{ 1 };
    bool keepGoing{ true };
    double firstX{ lastX };
    bool foundMistake{ false };
    while (keepGoing)
    {
        if (2 * firstX == 1)
        {
            foundMistake = true;
            outputFile << "Итерационный процесс модифицированного метода Ньютона закончен. Матрица Якоби вырожденная\n";
            break;
        }
        if (std::isinf(lastX) || std::isinf(lastY))
        {
            foundMistake = true;
            outputFile << "Метод расходится\n";
            break;
        }

        double nextX{ getNextXForModifiedNewtonsMethod(lastX, lastY, firstX) };
        double nextY{ getNextYForModifiedNewtonsMethod(lastX, lastY, firstX) };
        double xDifference{ std::abs(nextX - lastX) };
        double yDifference{ std::abs(nextY - lastY) };
        double firstFunctionValue{ std::abs(
            getFirstFunctionValue(nextX, nextY)) };
        double secondFunctionValue{ std::abs(
            getSecondFunctionValue(nextX, nextY)) };

        outputFile << ',' << currentIteration << ',' << lastX << ',' << nextX
                   << ',' << xDifference << ',' << lastY << ',' << nextY << ','
                   << yDifference << ',' << firstFunctionValue << ','
                   << secondFunctionValue << '\n';

        lastX = nextX;
        lastY = nextY;
        ++currentIteration;

        if (xDifference <= epsilon && yDifference <= epsilon &&
            firstFunctionValue <= delta && secondFunctionValue <= delta)
        {
            keepGoing = false;
        }
    }

    if (!foundMistake)
    {
        outputFile << "Найденные корни:\n";
        outputFile << "x = " << lastX << '\n';
        outputFile << "y = " << lastY << '\n';
        outputFile << '\n';
    }
}

void runModifiedNewtonsMethod(std::ofstream& outputFile, double lastX,
                              double lastY)
{
    printModifiedNewtonsMethodTableHeader(outputFile, constants::firstEpsilon);
    runModifiedNewtonsMethodLoop(constants::firstEpsilon, constants::firstDelta,
                                 outputFile, lastX, lastY);
    printModifiedNewtonsMethodTableHeader(outputFile, constants::secondEpsilon);
    runModifiedNewtonsMethodLoop(constants::secondEpsilon,
                                 constants::secondDelta, outputFile, lastX,
                                 lastY);
}
