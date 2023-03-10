#include "Menu.h"
#include "LinkedList.h"

#include <iostream>
#include <optional>
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

std::optional<AddOption> getOption()
{
	int number{ getNumber() };
	switch (number)
	{
		case 0:
			return AddOption::beforeElement;
		case 1:
			return AddOption::afterElement;
		default:
			std::cout << "\nincorrect addition option, try again\n";
			return std::nullopt;
	}
}

void handleListAddition(LinkedList& list)
{
	if (isListFull(list))
	{
		std::cout << "\nthe list is full, cannot add\n";
		return;
	}

	if (isListEmpty(list))
		addToList(list);
	else
	{
		std::cout << "\n0 - add before specified element\n1 - add after specified element\n";
		auto option{ getOption() };
		while (!option)
			option = getOption();

		addToList(list, option.value());
	}
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
	int found{ findInList(list, itemToFind) };

	if (found != -1)
		std::cout << "\nvalue " << itemToFind << " found at index " << found << '\n';
	else
		std::cout << "\nvalue " << itemToFind << " is not in the list\n";
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
	initializeList(list);

	int command{};
	while (command != -1)
	{
		printMenu();
		command = getNumber();
		handleCommand(list, command);
	}
}
