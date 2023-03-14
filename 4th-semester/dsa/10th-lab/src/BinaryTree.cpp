#include "BinaryTree.h"

#include <iostream>
#include <random>

namespace rnd
{
	std::mt19937 mt{ std::random_device{}() };

	int getNumber(int min, int max)
	{
		std::uniform_int_distribution range{ min, max };
		return range(mt);
	}
}

void addToTree(TreeNode*& root, int numberOfElements)
{
	if (numberOfElements == 0)
		return;

	int numberOfLeftChildren{ numberOfElements / 2 };
	int numberOfRightChildren{ numberOfElements - numberOfLeftChildren - 1 };

	TreeNode* newNode{ new TreeNode{} };
	newNode->value = rnd::getNumber(0, 99);
	addToTree(newNode->left, numberOfLeftChildren);
	addToTree(newNode->right, numberOfRightChildren);
	root = newNode;
}

void printTreeInDirectOrder(TreeNode* root, int level)
{
	if (root == nullptr)
		return;

	std::cout << std::string(level, ' ') << root->value << '\n';
	printTreeInDirectOrder(root->left, level + 4);
	printTreeInDirectOrder(root->right, level + 4);
}

void printTreeInSymmetricOrder(TreeNode* root, int level)
{
	if (root == nullptr)
		return;

	printTreeInSymmetricOrder(root->left, level + 4);
	std::cout << std::string(level, ' ') << root->value << '\n';
	printTreeInSymmetricOrder(root->right, level + 4);
}

void printTreeInSymmetricOrderNonRecursive(TreeNode* root)
{
	Stack* top{ new Stack{} };
	top->traversedNode = root;
	top->level = -1;
	top->next = nullptr;

	TreeNode* current{ root };
	int currentLevel{ 0 };
	while (current != nullptr || top->level >= 0)
	{
		while (current != nullptr)
		{
			Stack* newNode{ new Stack{} };
			newNode->level = currentLevel;
			newNode->traversedNode = current;
			newNode->next = top;
			top = newNode;
			current = current->left;
			++currentLevel;
		}

		currentLevel = top->level;

		current = top->traversedNode;
		Stack* temporary{ top };
		top = top->next;
		delete temporary;

		std::cout << std::string(currentLevel * 4, ' ') << current->value << '\n';

		current = current->right;
		++currentLevel;
	}
}

void printTreeInBackwardSymmetricOrder(TreeNode* root, int level)
{
	if (root == nullptr)
		return;

	printTreeInBackwardSymmetricOrder(root->right, level + 4);
	std::cout << std::string(level, ' ') << root->value << '\n';
	printTreeInBackwardSymmetricOrder(root->left, level + 4);
}

void destroyTree(TreeNode* root)
{
	if (root == nullptr)
		return;

	destroyTree(root->left);
	destroyTree(root->right);
	delete root;
}
