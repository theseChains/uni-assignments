#include <iostream>

#include "Calculations.hpp"

double getFirstApproximation(double firstX)
{
    return getNextForIterativeMethod(firstX);
}

int main()
{
    double firstX{ 2 };
    double firstApproximation{ getFirstApproximation(firstX) };
    std::cout << "x1 = " << firstApproximation << '\n';

    int aprioryEstimate{ getAprioryEstimate(firstX, firstApproximation) };
    double xDifference{ std::abs(firstX - firstApproximation) };
    std::cout << "|x0 - x1| = " << xDifference << '\n';
    std::cout << "apriory estimate = " << aprioryEstimate << " iterations\n";

    int aposterioryEstimate{ getAposterioryEstimate(firstX) };
    std::cout << "aposteriory estimate = " << aposterioryEstimate
              << " iterations\n";

    return 0;
}
