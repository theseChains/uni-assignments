#include "Menu.h"
#include "Queue.cpp"

#include <iostream>
#include <random>

namespace rnd
{
	std::mt19937 mt{ std::random_device{}() };

	int get(int min, int max)
	{
		std::uniform_int_distribution range{ min, max };
		return range(mt);
	}
}

void printMenu()
{
	std::cout << "\n1:  push element to queue\n";
	std::cout << "2:  remove element from queue\n";
	std::cout << "3:  print queue\n";
	std::cout << "-1: exit\n";
}

int getNumber()
{
	int number{};
	std::cin >> number;
	return number;
}

void handleStackPush(Queue*& queue)
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

void handleStackPop(Stack*& mainTop, Stack*& auxiliaryTop)
{
	int popCommand{};
	std::cout << "\n1: delete element from main stack\n";
	std::cout << "2: push element to auxiliary stack from main stack\n";
	popCommand = getNumber();
	switch (popCommand)
	{
		case 1:
		{
			int poppedValue{ popFromStack(mainTop) };
			std::cout << "\npopped element with value " << poppedValue << " from main stack\n";
			break;
		}
		case 2:
		{
			Stack* nodeToMove{ mainTop };
			std::cout << "\nmoved element with value " << mainTop->value << " to auxiliary stack\n";
			mainTop = mainTop->next;
			nodeToMove->next = auxiliaryTop;
			auxiliaryTop = nodeToMove;
		}
	}
}

void handleRandomStackPush(Stack*& mainTop)
{
	std::cout << "\nenter number of elements to push: ";
	int numberOfElementsToPush{ getNumber() };
	for (int i{ 0 }; i < numberOfElementsToPush; ++i)
	{
		pushToStack(mainTop, rnd::get(1, 100));
	}
}

void handleStackPrint(Stack* top)
{
	std::cout << '\n';
	printStack(top);
}

void handleCommand(Stack*& mainTop, Stack*& auxiliaryTop, int command)
{
	switch (command)
	{
		case 1:
			handleStackPush(mainTop, auxiliaryTop);
			break;
		case 2:
			handleStackPop(mainTop, auxiliaryTop);
			break;
		case 3:
			handleRandomStackPush(mainTop);
			break;
		case 4:
			handleStackPrint(mainTop);
			break;
		case 5:
			handleStackPrint(auxiliaryTop);
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
