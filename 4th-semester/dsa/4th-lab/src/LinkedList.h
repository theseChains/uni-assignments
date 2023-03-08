#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace constants
{
	inline constexpr int maxSize{ 5 };
}

struct LinkedList
{
	int array[constants::maxSize]{};
	int numberOfElements{ 0 };
};

bool isListEmpty(const LinkedList& list);
bool isListFull(const LinkedList& list);
void addToList(LinkedList& list, int newElement);
void removeFromList(LinkedList& list, int itemToRemove);
int findInList(LinkedList& list, int itemToFind);
void printList(const LinkedList& list);

#endif
