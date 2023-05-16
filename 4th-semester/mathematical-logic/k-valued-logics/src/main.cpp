#include <iostream>
#include <string>

#include "UserInput.h"

void printAvailableOperations()
{
    std::cout << "\navailable operations:\n";
    std::cout << "raising to the power of 4: x^\n";
    std::cout << "implication: x => y\n\n";
}

int main()
{
    [[maybe_unused]] int numberOfValues{ getNumber('k') };
    int numberOfVariables{ getNumber('n') };

    printAvailableOperations();
    std::string function{ getFunction(numberOfVariables) };

    return 0;
}
