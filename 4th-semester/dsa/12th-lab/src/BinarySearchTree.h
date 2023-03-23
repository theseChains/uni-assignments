#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct TreeNode
{
	int value{};
	int count{ 0 };
	TreeNode* left{ nullptr };
	TreeNode* right{ nullptr };
	TreeNode* parent{ nullptr };
};

bool isTreeEmpty(const TreeNode* root);
void addToTree(TreeNode*& root, int newValue);
void findElementInTree(TreeNode* root, TreeNode*& foundParent, int valueToFind,
		bool continueSearching = true);
void printTreeInDirectOrder(const TreeNode* root, int level = 0);
void printTreeInSymmetricOrder(const TreeNode* root, int level = 0);
void printTreeInBackwardSymmetricOrder(const TreeNode* root, int level = 0);
void destroyTree(TreeNode* root);

#endif
