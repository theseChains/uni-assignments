#include "LinkedList.h"

#include <iostream>

bool isListEmpty(const LinkedList& list)
{
	return (list.numberOfElements == 0);
}

bool isListFull(const LinkedList& list)
{
	return (list.numberOfElements == constants::maxSize);
}

void addToList(LinkedList& list, int newItem)
{
	if (isListFull(list))
	{
		std::cout << "the list is full\n";
		return;
	}

	if (isListEmpty(list))
	{
		list.array[0] = newItem;
		++list.numberOfElements;
	}
	else
	{
		int newItemIndex{ 0 };
		int index{ 0 };
		while (list.array[index] < newItem && index < list.numberOfElements)
		{
			++newItemIndex;
			++index;
		}

		// append
		if (newItemIndex == constants::maxSize - 1)
		{
			list.array[newItemIndex] = newItem;
			++list.numberOfElements;
		}
		else
		{
			for (int i{ list.numberOfElements }; i > newItemIndex; --i)
				list.array[i] = list.array[i - 1];

			list.array[newItemIndex] = newItem;
			++list.numberOfElements;
		}
	}
}

void removeFromList(LinkedList& list, int itemToRemove)
{
	if (isListEmpty(list))
	{
		std::cout << "the list is empty, cannot remove\n";
		return;
	}

	auto found{ findInList(list, itemToRemove) };
	if (found)
	{
		--list.numberOfElements;
		for (int i{ found->second }; i < list.numberOfElements; ++i)
			list.array[i] = list.array[i + 1];
	}
	else
	{
		std::cout << "\ncouldn't find an element with given value\n";
	}
}

std::optional<std::pair<int, int>> findInList(const LinkedList& list, int itemToFind)
{
	for (int i{ 0 }; i < list.numberOfElements; ++i)
	{
		if (list.array[i] == itemToFind)
			return std::make_pair(list.array[i], i);
	}

	return std::nullopt;
}

void printList(const LinkedList& list)
{
	if (isListEmpty(list))
	{
		std::cout << "the list is empty";
		return;
	}

	for (int i{ 0 }; i < list.numberOfElements; ++i)
	{
		std::cout << list.array[i] << ' ';
	}
}
