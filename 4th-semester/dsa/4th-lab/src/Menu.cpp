#include "Menu.h"
#include "LinkedList.h"

#include <iostream>
#include <random>

void printMenu()
{
	std::cout << "\n1:  add element to list\n";
	std::cout << "2:  remove element from list\n";
	std::cout << "3:  print list\n";
	std::cout << "4:  search for value in list\n";
	std::cout << "-1: exit\n";
}

int getNumber()
{
	int number{};
	std::cin >> number;
	return number;
}

void handleListAddition(LinkedList& list)
{
	if (isListFull(list))
	{
		std::cout << "\nthe list is full, cannot add\n";
		return;
	}

	std::cout << "\nenter new value: ";
	int newValue{ getNumber() };
	addToList(list, newValue);
}

void handleListRemoval(LinkedList& list)
{
	if (isListEmpty(list))
	{
		std::cout << "\nthe list is empty, cannot remove\n";
		return;
	}

	std::cout << "enter item to remove: ";
	int itemToRemove{ getNumber() };
	removeFromList(list, itemToRemove);
}

void handleListSearch(const LinkedList& list)
{
	if (isListEmpty(list))
	{
		std::cout << "\nthe list is empty, cannot search for elements\n";
		return;
	}

	std::cout << "enter item to find: ";
	int itemToFind{ getNumber() };
	auto found{ findInList(list, itemToFind) };
	if (found)
		std::cout << "\nfound element with value " << found->first << " at index "<<
			found->second << '\n';
	else
		std::cout << "\ncouldn't find element with value " << itemToFind << '\n';
}

void handleListPrinting(const LinkedList& list)
{
	std::cout << '\n';
	printList(list);
	std::cout << '\n';
}

void handleCommand(LinkedList& list, int command)
{
	switch (command)
	{
		case 1:
			handleListAddition(list);
			break;
		case 2:
			handleListRemoval(list);
			break;
		case 3:
			handleListPrinting(list);
			break;
		case 4:
			handleListSearch(list);
			break;
	}
}

void runMenuLoop()
{
	LinkedList list{};

	int command{};
	while (command != -1)
	{
		printMenu();
		command = getNumber();
		handleCommand(list, command);
	}
}
