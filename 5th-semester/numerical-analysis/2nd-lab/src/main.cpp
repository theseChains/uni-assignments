#include <fstream>
#include <iostream>

#include "Constants.hpp"
#include "Input.hpp"
#include "IterativeMethod.hpp"
#include "ModifiedNewtonsMethod.hpp"
#include "NewtonsMethod.hpp"

#include <cmath>

void printInitialInformation()
{
    std::cout << "2sin(x) + x^2 - 1.5 = 0\n";
}

int main()
{
    printInitialInformation();

    std::ofstream outputFile{ "output.csv" };

    std::cout << "x0 = ";
    double firstX{};
    std::cin >> firstX;

    if (firstX < constants::leftBorder || firstX > constants::rightBorder)
    {
        std::cerr << "x0 не принадлежит отрезку [a, b] = [0.5, 1.0]\n";
        return 1;
    }

    runIterativeMethod(outputFile, firstX);
    runNewtonsMethod(outputFile, firstX);
    runModifiedNewtonsMethod(outputFile, firstX);

    return 0;
}
