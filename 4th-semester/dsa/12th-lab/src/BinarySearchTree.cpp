#include "BinarySearchTree.h"

#include <iostream>
#include <random>

bool isTreeEmpty(const TreeNode* root)
{
	return (root == nullptr);
}

void addToTree(TreeNode*& root, int newValue)
{
	TreeNode* parent{};
	TreeNode* current{ root };
	TreeNode* newNode{};

	while (current != nullptr)
	{
		parent = current;
		if (newValue < current->value)
			current = current->left;
		else if (newValue > current->value)
			current = current->right;
		else
		{
			std::cout << "\nelement " << newValue << " is already in the tree, increasing count\n";
			++current->count;
			return;
		}
	}

	newNode = new TreeNode{};
	newNode->parent = parent;
	newNode->value = newValue;

	if (parent == nullptr)
		root = newNode;
	else if (newNode->value < parent->value)
		parent->left = newNode;
	else
		parent->right = newNode;
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
