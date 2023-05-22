#ifndef NORMAL_FORM_PRINTER
#define NORMAL_FORM_PRINTER

#include <vector>

void printPcnfAnalogue(const std::vector<int>& values, int numberOfValues, int numberOfVariables);
void printPcnfForSingleVariable(const std::vector<int>& values, int numberOfValues);
void printPcnfForMultipleVariables(const std::vector<int>& values, int numberOfValues);

#endif
