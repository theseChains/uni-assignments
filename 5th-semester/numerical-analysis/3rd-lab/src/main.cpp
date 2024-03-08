#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "Constants.hpp"
#include "Input.hpp"
#include "IterativeMethod.hpp"
#include "ModifiedNewtonsMethod.hpp"
#include "NewtonsMethod.hpp"

int main()
{
    std::ofstream outputFile{ "output.csv" };
    outputFile << std::fixed;
    outputFile << std::setprecision(12);

    std::cout << "x0 = ";
    double firstX{};
    std::cin >> firstX;

    std::cout << "y0 = ";
    double firstY{};
    std::cin >> firstY;

    runIterativeMethod(outputFile, firstX, firstY);
    runNewtonsMethod(outputFile, firstX, firstY);
    runModifiedNewtonsMethod(outputFile, firstX, firstY);

    return 0;
}
