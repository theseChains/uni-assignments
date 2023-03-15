#include "BinaryTree.h"

#include <iostream>
#include <random>

bool isTreeEmpty(const TreeNode* root)
{
	return (root == nullptr);
}

void addToTree(TreeNode*& node, int newValue)
{
	TreeNode* newNode{ new TreeNode{} };
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->value = newValue;

	if (node->left == nullptr && node->right != nullptr)
	{
		node->left = newNode;
		std::cout << "\nadded value " << newValue << " as the left child of node\n";
	}
	else if (node->left != nullptr && node->right == nullptr)
	{
		node->right = newNode;
		std::cout << "\nadded value " << newValue << " as the right child of node\n";
	}
	else
	{
		std::cout << "\n0: add as the right child\n1: add as the left child\n";
		int option{};
		std::cin >> option;

		if (option == 0)
			node->right = newNode;
		else if (option == 1)
			node->left = newNode;
		else
		{
			std::cout << "\nincorrect option\n";
			delete newNode;
		}
	}
}

void findElementInTree(TreeNode* root, TreeNode*& foundParent, int valueToFind, bool continueSearching)
{
	if (!continueSearching || root == nullptr)
		return;

	if (root->value != valueToFind)
	{
		findElementInTree(root->left, foundParent, valueToFind, continueSearching);
		findElementInTree(root->right, foundParent, valueToFind, continueSearching);
	}
	else if (root->value == valueToFind)
	{
		continueSearching = false;
		foundParent = root;
	}
}

void printTreeInDirectOrder(const TreeNode* root, int level)
{
	if (root == nullptr)
		return;

	std::cout << std::string(level, ' ') << root->value << '\n';
	printTreeInDirectOrder(root->left, level + 4);
	printTreeInDirectOrder(root->right, level + 4);
}

void printTreeInSymmetricOrder(const TreeNode* root, int level)
{
	if (root == nullptr)
		return;

	printTreeInSymmetricOrder(root->left, level + 4);
	std::cout << std::string(level, ' ') << root->value << '\n';
	printTreeInSymmetricOrder(root->right, level + 4);
}

void printTreeInBackwardSymmetricOrder(const TreeNode* root, int level)
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
