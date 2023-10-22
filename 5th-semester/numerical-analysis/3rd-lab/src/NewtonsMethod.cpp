#include "NewtonsMethod.hpp"

#include <iostream>

#include "Calculations.hpp"
#include "Constants.hpp"

void printNewtonsMethodTableHeader(std::ofstream& outputFile,
                                   const double epsilon)
{
    outputFile << "Метод Ньютона\n";
    outputFile << "точность: " << epsilon << ",k + 1" << ',' << "x_k" << ','
               << "x_k+1" << ',' << "|x_k+1 - x_k|" << ',' << "y_k" << ','
               << "y_k+1" << ',' << "|y_k+1 - y_k|" << ','
               << "\"|f1(x_k+1,y_k+1)|\"" << ',' << "\"|f2(x_k+1,y_k+1)|\"\n";
}

void runNewtonsMethodLoop(const double epsilon, const double delta,
                          std::ofstream& outputFile, double lastX, double lastY)
{
    int currentIteration{ 1 };
    bool keepGoing{ true };
    while (keepGoing)
    {
        double nextX{ getNextXForIterativeMethod(lastX, lastY) };
        double nextY{ getNextYForIterativeMethod(lastX, lastY) };
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
}

void runNewtonsMethod(std::ofstream& outputFile, double lastX, double lastY)
{
    printNewtonsMethodTableHeader(outputFile, constants::firstEpsilon);
    runNewtonsMethodLoop(constants::firstEpsilon, constants::firstDelta,
                         outputFile, lastX, lastY);
    printNewtonsMethodTableHeader(outputFile, constants::secondEpsilon);
    runNewtonsMethodLoop(constants::secondEpsilon, constants::secondDelta,
                         outputFile, lastX, lastY);
}
