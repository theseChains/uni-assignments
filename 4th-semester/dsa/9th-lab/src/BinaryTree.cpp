#include "BinaryTree.h"

namespace rnd
{
	std::mt19937 mt{ std::random_device{}() };

	int getNumber(int min, int max)
	{
		std::uniform_int_distribution range{ min, max };
		return range(mt);
	}
}

void addToTree(TreeNode* root, int numberOfElements)
{

}

void printTreeInDirectOrder(TreeNode* root)
{

}

void printTreeInSymmetricOrder(TreeNode* root)
{

}

void printTreeInBackwardSymmetricOrder(TreeNode* root)
{

}
