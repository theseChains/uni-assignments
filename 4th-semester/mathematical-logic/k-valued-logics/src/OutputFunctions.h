#ifndef OUTPUT_FUNCTIONS_H
#define OUTPUT_FUNCTIONS_H

#include <string>

void printAvailableOperations();
void printResultTable(const std::string& function, int numberOfValues, int numberOfVariables);
void printSingleVariableResults(const std::string& function, int numberOfValues);
void printMultipleVariableResults(const std::string& function, int numberOfValues);

#endif
