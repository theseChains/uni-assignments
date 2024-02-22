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
    return (y * std::cos(2 * x));
}

double calculateExactValue(double x)
{
    return (-2 * std::exp(std::sin(2 * x) / 2));
}

double calculateEulerValue(double previousY, double x, double step)
{
    return (previousY + step * calculateFunction(x, previousY));
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

std::vector<Coordinate> getEulerCalculations(int numberOfIterations, double step)
{
    std::vector<Coordinate> values(numberOfIterations + 1);
    values[0].x = constants::x0;
    values[0].y = constants::y0;

    for (int i{ 1 }; i <= numberOfIterations; ++i)
    {
        values[i].x = values[i - 1].x + step;
        values[i].y = calculateEulerValue(values[i - 1].y, values[i - 1].x, step);
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

void performCalculations(std::ofstream& outputFile, int numberOfIterations)
{
    outputFile << ",x,yi,yiEuler,|yi-yiEuler|,yiRK,|yi-yiRK|,yiAdams,|yi-yiAdams|\n";
    double step{ (constants::b - constants::a) / numberOfIterations };

    std::vector<Coordinate> exactValues{ getExactValueCalculations(numberOfIterations, step) };
    std::vector<Coordinate> eulerValues{ getEulerCalculations(numberOfIterations, step) };
    std::vector<Coordinate> rungeKuttValues{ getRungeKuttCalculations(numberOfIterations, step) };
    std::vector<Coordinate> adamsValues{ getAdamsCalculations(numberOfIterations, step) };

    for (int i{ 0 }; i <= numberOfIterations; ++i)
    {
        double eulerDifference{ std::abs(exactValues[i].y - eulerValues[i].y) };
        double rungeKuttDifference{ std::abs(exactValues[i].y - rungeKuttValues[i].y) };
        double adamsDifference{ std::abs(exactValues[i].y - adamsValues[i].y) };

        outputFile << i << ',' << exactValues[i].x << ',' << exactValues[i].y;
        outputFile << ',' << eulerValues[i].y << ',' << eulerDifference;
        outputFile << ',' << rungeKuttValues[i].y << ',' << rungeKuttDifference;
        outputFile << ',' << adamsValues[i].y << ',' << adamsDifference;
        outputFile << '\n';
    }
}

void runRungeKuttWithChangingStep(std::ofstream& outputFile, int n, double epsilon)
{
    outputFile << "epsilon: " << epsilon << '\n';
    outputFile << ",x,yi,yiRK(h),|yi-yiRK|,yiRK(2h),yiRK(2h)-yiRK(h),h\n";
    double step{ (constants::b - constants::a) / n };

    std::vector<Coordinate> rungeKuttValues(200);
    std::vector<Coordinate> rungeKuttValues2H(200);
    std::vector<Coordinate> exactValues(200);

    double currentX{ constants::x0 };
    exactValues[0].x = constants::x0;
    exactValues[0].y = constants::y0;
    rungeKuttValues[0].x = constants::x0;
    rungeKuttValues[0].y = constants::y0;
    rungeKuttValues2H[0].x = constants::x0;
    rungeKuttValues2H[0].y = constants::y0;

    double difference{ std::abs(exactValues[0].y - rungeKuttValues[0].y) };
    double difference2H{};
    int iteration{ 0 };

    outputFile << iteration++ << ',' << exactValues[0].x << ',' << exactValues[0].y;
    outputFile << ',' << rungeKuttValues[0].y << ',' << difference;
    outputFile << ",,," << step << '\n';

    exactValues[1].x = exactValues[0].x + step;
    exactValues[1].y = calculateExactValue(exactValues[1].x);

    rungeKuttValues[1].x = rungeKuttValues[0].x + step;
    rungeKuttValues[1].y = calculateRungeKuttValue(rungeKuttValues[0].y, rungeKuttValues[0].x, step);
    difference = std::abs(exactValues[1].y - rungeKuttValues[1].y);

    outputFile << iteration++ << ',' << exactValues[1].x << ',' << exactValues[1].y;
    outputFile << ',' << rungeKuttValues[1].y << ',' << difference;
    outputFile << ",,," << step << '\n';

    currentX = exactValues[1].x;

    for (int i{ 2 }; currentX < 1; i += 2)
    {
        exactValues[i].x = exactValues[i - 1].x + step;
        exactValues[i].y = calculateExactValue(exactValues[i].x);

        rungeKuttValues[i].x = rungeKuttValues[i - 1].x + step;
        rungeKuttValues[i].y = calculateRungeKuttValue(rungeKuttValues[i - 1].y, rungeKuttValues[i - 1].x, step);
        difference = std::abs(exactValues[i].y - rungeKuttValues[i].y);

        rungeKuttValues2H[i].x = rungeKuttValues2H[i - 2].x + step * 2;
        rungeKuttValues2H[i].y = calculateRungeKuttValue(rungeKuttValues2H[i - 2].y, rungeKuttValues2H[i - 2].x, step * 2);
        difference2H = std::abs(rungeKuttValues[i].y - rungeKuttValues2H[i].y);

        outputFile << iteration++ << ',' << exactValues[i].x << ',' << exactValues[i].y;
        outputFile << ',' << rungeKuttValues[i].y << ',' << difference;
        outputFile << ',' << rungeKuttValues2H[i].y << ',' << difference2H;
        outputFile << ',' << step << '\n';

        if (difference2H >= epsilon)
        {
            i -= 2;
            step /= 2;

            outputFile << iteration++ << ',' << exactValues[i].x << ',' << exactValues[i].y;
            outputFile << ',' << rungeKuttValues[i].y << ',' << difference;
            outputFile << ",,," << step << '\n';
        }

        if (exactValues[i].x + step < constants::b)
        {
            exactValues[i + 1].x = exactValues[i].x + step;
            exactValues[i + 1].y = calculateExactValue(exactValues[i + 1].x);

            rungeKuttValues[i + 1].x = rungeKuttValues[i].x + step;
            rungeKuttValues[i + 1].y = calculateRungeKuttValue(rungeKuttValues[i].y, rungeKuttValues[i].x, step);
            difference = std::abs(exactValues[i + 1].y - rungeKuttValues[i + 1].y);

            outputFile << iteration++ << ',' << exactValues[i + 1].x << ',' << exactValues[i + 1].y;
            outputFile << ',' << rungeKuttValues[i + 1].y << ',' << difference;
            outputFile << ",,," << step << '\n';
        }
        else
            break;

        currentX = exactValues[i + 1].x;
    }

    outputFile << '\n';
}

int main()
{
    std::ofstream outputFile{ "output.csv" };
    outputFile << std::setprecision(12);
    performCalculations(outputFile, 10);
    outputFile << '\n';
    performCalculations(outputFile, 20);
    outputFile << '\n';
    runRungeKuttWithChangingStep(outputFile, 10, 1e-6);
    runRungeKuttWithChangingStep(outputFile, 20, 9e-8);

    return 0;
}
