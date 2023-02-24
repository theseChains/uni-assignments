#include "Queue.h"

#include <iostream>

bool isEmpty(const Queue& queue)
{
	return (queue.frontIndex == -1);
}

bool isFull(const Queue& queue)
{
	return (queue.frontIndex == queue.backIndex + 1 ||
			queue.frontIndex == 0 && queue.backIndex == constants::maxSize - 1);
}

void pushToQueue(Queue& queue, int newElement)
{
	if (isFull(queue))
	{
		std::cerr << "The queue is full\n";
		return;
	}

	if (queue.frontIndex == -1)
		queue.frontIndex = 0;

	queue.backIndex = (queue.backIndex + 1) % constants::maxSize;
	queue.array[queue.backIndex] = newElement;
}

int removeFromQueue(Queue& queue)
{
	if (isEmpty(queue))
	{
		std::cerr << "The queue is empty\n";
		return -1;
	}

	int elementToRemove{ queue.array[queue.frontIndex] };
	if (queue.frontIndex == queue.backIndex)
	{
		queue.frontIndex = -1;
		queue.backIndex = -1;
	}
	else
	{
		queue.frontIndex = (queue.frontIndex + 1) % constants::maxSize;
	}

	return elementToRemove;
}

void printQueue(const Queue& queue)
{
	if (isEmpty(queue))
	{
		std::cerr << "The queue is empty\n";
		return;
	}

	for (int i{ queue.frontIndex }; i < queue.backIndex; i = (i + 1) % constants::maxSize)
	{
		std::cout << queue.array[i] << ' ';
	}
	std::cout << '\n';
}
