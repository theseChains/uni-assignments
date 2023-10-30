#include "Calculations.hpp"

#include "Constants.hpp"

double getFunctionValue(double x)
{
    return (std::pow(2, x) + 5 * x - 10);
}

double getLeftEndApproximationNu()
{
    return (std::log(2) + 5);
}

double getRightEndApproximationMu()
{
    return (std::pow(2, 2) * std::log(2) + 5);
}

double getNextForIterativeMethod(double lastX)
{
    double functionValue{ getFunctionValue(lastX) };
    double mu{ getRightEndApproximationMu() };
    return (lastX - 1 / mu * functionValue);
}

double getContractionCoefficient()
{
    double mu{ getRightEndApproximationMu() };
    double nu{ getLeftEndApproximationNu() };
    return (1 - nu / mu);
}

double logWithBase(double number, double base)
{
    return (std::log2(number) / std::log2(base));
}

int getAprioryEstimate(double firstX, double firstApproximation)
{
    double xDifference{ std::abs(firstX - firstApproximation) };
    double contractionCoefficient{ getContractionCoefficient() };
    double logNumerator{ constants::epsilon * (1 - contractionCoefficient) };
    double logNumber{ logNumerator / xDifference };
    int aprioryEstimate{
        static_cast<int>(std::floor(
                    logWithBase(logNumber, contractionCoefficient))) + 1 };

    return aprioryEstimate;
}

int getAposterioryEstimate(double firstX)
{
    double contractionCoefficient{ getContractionCoefficient() };

    bool keepGoing{ true };
    double lastX{ firstX };
    int numberOfIterations{ 0 };
    while (keepGoing)
    {
        double nextX{ getNextForIterativeMethod(lastX) };
        double xDifference{ std::abs(nextX - lastX) };
        if (contractionCoefficient / (1 - contractionCoefficient) *
                xDifference <= constants::epsilon)
        {
            keepGoing = false;
        }

        lastX = nextX;
        ++numberOfIterations;
    }

    return numberOfIterations;
}
