#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

#include "Constants.hpp"

struct Coordinate
{
    double x{};
    double y{};
};

double calculateFunction(double x, double y)
{
    return (x * y - std::pow(y, 3) / std::exp(x * x));
}

double calculateExactValue(double x)
{
    return (std::sqrt((std::exp(x * x) / (2 * x + 1))));
}

double calculateRungeKuttValue(double previousY, double x, double step)
{
    double k1i{ step * calculateFunction(x, previousY) };
    double k2i{ step * calculateFunction(x + step / 2.0, previousY + k1i / 2.0) };
    double k3i{ step * calculateFunction(x + step / 2.0, previousY + k2i / 2.0) };
    double k4i{ step * calculateFunction(x + step, previousY + k3i) };

    return previousY + 1.0 / 6.0 * (k1i + 2 * k2i + 2 * k3i + k4i);
}

double calculateAdamsValue(int currentIndex, const std::vector<Coordinate>& values, double step)
{
    return (values[currentIndex].y + step / 24.0 *
            (55 * calculateFunction(values[currentIndex].x, values[currentIndex].y) -
             59 * calculateFunction(values[currentIndex - 1].x, values[currentIndex - 1].y) +
             37 * calculateFunction(values[currentIndex - 2].x, values[currentIndex - 2].y) -
             9 * calculateFunction(values[currentIndex - 3].x, values[currentIndex - 3].y)));
}

double calculateMilneValue(int currentIndex, const std::vector<Coordinate>& values, double step)
{
    double predictedY{ values[currentIndex - 3].y + 4 * step / 3 *
            (2 * calculateFunction(values[currentIndex - 2].x, values[currentIndex - 2].y) -
             calculateFunction(values[currentIndex - 1].x, values[currentIndex - 1].y) +
             2 * calculateFunction(values[currentIndex].x, values[currentIndex].y)) };
    double nextX{ values[currentIndex].x + step };

    return (values[currentIndex - 1].y + step / 3 *
            (calculateFunction(nextX, predictedY) +
             4 * calculateFunction(values[currentIndex].x, values[currentIndex].y) +
             calculateFunction(values[currentIndex - 1].x, values[currentIndex - 1].y)));
}

std::vector<Coordinate> getExactValueCalculations(int numberOfIterations, double step)
{
    std::vector<Coordinate> values(numberOfIterations + 1);
    values[0].x = constants::x0;
    values[0].y = constants::y0;

    for (int i{ 1 }; i <= numberOfIterations; ++i)
    {
        values[i].x = values[i - 1].x + step;
        values[i].y = calculateExactValue(values[i].x);
    }

    return values;
}

std::vector<Coordinate> getRungeKuttCalculations(int numberOfIterations, double step)
{
    std::vector<Coordinate> values(numberOfIterations + 1);
    values[0].x = constants::x0;
    values[0].y = constants::y0;

    for (int i{ 1 }; i <= numberOfIterations; ++i)
    {
        values[i].x = values[i - 1].x + step;
        values[i].y = calculateRungeKuttValue(values[i - 1].y, values[i - 1].x, step);
    }

    return values;
}

std::vector<Coordinate> getAdamsCalculations(int numberOfIterations, double step)
{
    std::vector<Coordinate> values(numberOfIterations + 1);
    values[0].x = constants::x0;
    values[0].y = constants::y0;

    for (int i{ 1 }; i <= numberOfIterations; ++i)
    {
        values[i].x = values[i - 1].x + step;
        if (i <= 3)
            values[i].y = calculateRungeKuttValue(values[i - 1].y, values[i - 1].x, step);
        else
            values[i].y = calculateAdamsValue(i - 1, values, step);
    }

    return values;
}

std::vector<Coordinate> getMilneCalculations(int numberOfIterations, double step)
{
    std::vector<Coordinate> values(numberOfIterations + 1);
    values[0].x = constants::x0;
    values[0].y = constants::y0;

    for (int i{ 1 }; i <= numberOfIterations; ++i)
    {
        values[i].x = values[i - 1].x + step;
        if (i <= 3)
            values[i].y = calculateRungeKuttValue(values[i - 1].y, values[i - 1].x, step);
        else
            values[i].y = calculateMilneValue(i - 1, values, step);
    }

    return values;
}

void performCalculations(std::ofstream& outputFile, int numberOfIterations)
{
    outputFile << ",x,yi,yiRK,|yi-yiRK|,yiAdams,|yi-yiAdams|,yiMilne,|yi-yiMilne|\n";
    double step{ (constants::b - constants::a) / numberOfIterations };

    std::vector<Coordinate> exactValues{ getExactValueCalculations(numberOfIterations, step) };
    std::vector<Coordinate> rungeKuttValues{ getRungeKuttCalculations(numberOfIterations, step) };
    std::vector<Coordinate> adamsValues{ getAdamsCalculations(numberOfIterations, step) };
    std::vector<Coordinate> milneValues{ getMilneCalculations(numberOfIterations, step) };

    for (int i{ 0 }; i <= numberOfIterations; ++i)
    {
        double rungeKuttDifference{ std::abs(exactValues[i].y - rungeKuttValues[i].y) };
        double adamsDifference{ std::abs(exactValues[i].y - adamsValues[i].y) };
        double milneDifference{ std::abs(exactValues[i].y - milneValues[i].y) };

        outputFile << i << ',' << exactValues[i].x << ',' << exactValues[i].y;
        outputFile << ',' << rungeKuttValues[i].y << ',' << rungeKuttDifference;
        outputFile << ',' << adamsValues[i].y << ',' << adamsDifference;
        outputFile << ',' << milneValues[i].y << ',' << milneDifference;
        outputFile << '\n';
    }
}

int main()
{
    std::ofstream outputFile{ "output.csv" };
    outputFile << std::setprecision(14);
    performCalculations(outputFile, 10);
    outputFile << '\n';
    performCalculations(outputFile, 20);

    return 0;
}
