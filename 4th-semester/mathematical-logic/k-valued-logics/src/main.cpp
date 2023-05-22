#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "OutputFunctions.h"
#include "ExpressionParser.h"
#include "NormalForPrinter.h"
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

    return 0;
}
