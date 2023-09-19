#include "SeidelMethod.hpp"

#include "Calculations.hpp"
#include "Constants.hpp"

void printSeidelMethodTableHeader(std::ofstream& outputFile)
{
    outputFile << "k" << ',' << "x_k" << ',' << "y_k" << ',' << "z_k" << ',' <<
        "x_k+1" << ',' << "y_k+1" << ',' << "z_k+1" << ',' << "|x_k+1 - x_k|" <<
        ',' << "|y_k+1 - y_k|" << ',' << "|z_k+1 - z_k|" << ',' << "sum\n";
}

void runSeidelMethodLoop(const double epsilon, std::ofstream& outputFile,
        double lastX, double lastY, double lastZ)
{
    int currentIteration{ 1 };
    bool keepGoing{ true };
    while (keepGoing)
    {
        double nextX{ getNextX(lastY, lastZ) };
        double nextY{ getNextY(nextX, lastZ) };
        double nextZ{ getNextZ(nextX, nextY) };

        double differenceX{ std::abs(nextX - lastX) };
        double differenceY{ std::abs(nextY - lastY) };
        double differenceZ{ std::abs(nextZ - lastZ) };

        double differenceSum{ differenceX + differenceY + differenceZ };

        outputFile << currentIteration << ',' << lastX << ',' << lastY << ',' <<
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

    outputFile << '\n';
}

void runSeidelMethod(std::ofstream& outputFile, double lastX, double lastY,
        double lastZ)
{
    printSeidelMethodTableHeader(outputFile);
    runSeidelMethodLoop(constants::firstEpsilon, outputFile,
                           lastX, lastY, lastZ);
    printSeidelMethodTableHeader(outputFile);
    runSeidelMethodLoop(constants::secondEpsilon, outputFile,
                           lastX, lastY, lastZ);
}
