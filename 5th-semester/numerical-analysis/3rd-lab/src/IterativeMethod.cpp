#include "IterativeMethod.hpp"

#include <iostream>

#include "Calculations.hpp"
#include "Constants.hpp"

void printIterativeMethodTableHeader(std::ofstream& outputFile,
                                     const double epsilon)
{
    outputFile << "Метод простых итераций\n";
    outputFile << "точность: " << epsilon << ",k + 1" << ',' << "x_k" << ','
               << "x_k+1" << ',' << "|x_k+1 - x_k|" << ',' << "y_k" << ','
               << "y_k+1" << ',' << "|y_k+1 - y_k|" << ','
               << "\"|f1(x_k+1,y_k+1)|\"" << ',' << "\"|f2(x_k+1,y_k+1)|\"\n";
}

void runIterativeMethodLoop(const double epsilon, const double delta,
                            std::ofstream& outputFile, double lastX,
                            double lastY)
{
    int currentIteration{ 1 };
    bool keepGoing{ true };
    bool foundMistake{ false };
    while (keepGoing)
    {
        if (2 * lastX == 1)
        {
            foundMistake = true;
            outputFile << "Знаменатель обращается в 0\n";
            break;
        }

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

    if (!foundMistake)
    {
        outputFile << "Найденные корни:\n";
        outputFile << "x = " << lastX << '\n';
        outputFile << "y = " << lastY << '\n';
        outputFile << '\n';
    }
}

void runIterativeMethod(std::ofstream& outputFile, double lastX, double lastY)
{
    printIterativeMethodTableHeader(outputFile, constants::firstEpsilon);
    runIterativeMethodLoop(constants::firstEpsilon, constants::firstDelta,
                           outputFile, lastX, lastY);
    printIterativeMethodTableHeader(outputFile, constants::secondEpsilon);
    runIterativeMethodLoop(constants::secondEpsilon, constants::secondDelta,
                           outputFile, lastX, lastY);
}
