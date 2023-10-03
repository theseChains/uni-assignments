#include "NewtonsMethod.hpp"

#include "Calculations.hpp"
#include "Constants.hpp"

void printNewtonsMethodTableHeader(std::ofstream& outputFile,
                                   const double epsilon)
{
    outputFile << "Метод Ньютона\n";
    outputFile << "точность: " << epsilon << ",k + 1" << ',' << "x_k" << ','
               << "x_k+1" << ',' << "|x_k+1 - x_k|" << ',' << "|f(x_k+1)\n";
}

void runNewtonsMethodLoop(const double epsilon, const double delta,
                          std::ofstream& outputFile, double lastX)
{
    int currentIteration{ 1 };
    bool keepGoing{ true };
    while (keepGoing)
    {
        double nextX{ getNextXForNewtonsMethod(lastX) };
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

void runNewtonsMethod(std::ofstream& outputFile, double lastX)
{
    printNewtonsMethodTableHeader(outputFile, constants::firstEpsilon);
    runNewtonsMethodLoop(constants::firstEpsilon, constants::firstDelta,
                         outputFile, lastX);
    printNewtonsMethodTableHeader(outputFile, constants::secondEpsilon);
    runNewtonsMethodLoop(constants::secondEpsilon, constants::secondDelta,
                         outputFile, lastX);
}
