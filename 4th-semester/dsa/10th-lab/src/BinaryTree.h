#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct TreeNode
{
	int value{};
	TreeNode* left{};
	TreeNode* right{};
};

void addToTree(TreeNode*& root, int numberOfElements);
void printTreeInDirectOrder(TreeNode* root, int level = 0);
void printTreeInSymmetricOrder(TreeNode* root, int level = 0);
void printTreeInBackwardSymmetricOrder(TreeNode* root, int level = 0);
void destroyTree(TreeNode* root);

#endif
