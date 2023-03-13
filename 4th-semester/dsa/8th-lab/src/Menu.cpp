#include "Menu.h"
#include "LinkedList.h"

#include <iostream>
#include <optional>

void printMenu()
{
	std::cout << "\n1:  add new list\n";
	std::cout << "2:  add element to list\n";
	std::cout << "3:  print main list\n";
	std::cout << "4:  remove a list by id\n";
	std::cout << "5:  remove an element from a list\n";
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

void handleListAddition(NodeList* head)
{
	std::cout << "\n0 - add before specified element\n1 - add after specified element\n";
	auto option{ getOption() };
	while (!option)
		option = getOption();

	std::cout << "\nenter the id of the list: ";
	int listId{};
	std::cin >> listId;

	NodeList* current{ head->next };
	while (current != nullptr && current->head->value != listId)
		current = current->next;

	if (current == nullptr)
	{
		std::cout << "\ncouldn't find the list with the given id\n";
		return;
	}

	addToList(current->head, option.value());
}

void handleNodeListRemoval(NodeList* head)
{
	if (isNodeListEmpty(head))
	{
		std::cout << "\nthe list of lists is empty, cannot remove\n";
		return;
	}

	std::cout << "\nenter id of list to remove: ";
	int listId{};
	std::cin >> listId;
	removeFromNodeList(head, listId);
}

void handleListRemoval(NodeList* head)
{
	if (isNodeListEmpty(head))
	{
		std::cout << "\nthe list of lists is empty, cannot remove\n";
		return;
	}

	std::cout << "\nenter the id of list from which to remove the element: ";
	int listId{};
	std::cin >> listId;

	NodeList* current{ head->next };
	while (current != nullptr && current->head->value != listId)
		current = current->next;

	if (current == nullptr)
	{
		std::cout << "\ncouldn't find list with id " << listId << " in the list of lists\n";
		return;
	}

	std::cout << "\nenter value to remove: ";
	int valueToRemove{};
	std::cin >> valueToRemove;
	removeFromList(current->head, valueToRemove);
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
			handleListAddition(head);
			break;
		case 3:
			handleListPrinting(head);
			break;
		case 4:
			handleNodeListRemoval(head);
			break;
		case 5:
			handleListRemoval(head);
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
