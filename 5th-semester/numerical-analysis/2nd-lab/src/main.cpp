#include <fstream>
#include <iostream>

#include "Constants.hpp"
#include "Input.hpp"
#include "IterativeMethod.hpp"
#include "ModifiedNewtonsMethod.hpp"
#include "NewtonsMethod.hpp"

void printInitialInformation()
{
    std::cout << "2sin(x) + x^2 - 1.5 = 0\n";
}

int main()
{
    printInitialInformation();

    std::ofstream outputFile{ "output.csv" };
    double firstX{};
    std::cin >> firstX;

    runIterativeMethod(outputFile, firstX);
    runNewtonsMethod(outputFile, firstX);
    runModifiedNewtonsMethod(outputFile, firstX);

    return 0;
}
