#include <algorithm>
#include <iomanip>
#include <iostream>
#include <ranges>
#include <string>
#include <unordered_set>
#include <vector>

#include "OutputFunctions.h"
#include "ExpressionParser.h"
#include "SetPreservation.h"
#include "UserInput.h"
#include "ValueGetter.h"

int main()
{
    int numberOfValues{ getNumber('k') };
    int numberOfVariables{ getNumber('n') };

    printAvailableOperations();
    std::string function{ getFunction(numberOfVariables) };
    // todo: validate function input

    std::vector<int> values{ getFunctionValues(function, numberOfValues, numberOfVariables) };
    printResultTable(values, numberOfValues, numberOfVariables);
    printPcnfAnalogue(values, numberOfValues, numberOfVariables);
    checkForSetPreservation(values, numberOfValues);

    return 0;
}
