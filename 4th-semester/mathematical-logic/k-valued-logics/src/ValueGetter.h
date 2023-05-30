#ifndef VALUE_GETTER_H
#define VALUE_GETTER_H

#include <string>
#include <vector>

std::vector<int> getFunctionValues(std::string& function, int numberOfValues,
        int numberOfVariables);
void getSingleVariableFunctionValues(std::string& function, std::vector<int>& values,
        int numberOfValues);
void getMultipleVariableFunctionValues(std::string& function, std::vector<int>& values,
        int numberOfValues);

#endif
