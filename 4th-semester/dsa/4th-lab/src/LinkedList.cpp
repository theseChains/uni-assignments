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

		std::cout << "new item index: " << newItemIndex << '\n';

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
