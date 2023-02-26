#ifndef QUEUE_H
#define QUEUE_H

#include <optional>

struct Node
{
	char item{};
	Node* next{};
};

struct Queue
{
	struct Node* front{};
	struct Node* back{};
};

bool isQueueEmpty(const Queue& queue);
void pushToQueue(Queue& queue, char newElement);
std::optional<char> removeFromQueue(Queue& queue);
void printQueue(const Queue& queue);

#endif
