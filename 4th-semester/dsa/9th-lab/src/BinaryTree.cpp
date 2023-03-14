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
