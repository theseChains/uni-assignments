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
TreeNode* addToTreeRecursive(TreeNode*& root, int newValue, TreeNode* parent = nullptr);
TreeNode* findElementInTree(TreeNode* root, int valueToFind);
void removeFromTree(TreeNode*& root, int valueToRemove);

void printTreeInSymmetricOrderWithCount(const TreeNode* root);
void printTreeInBackwardSymmetricOrder(const TreeNode* root, int level = 0);

void destroyTree(TreeNode* root);

#endif
