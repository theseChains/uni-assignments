#include "Menu.h"
#include "Stack.h"

#include <iostream>

void printMenu()
{
	std::cout << "\n1:  push element to stack\n";
	std::cout << "2:  pop element from stack\n";
	std::cout << "3:  push random elements to stack\n";
	std::cout << "4:  print main stack\n";
	std::cout << "5:  print auxiliary stack\n";
	std::cout << "-1: exit\n";
}

int getNumber()
{
	int number{};
	std::cin >> number;
	return number;
}

void handleStackPush(Stack*& mainTop, Stack*& auxiliaryTop)
{
	int pushCommand{};
	std::cout << "\n1: create new element\n";
	std::cout << "2: push element from auxiliary stack to main stack\n";
	pushCommand = getNumber();
	switch (pushCommand)
	{
		case 1:
		{
			std::cout << "\nenter new value: ";
			int newValue = getNumber();
			pushToStack(mainTop, newValue);
			break;
		}
		case 2:
		{
			if (stackIsEmpty(auxiliaryTop))
				std::cout << "\nauxiliary stack is empty\n";
			else
				pushToStack(mainTop, auxiliaryTop->value);
		}
	}
}

void handleStackPrint(Stack* mainTop)
{
	std::cout << '\n';
	printStack(mainTop);
}

void handleCommand(Stack*& mainTop, Stack*& auxiliaryTop, int command)
{
	switch (command)
	{
		case 1:
			handleStackPush(mainTop, auxiliaryTop);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			handleStackPrint(mainTop);
			break;
		case 5:
			break;
	}
}

void runMenuLoop()
{
	Stack* mainTop{ nullptr };
	Stack* auxiliaryTop{ nullptr };

	int command{};
	while (command != -1)
	{
		printMenu();
		command = getNumber();
		handleCommand(mainTop, auxiliaryTop, command);
	}
}
