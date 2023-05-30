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
    if (operatorCharacter == '^')
        return 2;
    else if (operatorCharacter == '>')
        return 1;

    return 0;
}

void processOperation(std::stack<int>& operands, char operatorCharacter, int numberOfValues)
{
    if (operatorCharacter == '^')
    {
        int auxiliaryOperand{ operands.top() };
        operands.pop();
        int operand{ operands.top() };
        operands.pop();
        operands.push(static_cast<int>(std::pow(operand, auxiliaryOperand)) % numberOfValues);
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

void convertPowerToBinaryOperation(std::string& functionString)
{
    for (std::size_t i{ 0 }; i < functionString.size(); ++i)
    {
        if (functionString[i] == '^')
        {
            functionString.insert(i + 1, 1, '4');
            ++i;
        }
    }
}

std::string convertToPostfix(std::string& functionString)
{
    std::stack<char> operators{};
    std::string result{};
    result.reserve(functionString.size());

    for (std::size_t i{ 0 }; i < functionString.size(); ++i)
    {
        char currentCharacter{ functionString[i] };

        if (isDelimiter(currentCharacter))
            continue;

        if (std::isalnum(currentCharacter))
            result += currentCharacter;
        else if (currentCharacter == '(')
            operators.push(currentCharacter);
        else if (currentCharacter == ')')
        {
            while (operators.top() != '(')
            {
                result += operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else if (isOperator(currentCharacter))
        {
            while (!operators.empty() &&
                    getPriority(currentCharacter) <= getPriority(operators.top()))
            {
                result += operators.top();
                operators.pop();
            }
            operators.push(currentCharacter);
        }
    }
    while (!operators.empty())
    {
        result += operators.top();
        operators.pop();
    }

    return result;
}

int evaluateFunction(std::string& functionString, int currentX, int currentY, int numberOfValues)
{
    std::stack<int> operands{};

    for (std::size_t i{ 0 }; i < functionString.size(); ++i)
    {
        char currentCharacter{ functionString[i] };
        if (isOperator(currentCharacter))
            processOperation(operands, currentCharacter, numberOfValues);
        else if (std::isdigit(currentCharacter))
        {
            int number{ 0 };
            while (i < functionString.size() && std::isdigit(functionString[i]))
                number = number * 10 + functionString[i++] - '0';
            --i;
            operands.push(number);
        }
        else if (currentCharacter == 'x')
            operands.push(currentX);
        else if (currentCharacter == 'y')
            operands.push(currentY);
    }

    return operands.top();
}
