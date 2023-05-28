#include "ExpressionParser.h"
#include "Constants.h"

#include <cmath>
#include <iostream>

bool isDelimiter(char character)
{
    return character == ' ';
}

bool isOperator(char operatorCharacter)
{
    return operatorCharacter == '^' || operatorCharacter == '>';
}

bool isUnary(char operatorCharacter)
{
    return operatorCharacter == '^';
}

int getPriority(char operatorCharacter)
{
    // unary
    if (operatorCharacter < 0)
        return 2;
    else if (operatorCharacter == '>')
        return 1;

    return -1;
}

void processOperation(std::stack<int>& operands, char operatorCharacter, int numberOfValues)
{
    if (operatorCharacter == '^')
    {
        int operand{ operands.top() };
        operands.pop();
        operands.push(static_cast<int>(std::pow(operand, constants::power)) % numberOfValues);
    }
    else
    {
        int rightOperand{ operands.top() };
        operands.pop();
        int leftOperand{ operands.top() };
        operands.pop();
        if (leftOperand < rightOperand)
            operands.push(numberOfValues - 1);
        else if (leftOperand >= rightOperand)
            operands.push(numberOfValues - 1 - leftOperand + rightOperand);
    }
}

int evaluateFunction(const std::string& functionString, int currentX, int currentY,
        int numberOfValues)
{
    std::stack<int> operands{};
    std::stack<char> operators{};
    bool mayBeUnary{ true };
    for (std::size_t i{ 0 }; i < functionString.size(); ++i)
    {
        if (isDelimiter(functionString[i]))
            continue;

        if (functionString[i] == '(')
        {
            operators.push('(');
            mayBeUnary = true;
        }
        else if (functionString[i] == ')')
        {
            while (operators.top() != '(')
            {
                processOperation(operands, operators.top(), numberOfValues);
                operators.pop();
            }
            operators.pop();
            mayBeUnary = false;
        }
        else if (isOperator(functionString[i]))
        {
            char currentOperator{ functionString[i] };
            if (mayBeUnary && isUnary(functionString[i]))
                currentOperator = -currentOperator;

            while (!operators.empty() &&
                ((currentOperator >= 0 && getPriority(operators.top()) >= getPriority(currentOperator)) ||
                 (currentOperator < 0 && getPriority(operators.top()) > getPriority(currentOperator))))
            {
                processOperation(operands, currentOperator, numberOfValues);
                operators.pop();
            }
            operators.push(functionString[i]);
            mayBeUnary = true;
        }
        else if (functionString[i] == 'x')
        {
            operands.push(currentX);
            mayBeUnary = false;
        }
        else if (functionString[i] == 'y')
        {
            operands.push(currentY);
            mayBeUnary = false;
        }
        else
        {
            int number{ 0 };
            while (i < functionString.size() && std::isalnum(functionString[i]))
                number = number * 10 + functionString[i++] - '0';
            --i;
            operands.push(number);
            mayBeUnary = false;
        }
    }

    while (!operators.empty())
    {
        processOperation(operands, operators.top(), numberOfValues);
        operators.pop();
    }

    return operands.top();
}
