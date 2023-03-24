#include "Menu.h"
#include "BinarySearchTree.h"

#include <iostream>
#include <random>

namespace rnd
{
	std::mt19937 mt{ std::random_device{}() };

	int get(int min, int max)
	{
		std::uniform_int_distribution range{ min, max };
		return range(mt);
	}
}

void printMenu()
{
	std::cout << "\n1:  add element to tree\n";
	std::cout << "2:  search for element in tree\n";
	std::cout << "3:  print tree\n";
	std::cout << "4:  remove element from tree\n";
	std::cout << "5:  destroy tree\n";
	std::cout << "6:  add multiple elements\n";
	std::cout << "7:  print tree with the counter of elements\n";
	std::cout << "-1: exit\n";
}

int getNumber()
{
	int number{};
	std::cin >> number;
	return number;
}

void handleTreeAddition(TreeNode*& root)
{
	std::cout << "\n0: use recursive algorithm\n1: use non-recursive algorithm\n";
	int option{ getNumber() };
	std::cout << "\nenter new value: ";
	int newValue{ getNumber() };
	if (option == 0)
		addToTree(root, newValue);
	else if (option == 1)
		addToTreeRecursive(root, newValue);
	else
		std::cout << "\nincorrect option\n";
}

void handleTreeSearch(TreeNode* root)
{
	std::cout << "\nenter value to find: ";
	int valueToFind{ getNumber() };
	TreeNode* found{ findElementInTree(root, valueToFind) };
	if (found)
		std::cout << "\nvalue " << valueToFind << " was found in the tree\n";
	else
		std::cout << "\nvalue " << valueToFind << " wasn't found in the tree\n";
}

void handleTreeDestruction(TreeNode*& root)
{
	destroyTree(root);
	root = nullptr;
}

void handleTreePrint(const TreeNode* root)
{
	if (isTreeEmpty(root))
	{
		std::cout << "\nthe tree is empty\n";
		return;
	}

	printTreeInBackwardSymmetricOrder(root);
}

void handleTreeRemoval(TreeNode*& root)
{
	std::cout << "\nenter value to remove: ";
	int valueToRemove{ getNumber() };
	removeFromTree(root, valueToRemove);
}

void handleTreeCreation(TreeNode*& root)
{
	std::cout << "\nenter number of elements to add: ";
	int numberOfElementsToAdd{ getNumber() };
	for (int i{ 0 }; i < numberOfElementsToAdd; ++i)
		addToTree(root, rnd::get(0, 99));
}

void handleTreePrintWithCount(const TreeNode* root)
{
	std::cout << '\n';
	printTreeInSymmetricOrderWithCount(root);
	std::cout << '\n';
}

void handleCommand(TreeNode*& root, int command)
{
	switch (command)
	{
		case 1:
			handleTreeAddition(root);
			break;
		case 2:
			handleTreeSearch(root);
			break;
		case 3:
			handleTreePrint(root);
			break;
		case 4:
			handleTreeRemoval(root);
			break;
		case 5:
			handleTreeDestruction(root);
			break;
		case 6:
			handleTreeCreation(root);
			break;
		case 7:
			handleTreePrintWithCount(root);
			break;
	}
}

void runMenuLoop()
{
	TreeNode* root{ nullptr };

	int command{};
	while (command != -1)
	{
		printMenu();
		command = getNumber();
		handleCommand(root, command);
	}
}
