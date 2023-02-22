#ifndef STACK_H
#define STACK_H

struct Stack
{
	int value{};
	Stack* next{};
};

bool stackIsEmpty(Stack* top);
void pushToStack(Stack*& top, int newValue);
int popFromStack(Stack*& top);
void printStack(Stack* top);
void destructStack(Stack* top);

#endif
