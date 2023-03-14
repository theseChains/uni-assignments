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
	Node* front{ nullptr };
	Node* back{ nullptr };
};

bool isQueueEmpty(const Queue& queue);
void pushToQueue(Queue& queue, char newElement);
std::optional<char> removeFromQueue(Queue& queue);
void printQueue(const Queue& queue);

#endif
