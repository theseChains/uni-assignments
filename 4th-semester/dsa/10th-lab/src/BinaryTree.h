#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct TreeNode
{
	int value{};
	TreeNode* left{};
	TreeNode* right{};
};

struct Stack
{
	int level{ -1 };
	Stack* next{ nullptr };
	TreeNode* traversedNode{ nullptr };
};

void addToTree(TreeNode*& root, int numberOfElements);
void printTreeInDirectOrder(TreeNode* root, int level = 0);
void printTreeInSymmetricOrder(TreeNode* root, int level = 0);
void printTreeInSymmetricOrderNonRecursive(TreeNode* root);
void printTreeInBackwardSymmetricOrder(TreeNode* root, int level = 0);
void destroyTree(TreeNode* root);

#endif
