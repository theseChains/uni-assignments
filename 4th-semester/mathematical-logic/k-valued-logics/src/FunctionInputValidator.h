#ifndef FUNCTION_INPUT_VALIDATOR_H
#define FUNCTION_INPUT_VALIDATOR_H

#include <string>

bool functionIsValid(const std::string& function, int numberOfValues, int numberOfVariables);

bool bracketsAreValid(const std::string& function);
bool numbersAreValid(const std::string& function, int numberOfValues);
bool symbolsAreValid(const std::string& function, int numberOfVariables);

#endif
