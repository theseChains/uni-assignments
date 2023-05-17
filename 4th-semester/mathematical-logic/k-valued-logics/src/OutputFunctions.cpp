#include "ExpressionParser.h"
#include "OutputFunctions.h"

#include <iomanip>
#include <iostream>

void printAvailableOperations()
{
    std::cout << "\navailable operations:\n";
    std::cout << "raising to the power of 4: x^\n";
    std::cout << "implication: x > y\n\n";
}

void printResultTable(const std::string& function, int numberOfValues, int numberOfVariables)
{
    if (numberOfVariables == 1)
        printSingleVariableResults(function, numberOfValues);
    else if (numberOfVariables == 2)
        printMultipleVariableResults(function, numberOfValues);
}

void printSingleVariableResults(const std::string& function, int numberOfValues)
{
    std::cout << std::setw(4) << 'x' << std::string(3, ' ') << '|' << std::string(4, ' ')
        << "f(x)\n";
    for (int currentX{ 0 }; currentX < numberOfValues; ++currentX)
    {
        std::cout << std::setw(4) << currentX << std::string(3, ' ') << '|' << std::string(3, ' ')
            << std::setw(4) << evaluateFunction(function, currentX, 0, numberOfValues) << '\n';
    }
}

void printMultipleVariableResults(const std::string& function, int numberOfValues)
{
    std::cout << std::setw(4) << 'x' << std::string(3, ' ') << '|' << std::setw(4) << 'y'
        << std::string(3, ' ') << '|' << std::string(3, ' ') << "f(x,y)\n";
    for (int currentX{ 0 }; currentX < numberOfValues; ++currentX)
    {
        for (int currentY{ 0 }; currentY < numberOfValues; ++currentY)
        {
            std::cout << std::setw(4) << currentX << std::string(3, ' ') << '|'
                << std::setw(4) << currentY << std::string(3, ' ') << '|' << std::setw(7)
                    << evaluateFunction(function, currentX, currentY, numberOfValues) << '\n';
        }
    }
}
