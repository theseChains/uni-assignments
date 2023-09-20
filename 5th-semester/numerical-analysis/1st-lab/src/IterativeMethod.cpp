#include "IterativeMethod.hpp"

#include "Calculations.hpp"
#include "Constants.hpp"

void printIterativeMethodTableHeader(std::ofstream& outputFile, const double epsilon)
{
    outputFile << "Метод простых итераций\n";
    outputFile << "точность: " << epsilon << ",k + 1" << ',' << "x_k" << ',' <<
        "y_k" << ',' << "z_k" << ',' << "x_k+1" << ',' << "y_k+1" << ',' <<
        "z_k+1" << ',' << "|x_k+1 - x_k|" << ',' << "|y_k+1 - y_k|" << ',' <<
        "|z_k+1 - z_k|" << ',' << "sum\n";
}

void runIterativeMethodLoop(const double epsilon, std::ofstream& outputFile,
        double lastX, double lastY, double lastZ)
{
    int currentIteration{ 1 };
    bool keepGoing{ true };
    while (keepGoing)
    {
        double nextX{ getNextX(lastY, lastZ) };
        double nextY{ getNextY(lastX, lastZ) };
        double nextZ{ getNextZ(lastX, lastY) };

        double differenceX{ std::abs(nextX - lastX) };
        double differenceY{ std::abs(nextY - lastY) };
        double differenceZ{ std::abs(nextZ - lastZ) };

        double differenceSum{ differenceX + differenceY + differenceZ };

        outputFile << ',' << currentIteration << ',' << lastX << ',' << lastY << ',' <<
            lastZ << ',' << nextX << ',' << nextY << ',' << nextZ << ',' <<
            differenceX << ',' << differenceY << ',' << differenceZ << ',' <<
            differenceSum << '\n';

        ++currentIteration;
        lastX = nextX;
        lastY = nextY;
        lastZ = nextZ;

        if (differenceSum <= epsilon)
            keepGoing = false;
    }

    outputFile << "Найденные приближённые корни:\n";
    outputFile << "x = " << lastX << '\n';
    outputFile << "y = " << lastY << '\n';
    outputFile << "z = " << lastZ << '\n';
    outputFile << '\n';
}

void runIterativeMethod(std::ofstream& outputFile, double lastX, double lastY, double lastZ)
{
    printIterativeMethodTableHeader(outputFile, constants::firstEpsilon);
    runIterativeMethodLoop(constants::firstEpsilon, outputFile,
                           lastX, lastY, lastZ);
    printIterativeMethodTableHeader(outputFile, constants::secondEpsilon);
    runIterativeMethodLoop(constants::secondEpsilon, outputFile,
                           lastX, lastY, lastZ);
}
