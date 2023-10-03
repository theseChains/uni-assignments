#include "IterativeMethod.hpp"

#include "Calculations.hpp"
#include "Constants.hpp"

void printIterativeMethodTableHeader(std::ofstream& outputFile,
                                     const double epsilon)
{
    outputFile << "Метод простых итераций\n";
    outputFile << "точность: " << epsilon << ",k + 1" << ',' << "x_k" << ','
               << "x_k+1" << ',' << "|x_k+1 - x_k|" << ',' << "|f(x_k+1)\n";
}

void runIterativeMethodLoop(const double epsilon, const double delta,
                            std::ofstream& outputFile, double lastX)
{
    int currentIteration{ 1 };
    bool keepGoing{ true };
    while (keepGoing)
    {
        double nextX{ getNextXForIterativeMethod(lastX) };
        double xDifference{ std::abs(nextX - lastX) };
        double functionValue{ std::abs(getFunctionValue(nextX)) };

        outputFile << ',' << currentIteration << ',' << lastX << ',' << nextX
                   << ',' << xDifference << ',' << functionValue << '\n';

        lastX = nextX;

        if (xDifference <= epsilon || functionValue <= delta)
            keepGoing = false;
    }

    outputFile << "Найденный приближённый корень:\n";
    outputFile << "x = " << lastX << '\n';
    outputFile << '\n';
}

void runIterativeMethod(std::ofstream& outputFile, double lastX)
{
    printIterativeMethodTableHeader(outputFile, constants::firstEpsilon);
    runIterativeMethodLoop(constants::firstEpsilon, constants::firstDelta,
                           outputFile, lastX);
    printIterativeMethodTableHeader(outputFile, constants::secondEpsilon);
    runIterativeMethodLoop(constants::secondEpsilon, constants::secondDelta,
                           outputFile, lastX);
}
