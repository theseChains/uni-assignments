#ifndef STACK_H
#define STACK_H

#include <optional>

struct Stack
{
	int value{};
	Stack* next{};
};

bool stackIsEmpty(Stack* top);
void pushToStack(Stack*& top, int newValue);
std::optional<int> popFromStack(Stack*& top);
void printStack(Stack* top);
void destructStack(Stack* top);

#endif
