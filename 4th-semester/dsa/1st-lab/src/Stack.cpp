#include "Stack.h"

#include <iostream>

bool stackIsEmpty(Stack* top)
{
	return (top == nullptr);
}

void pushToStack(Stack** top, int newValue)
{
	Stack* newElement{ new Stack{} };
	newElement->value = newValue;
	newElement->next = *top;
	*top = newElement;
}

void popFromStack(Stack* top)
{
	if (stackIsEmpty(top))
	{
		std::cerr << "Cannot pop from empty stack\n";
		return;
	}

	Stack* temporary{ top };
	top = top->next;
	delete temporary;
}

void printStack(Stack* top)
{
	if (stackIsEmpty(top))
	{
		std::cout << "The stack is empty\n";
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
