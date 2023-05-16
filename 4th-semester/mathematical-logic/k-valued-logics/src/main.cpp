#include <iostream>
#include <limits>
#include <string>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getNumber(char numberLetter)
{
    std::cout << "enter " << numberLetter << ": ";
    while (true)
    {
        int number{};
        std::cin >> number;

        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();
            std::cout << "invalid input, enter " << numberLetter << " again: ";
        }
        else if (numberLetter == 'k' && number <= 0)
        {
            ignoreLine();
            std::cout << "k must be greater than 0, enter k again: ";
        }
        else if (numberLetter == 'n' && (number <= 0 || number >= 3))
        {
            ignoreLine();
            std::cout << "n must be greater than 0 and less than 3, enter n again: ";
        }
        else
        {
            ignoreLine();
            return number;
        }
    }
}

void printAvailableOperations()
{
    std::cout << "\navailable operations:\n";
    std::cout << "raising to the power of 4: x^\n";
    std::cout << "implication: x => y\n\n";
}

std::string getFunction(int numberOfVariables)
{
    std::cout << "enter your function:\n";
    if (numberOfVariables == 1)
        std::cout << "f(x) = ";
    else if (numberOfVariables == 2)
        std::cout << "f(x,y) = ";

    std::string function{};
    std::cin >> function;
    return function;
}

int main()
{
    [[maybe_unused]] int numberOfValues{ getNumber('k') };
    int numberOfVariables{ getNumber('n') };

    printAvailableOperations();
    std::string function{ getFunction(numberOfVariables) };

    return 0;
}
