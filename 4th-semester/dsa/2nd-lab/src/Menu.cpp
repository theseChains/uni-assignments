#include "Menu.h"
#include "Queue.h"

#include <iostream>
#include <random>

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

void handleQueuePush(Queue& queue)
{
	std::cout << "\nenter new value: ";
	int newValue = getNumber();
	pushToQueue(queue, newValue);
}

void handleQueueRemoval(Queue& queue)
{
	std::optional<int> removed{ removeFromQueue(queue) };
	if (removed)
		std::cout << "\nremoved element with value " << removed.value() << " from queue\n";
	else
		std::cout << "\ncannot remove from empty queue\n";
}

void handleQueuePrint(const Queue& queue)
{
	std::cout << '\n';
	printQueue(queue);
}

void handleCommand(Queue& queue, int command)
{
	switch (command)
	{
		case 1:
			handleQueuePush(queue);
			break;
		case 2:
			handleQueueRemoval(queue);
			break;
		case 3:
			handleQueuePrint(queue);
			break;
	}
}

void runMenuLoop()
{
	Queue queue{};

	int command{};
	while (command != -1)
	{
		printMenu();
		command = getNumber();
		handleCommand(queue, command);
	}
}
