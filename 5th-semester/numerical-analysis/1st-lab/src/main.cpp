#include <fstream>
#include <iostream>

#include "Constants.hpp"
#include "Input.hpp"
#include "IterativeMethod.hpp"
#include "RelaxationMethod.hpp"
#include "SeidelMethod.hpp"

void printInitialInformation()
{
    std::cout << "4x - y - z = 5\n";
    std::cout << "x + 2y + z = 0\n";
    std::cout << "x - y - 3z = 4\n";
}

int main()
{
    printInitialInformation();

    std::ofstream outputFile{ "output.csv" };
    auto [firstX, firstY, firstZ]{ getInitialValues() };

    runIterativeMethod(outputFile, firstX, firstY, firstZ);
    runSeidelMethod(outputFile, firstX, firstY, firstZ);
    runRelaxationMethod(outputFile, firstX, firstY, firstZ);

    return 0;
}
