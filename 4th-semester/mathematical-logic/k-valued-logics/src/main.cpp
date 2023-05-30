#include "OutputFunctions.h"
#include "ExpressionParser.h"
#include "FunctionInputValidator.h"
#include "SetPreservation.h"
#include "UserInput.h"
#include "ValueGetter.h"

#include <iostream>

int main()
{
    int numberOfValues{ getNumber('k') };
    int numberOfVariables{ getNumber('n') };

    printAvailableOperations();
    std::string function{ getFunction(numberOfVariables) };
    if (functionIsValid(function, numberOfValues, numberOfVariables))
    {
        convertPowerToBinaryOperation(function);
        std::string postfixForm{ convertToPostfix(function) };
        std::vector<int> values{ getFunctionValues(postfixForm, numberOfValues, numberOfVariables) };
        printResultTable(values, numberOfValues, numberOfVariables);
        printPcnfAnalogue(values, numberOfValues, numberOfVariables);
        checkForSetPreservation(values, numberOfValues);
    }

    return 0;
}
