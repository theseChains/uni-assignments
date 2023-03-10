#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <optional>
#include <tuple>

namespace constants
{
	inline constexpr int maxSize{ 5 };
}

enum class AddOption
{
	beforeElement,
	afterElement
};

struct Node
{
	int value{};
	int next{};
};

struct LinkedList
{
	Node array[constants::maxSize + 1]{};
	int size{ 0 };
};

void initializeList(LinkedList& list);
bool isListEmpty(const LinkedList& list);
bool isListFull(const LinkedList& list);
void addToList(LinkedList& list, int newElement, AddOption option = AddOption::afterElement);
void removeFromList(LinkedList& list, int itemToRemove);
int findInList(const LinkedList& list, int itemToFind);
void printList(const LinkedList& list);

#endif
