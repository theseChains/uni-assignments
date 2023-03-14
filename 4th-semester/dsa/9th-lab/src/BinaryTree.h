#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct TreeNode
{
	int value{};
	TreeNode* left{};
	TreeNode* right{};
};

void addToTree(TreeNode* root, int value);
void printTreeInDirectOrder(TreeNode* root);
void printTreeInSymmetricOrder(TreeNode* root);
void printTreeInBackwardSymmetricOrder(TreeNode* root);

#endif
