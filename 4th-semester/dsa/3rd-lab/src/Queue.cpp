#include "Queue.h"

#include <iostream>

bool isQueueEmpty(const Queue& queue)
{
	return (queue.front == nullptr && queue.back == nullptr);
}

void pushToQueue(Queue& queue, char newItem)
{
	Node* newNode{ new Node{} };
	newNode->item = newItem;
	newNode->next = nullptr;
	if (queue.front == nullptr && queue.back == nullptr)
	{
		queue.front = newNode;
		queue.back = newNode;
		queue.back->next = queue.front;
	}
	else
	{
		queue.back->next = newNode;
		queue.back = newNode;
		newNode->next = queue.front;
	}
}

std::optional<char> removeFromQueue(Queue& queue)
{
	if (isQueueEmpty(queue))
	{
		return std::nullopt;
	}

	Node* nodeToRemove{ queue.front };
	char removedElement{ nodeToRemove->item };
	if (queue.front == queue.back)
	{
		queue.front = nullptr;
		queue.back = nullptr;
		delete nodeToRemove;
	}
	else
	{
		queue.front = queue.front->next;
		queue.back->next = queue.front;
		delete nodeToRemove;
	}

	return removedElement;
}

void printQueue(const Queue& queue)
{
	if (isQueueEmpty(queue))
	{
		std::cerr << "The queue is empty";
		return;
	}

	Node* current{ queue.front };
	do
	{
		std::cout << current->item << ' ';
		current = current->next;
	}
	while (current != queue.front);
}
