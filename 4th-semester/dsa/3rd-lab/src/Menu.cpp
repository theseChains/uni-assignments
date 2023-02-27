#include "Menu.h"
#include "Queue.h"
#include "Settings.h"

#include <iostream>
#include <random>

#include <termios.h>
#include <unistd.h>
#include <sys/select.h>

namespace rnd
{
	std::mt19937 mt{ std::random_device{}() };

	int getNumber(int min, int max)
	{
		std::uniform_int_distribution range{ min, max };
		return range(mt);
	}

	char getCharacter(char min = 'A', char max = 'Z')
	{
		std::uniform_int_distribution range{ min, max };
		return static_cast<char>(range(mt));
	}
}

void printMenu()
{
	std::cout << "\n1:  push element to queue\n";
	std::cout << "2:  remove element from queue\n";
	std::cout << "3:  print queue\n";
	std::cout << "4:  begin real-time queue model\n";
	std::cout << "-1: exit\n";
}

char getCharacter()
{
	char character{};
	std::cin >> character;
	return character;
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
	char newValue = getCharacter();
	pushToQueue(queue, newValue);
}

void handleQueueRemoval(Queue& queue)
{
	std::optional<char> removed{ removeFromQueue(queue) };
	if (removed)
		std::cout << "\nremoved element with value " << removed.value() << " from queue\n";
	else
		std::cout << "\ncannot remove from empty queue\n";
}

void handleQueuePrint(const Queue& queue)
{
	std::cout << '\n';
	printQueue(queue);
	std::cout << '\n';
}

void handleRealTimeQueuePush(Queue& queue)
{
	int numberOfElementsToPush{ rnd::getNumber(1, 4) };
	std::cout << "\npushing " << numberOfElementsToPush << " elements to queue\n";
	for (int i{ 0 }; i < numberOfElementsToPush; ++i)
	{
		char newElement{ rnd::getCharacter() };
		pushToQueue(queue, newElement);
	}
}

void handleRealTimeQueueRemoval(Queue& queue)
{
	int numberOfElementsToRemove{ rnd::getNumber(1, 3) };
	std::cout << "\nremoving " << numberOfElementsToRemove << " elements from queue\n";
	for (int i{ 0 }; i < numberOfElementsToRemove; ++i)
	{
		if (isQueueEmpty(queue))
			break;
		removeFromQueue(queue);
	}
}

void handleRealTimeAction(Queue& queue, int randomNumber)
{
	if (randomNumber % 2 == 0)
	{
		handleRealTimeQueuePush(queue);
		handleQueuePrint(queue);
	}
	else
	{
		handleRealTimeQueueRemoval(queue);
		handleQueuePrint(queue);
	}
}

void handleRealTimeQueueModel(Queue& queue)
{
	int command{};

	termios newt{};
	termios oldt{};
	setUpTerminal(&newt, &oldt);

    fd_set readFileDescriptor{};
    timeval timeValue{};

	while (true)
	{
		FD_ZERO(&readFileDescriptor);
		FD_SET(0, &readFileDescriptor);
		timeValue.tv_sec = 0;
		timeValue.tv_usec = 0;

		int gotUserInput{ select(2, &readFileDescriptor, nullptr, nullptr, &timeValue) };

		if (gotUserInput)
		{
			command = getc(stdin);
			if (command == 'q')
				break;
		}
		else
		{
			int randomNumber{ rnd::getNumber(1, 100) };
			handleRealTimeAction(queue, randomNumber);
			sleep(1);
		}
	}

	resetTerminal(&oldt);
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
		case 4:
			handleRealTimeQueueModel(queue);
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
