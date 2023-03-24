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
	newNode->count = 1;

	if (parent == nullptr)
		root = newNode;
	else if (newNode->value < parent->value)
		parent->left = newNode;
	else
		parent->right = newNode;
}

TreeNode* addToTreeRecursive(TreeNode*& current, int newValue, TreeNode* parent)
{
	if (current == nullptr)
	{
		current = new TreeNode{};
		current->value = newValue;
		current->count = 1;
		current->parent = parent;
	}
	else
	{
		parent = current;
		if (newValue < current->value)
			current->left = addToTreeRecursive(current->left, newValue, parent);
		else if (newValue > current->value)
			current->right = addToTreeRecursive(current->right, newValue, parent);
		else
		{
			std::cout << "\nelement " << newValue << " is already in the tree, increasing count\n";
			++current->count;
		}
	}

	return current;
}

TreeNode* findElementInTree(TreeNode* current, int valueToFind)
{
	if (current == nullptr || current->value == valueToFind)
		return current;

	if (current->value < valueToFind)
		return findElementInTree(current->right, valueToFind);
	else
		return findElementInTree(current->left, valueToFind);
}

TreeNode* minimum(TreeNode* current)
{
	while (current->left != nullptr)
		current = current->left;

	return current;
}

void transplant(TreeNode*& root, TreeNode*& first, TreeNode*& second)
{
	if (first->parent == nullptr)
		root = second;
	else if (first == first->parent->left)
		first->parent->left = second;
	else
		first->parent->right = second;

	if (second != nullptr)
		second->parent = first->parent;
}

void removeFromTree(TreeNode*& root, int valueToRemove)
{
	TreeNode* nodeToRemove{ findElementInTree(root, valueToRemove) };
	if (!nodeToRemove)
	{
		std::cout << "\nvalue " << valueToRemove << " was not found in the tree, cannot remove\n";
		return;
	}

	if (nodeToRemove->left == nullptr)
		// replace by right child
		transplant(root, nodeToRemove, nodeToRemove->right);
	else if (nodeToRemove->right == nullptr)
		// replace by left child
		transplant(root, nodeToRemove, nodeToRemove->left);
	else
	{
		// both children exist
		// the successor is the minimum of the right subtree
		TreeNode* nodeToRemoveSuccessor{ minimum(nodeToRemove->right) };

		if (nodeToRemoveSuccessor->parent != nodeToRemove)
		{
			transplant(root, nodeToRemoveSuccessor, nodeToRemoveSuccessor->right);
			nodeToRemoveSuccessor->right = nodeToRemove->right;
			nodeToRemoveSuccessor->right->parent = nodeToRemoveSuccessor;
		}

		transplant(root, nodeToRemove, nodeToRemoveSuccessor);
		nodeToRemoveSuccessor->left = nodeToRemove->left;
		nodeToRemoveSuccessor->left->parent = nodeToRemoveSuccessor;
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
