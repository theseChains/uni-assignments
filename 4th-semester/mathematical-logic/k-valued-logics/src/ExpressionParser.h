#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include <stack>
#include <string>

bool isDelimiter(char character);
bool isOperator(char operatorCharacter);
bool isUnary(char operatorCharacter);
int getPriority(char operatorCharacter);
void processOperation(std::stack<int>& operands, char operatorCharacter, int numberOfValues);

void convertPowerToBinaryOperation(std::string& functionString);
std::string convertToPostfix(std::string& functionString);
int evaluateFunction(std::string& function, int currentX, int currentY, int numberOfValues);

#endif
