#include "RelaxationMethod.hpp"

#include "Calculations.hpp"
#include "Constants.hpp"

#include <algorithm>

void printRelaxationMethodTableHeader(std::ofstream& outputFile)
{
    outputFile << "k" << ',' << "x_k" << ',' << "y_k" << ',' << "z_k" << ',' <<
        "R_x(k)" << ',' << "R_y(k)" << ',' << "R_z(k)" << ',' << "max|R(k)|\n";
}

double getMaxResidualValue(double residualX, double residualY, double residualZ)
{
    double absoluteResidualX{ std::abs(residualX) };
    double absoluteResidualY{ std::abs(residualY) };
    double absoluteResidualZ{ std::abs(residualZ) };

    double maxResidualAbsoluteValue{
        std::max(absoluteResidualX, absoluteResidualY) };
    maxResidualAbsoluteValue =
        std::max(maxResidualAbsoluteValue, absoluteResidualZ);

    return maxResidualAbsoluteValue;
}

void runRelaxationMethodLoop(const double epsilon, std::ofstream& outputFile,
        double x, double y, double z)
{
    int currentIteration{ 1 };
    bool keepGoing{ true };
    while (keepGoing)
    {
        double residualX{ getResidualX(x, y, z) };
        double residualY{ getResidualY(x, y, z) };
        double residualZ{ getResidualZ(x, y, z) };

        double maxResidualAbsoluteValue{
            getMaxResidualValue(residualX, residualY, residualZ) };

        outputFile << currentIteration << ',' << x << ',' << y << ',' << z <<
            ',' << residualX << ',' << residualY << ',' << residualZ << ',' <<
            maxResidualAbsoluteValue << '\n';

        ++currentIteration;
        if (std::abs(residualX) == maxResidualAbsoluteValue)
            x += residualX;
        else if (std::abs(residualY) == maxResidualAbsoluteValue)
            y += residualY;
        else if (std::abs(residualZ) == maxResidualAbsoluteValue)
            z += residualZ;

        if (std::abs(residualX) <= epsilon && std::abs(residualY) <= epsilon &&
            std::abs(residualZ) <= epsilon)
        {
            keepGoing = false;
        }
    }

    outputFile << '\n';
}

void runRelaxationMethod(std::ofstream& outputFile, double x, double y,
        double z)
{
    printRelaxationMethodTableHeader(outputFile);
    runRelaxationMethodLoop(constants::firstEpsilon, outputFile, x, y, z);
    printRelaxationMethodTableHeader(outputFile);
    runRelaxationMethodLoop(constants::secondEpsilon, outputFile, x, y, z);
}
