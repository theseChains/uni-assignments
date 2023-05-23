#ifndef OUTPUT_FUNCTIONS_H
#define OUTPUT_FUNCTIONS_H

#include <string>
#include <vector>

void printAvailableOperations();

void printResultTable(const std::vector<int>& values, int numberOfValues, int numberOfVariables);
void printSingleVariableResults(const std::vector<int>& values, int numberOfValues);
void printMultipleVariableResults(const std::vector<int>& values, int numberOfValues);

void printPcnfAnalogue(const std::vector<int>& values, int numberOfValues, int numberOfVariables);
void printPcnfForSingleVariable(const std::vector<int>& values, int numberOfValues);
void printPcnfForMultipleVariables(const std::vector<int>& values, int numberOfValues);

#endif
