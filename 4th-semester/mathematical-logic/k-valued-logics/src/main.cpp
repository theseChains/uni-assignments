#include <iomanip>
#include <iostream>
#include <string>

#include "OutputFunctions.h"
#include "UserInput.h"

int main()
{
    int numberOfValues{ getNumber('k') };
    int numberOfVariables{ getNumber('n') };

    printAvailableOperations();
    std::string function{ getFunction(numberOfVariables) };
    // todo: validate function input
    
    printResultTable(function, numberOfValues, numberOfVariables);

    return 0;
}
