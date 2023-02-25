#include "Stack.h"

#include <iostream>

bool stackIsEmpty(Stack* top)
{
	return (top == nullptr);
}

void pushToStack(Stack*& top, int newValue)
{
	Stack* newElement{ new Stack{} };
	newElement->value = newValue;
	newElement->next = top;
	top = newElement;
}

std::optional<int> popFromStack(Stack*& top)
{
	if (stackIsEmpty(top))
	{
		std::cerr << "Cannot pop from empty stack\n";
		return 0;
	}

	Stack* temporary{ top };
	int value{ top->value };
	top = top->next;
	delete temporary;

	return value;
}

void printStack(Stack* top)
{
	if (stackIsEmpty(top))
	{
		std::cerr << "The stack is empty\n";
		return;
	}

	std::cout << "Stack elements: ";
	Stack* current{ top };
	while (current != nullptr)
	{
		std::cout << current->value << ' ';
		current = current->next;
	}
	std::cout << '\n';
}

void destructStack(Stack* top)
{
	if (!stackIsEmpty(top))
	{
		Stack* previous{ top };
		Stack* current{ top };
		while (current != nullptr)
		{
			current = current->next;
			delete previous;
			previous = current;
		}
	}
}
