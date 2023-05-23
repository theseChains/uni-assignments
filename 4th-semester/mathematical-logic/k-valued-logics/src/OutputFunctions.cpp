#include "ExpressionParser.h"
#include "OutputFunctions.h"

#include <iomanip>
#include <iostream>
#include <vector>

void printAvailableOperations()
{
    std::cout << "\navailable operations:\n";
    std::cout << "raising to the power of 4: x^\n";
    std::cout << "implication: x > y\n\n";
}

void printResultTable(const std::vector<int>& values, int numberOfValues, int numberOfVariables)
{
    if (numberOfVariables == 1)
        printSingleVariableResults(values, numberOfValues);
    else if (numberOfVariables == 2)
        printMultipleVariableResults(values, numberOfValues);
}

void printSingleVariableResults(const std::vector<int>& values, int numberOfValues)
{
    std::cout << std::setw(4) << 'x' << std::string(3, ' ') << '|' << std::string(4, ' ')
        << "f(x)\n";
    for (int currentX{ 0 }, i{ 0 }; currentX < numberOfValues; ++currentX, ++i)
    {
        std::cout << std::setw(4) << currentX << std::string(3, ' ') << '|' << std::string(3, ' ')
            << std::setw(4) << values[i] << '\n';
    }
}

void printMultipleVariableResults(const std::vector<int>& values, int numberOfValues)
{
    std::cout << std::setw(4) << 'x' << std::string(3, ' ') << '|' << std::setw(4) << 'y'
        << std::string(3, ' ') << '|' << std::string(3, ' ') << "f(x,y)\n";
    int index{ 0 };
    for (int currentX{ 0 }; currentX < numberOfValues; ++currentX)
    {
        for (int currentY{ 0 }; currentY < numberOfValues; ++currentY, ++index)
        {
            std::cout << std::setw(4) << currentX << std::string(3, ' ') << '|'
                << std::setw(4) << currentY << std::string(3, ' ') << '|' << std::setw(7)
                    << values[index] << '\n';
        }
    }
}

void printPcnfAnalogue(const std::vector<int>& values, int numberOfValues, int numberOfVariables)
{
    std::cout << "pcnf analogue: ";
    if (numberOfVariables == 1)
        printPcnfForSingleVariable(values, numberOfValues);
    else if (numberOfVariables == 2)
        printPcnfForMultipleVariables(values, numberOfValues);
    std::cout << '\n';
}

void printPcnfForSingleVariable(const std::vector<int>& values, int numberOfValues)
{
    for (std::size_t i{ 0 }; i < values.size(); ++i)
    {
        if (values[i] == 0)
            std::cout << "~J" << i << "(x)";
        else if (values[i] != numberOfValues - 1)
            std::cout << '(' << values[i] << " v ~J" << i << "(x))";

        if (i != values.size() - 1 && values[i + 1] != numberOfValues - 1) {
            std::cout << " & ";
        }
    }
}

void printPcnfForMultipleVariables(const std::vector<int>& values, int numberOfValues)
{
    int index{ 0 };
    for (int i{ 0 }; i < numberOfValues; ++i)
    {
        for (int j{ 0 }; j < numberOfValues; ++j, ++index)
        {
            if (values[index] == 0)
                std::cout << "(~J" << i << "(x) v ~J" << j << "(y))";
            else if (values[index] != numberOfValues - 1)
                std::cout << '(' << values[index] << " v ~J" << i << "(x) v ~J" << j << "(y))";
            if (index != static_cast<int>(values.size() - 1) &&
                    values[index + 1] != numberOfValues - 1) {
                std::cout << " & ";
            }
        }
    }
}
