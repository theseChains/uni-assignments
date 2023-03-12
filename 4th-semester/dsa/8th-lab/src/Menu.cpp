#include "Menu.h"
#include "LinkedList.h"

#include <iostream>
#include <optional>

void printMenu()
{
	std::cout << "\n1:  add new list\n";
	std::cout << "2:  add element to list\n";
	std::cout << "3:  print main list\n";
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

void handleNodeListAddition(NodeList* head)
{
	std::cout << "\n0 - add before specified element\n1 - add after specified element\n";
	auto option{ getOption() };
	while (!option)
		option = getOption();

	addToNodeList(head, option.value());
}

void handleListAddition(Node* head)
{
	std::cout << "\n0 - add before specified element\n1 - add after specified element\n";
	auto option{ getOption() };
	while (!option)
		option = getOption();

	addToList(head, option.value());
}

void handleListRemoval(Node* head)
{
	if (isListEmpty(head))
	{
		std::cout << "\nthe list is empty, cannot remove\n";
		return;
	}

	std::cout << "\nenter value to remove: ";
	int valueToRemove{};
	std::cin >> valueToRemove;
	removeFromList(head, valueToRemove);
}

void handleListSearch(const Node* head)
{
	if (isListEmpty(head))
	{
		std::cout << "\nthe list is empty, cannot search for elements\n";
		return;
	}

	std::cout << "\n0 - search in normal order\n1 - search in reverse order\n";
	int option{};
	std::cin >> option;

	std::cout << "enter item to find: ";
	int itemToFind{ getNumber() };
	findInList(head, itemToFind, option);
}

void handleListPrinting(NodeList* head)
{
	std::cout << '\n';
	printNodeList(head);
	std::cout << '\n';
}

void handleCommand(NodeList* head, int command)
{
	switch (command)
	{
		case 1:
			handleNodeListAddition(head);
			break;
		case 2:
			handleListAddition(head->head);
			break;
		case 3:
			handleListPrinting(head);
			break;
		case 4:
			break;
	}
}

void runMenuLoop()
{
	NodeList* head{ new NodeList{} };

	int command{};
	while (command != -1)
	{
		printMenu();
		command = getNumber();
		handleCommand(head, command);
	}
}
