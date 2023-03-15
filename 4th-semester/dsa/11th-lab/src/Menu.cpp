#include "Menu.h"
#include "BinaryTree.h"

#include <iostream>
#include <random>

void printMenu()
{
	std::cout << "\n1:  add element to tree\n";
	std::cout << "2:  search for element in tree\n";
	std::cout << "3:  print tree\n";
	std::cout << "4:  destroy tree\n";
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
	if (isTreeEmpty(root))
	{
		std::cout << "\nenter new value: ";
		int newValue{ getNumber() };
		TreeNode* newNode{ new TreeNode{} };
		newNode->value = newValue;
		newNode->left = nullptr;
		newNode->right = nullptr;
		root = newNode;
	}
	else
	{
		std::cout << "\nenter node value to which you want to add children\n";
		int nodeValue{ getNumber() };
		TreeNode* foundNode{};
		findElementInTree(root, foundNode, nodeValue);
		if (!foundNode)
		{
			std::cout << "\nnode with value " << nodeValue << " wasn't found in the tree\n";
			return;
		}

		if (foundNode->left != nullptr && foundNode->right != nullptr)
		{
			std::cout << "\nfound node already has 2 children\n";
			return;
		}

		std::cout << "\nenter new value: ";
		int newValue{ getNumber() };
		addToTree(foundNode, newValue);
	}
}

void handleTreeSearch(TreeNode* root)
{
	std::cout << "\nenter value to find: ";
	int valueToFind{ getNumber() };
	TreeNode* found{};
	findElementInTree(root, found, valueToFind);
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

	std::cout << "\ndirect order:\n";
	printTreeInDirectOrder(root);
	std::cout << "\nsymmetric order:\n";
	printTreeInSymmetricOrder(root);
	std::cout << "\nbackward symmetric order:\n";
	printTreeInBackwardSymmetricOrder(root);
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
			handleTreeDestruction(root);
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
