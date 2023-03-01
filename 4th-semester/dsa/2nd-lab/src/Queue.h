#ifndef QUEUE_H
#define QUEUE_H

#include <optional>

namespace constants
{
	inline constexpr int maxSize{ 4 };
}

struct Queue
{
	int array[constants::maxSize]{};
	int frontIndex{ -1 };
	int backIndex{ -1 };
};

bool isQueueEmpty(const Queue& queue);
bool isQueueFull(const Queue& queue);
void pushToQueue(Queue& queue, int newElement);
std::optional<int> removeFromQueue(Queue& queue);
void printQueue(const Queue& queue);

#endif
