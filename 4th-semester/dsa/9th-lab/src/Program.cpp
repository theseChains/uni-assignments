#include "Program.h"
#include "BinaryTree.h"

#include <iostream>

void runProgram()
{
	int command{};
	TreeNode* root{};
	while (command != -1)
	{
		std::cout << "\n\n\n";
		std::cout << "enter the number of elements of the tree: ";
		int numberOfElements{};
		std::cin >> numberOfElements;

		addToTree(root, numberOfElements);

		std::cout << "\ndirect order:\n";
		printTreeInDirectOrder(root);

		std::cout << "\nsymmetric order:\n";
		printTreeInSymmetricOrder(root);

		std::cout << "\nbackward-symmetric order:\n";
		printTreeInBackwardSymmetricOrder(root);

		std::cout << "\n\n-1: exit\n0:  continue\n";
		std::cin >> command;

		destroyTree(root);
		root = nullptr;
	}
}
