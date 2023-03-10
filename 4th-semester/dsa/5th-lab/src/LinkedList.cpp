#include "LinkedList.h"

#include <iostream>

void initializeList(LinkedList& list)
{
	list.array[0] = { 0, 0 };
	for (int i{ 1 }; i < constants::maxSize + 1; ++i)
		list.array[i].next = -1;
}

bool isListEmpty(const LinkedList& list)
{
	return (list.size == 0);
}

bool isListFull(const LinkedList& list)
{
	return (list.size == constants::maxSize);
}

int findPreviousIndex(const LinkedList& list, int itemToFind)
{
	int previousIndex{ 0 };
	int currentIndex{ list.array[0].next };
	while (currentIndex != 0)
	{
		if (list.array[currentIndex].value == itemToFind)
			break;
		currentIndex = list.array[currentIndex].next;
		previousIndex = list.array[previousIndex].next;
	}

	return previousIndex;
}

void addToList(LinkedList& list, AddOption option)
{
	if (isListFull(list))
	{
		std::cout << "the list is full\n";
		return;
	}

	if (isListEmpty(list))
	{
		std::cout << "\nenter new value: ";
		int newItem{};
		std::cin >> newItem;

		list.array[0].next = 1;
		list.array[1].value = newItem;
		list.array[1].next = 0;
	}
	else
	{
		if (option == AddOption::beforeElement)
		{
			std::cout << "\nenter value before which to insert the element: ";
			int value{};
			std::cin >> value;

			int valueIndex{ findInList(list, value) };
			if (valueIndex == -1)
			{
				std::cout << "\nthe value was not found\n";
				return;
			}
			int previousIndex{ findPreviousIndex(list, value) };

			std::cout << "\nenter new value: ";
			int newItem{};
			std::cin >> newItem;

			int freeIndex{ 1 };
			for (; freeIndex < constants::maxSize + 1; ++freeIndex)
				if (list.array[freeIndex].next == -1) break;

			list.array[freeIndex].next = valueIndex;
			list.array[freeIndex].value = newItem;
			list.array[previousIndex].next = freeIndex;
		}
		else if (option == AddOption::afterElement)
		{
			std::cout << "\nenter value after which to insert the element: ";
			int value{};
			std::cin >> value;

			int valueIndex{ findInList(list, value) };
			if (valueIndex == -1)
			{
				std::cout << "\nthe value was not found\n";
				return;
			}

			std::cout << "\nenter new value: ";
			int newItem{};
			std::cin >> newItem;

			int freeIndex{ 1 };
			for (; freeIndex < constants::maxSize + 1; ++freeIndex)
				if (list.array[freeIndex].next == -1) break;

			list.array[freeIndex].next = list.array[valueIndex].next;
			list.array[valueIndex].next = freeIndex;
			list.array[freeIndex].value = newItem;
		}
	}

	++list.size;
}

void removeFromList(LinkedList& list, int itemToRemove)
{
	if (isListEmpty(list))
	{
		std::cout << "the list is empty, cannot remove\n";
		return;
	}

	int foundIndex{ findInList(list, itemToRemove) };
	if (foundIndex == -1)
	{
		std::cout << "\ncouldn't find the value " << itemToRemove << " in list\n";
		return;
	}

	int previousIndex{ findPreviousIndex(list, itemToRemove) };
	list.array[previousIndex].next = list.array[foundIndex].next;
	list.array[foundIndex].next = -1;
	--list.size;
}

int findInList(const LinkedList& list, int itemToFind)
{
	for (int index{ list.array[0].next }; index != 0; index = list.array[index].next)
	{
		if (list.array[index].value == itemToFind)
			return index;
	}

	return -1;
}

void printList(const LinkedList& list)
{
	if (isListEmpty(list))
	{
		std::cout << "the list is empty";
		return;
	}

	for (int i{ list.array[0].next }; i != 0; i = list.array[i].next)
		std::cout << list.array[i].value << ' ';
}
