#include "NormalForPrinter.h"

#include <iostream>

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
