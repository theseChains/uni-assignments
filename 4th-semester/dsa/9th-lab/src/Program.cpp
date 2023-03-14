#include "Program.h"

#include <iostream>
#include <random>

void runProgram()
{
	int command{};
	while (command != -1)
	{
		std::cout << "\n\n\n";
		std::cout << "enter the number of elements of the tree: ";
		int numberOfElements{};
		std::cin >> numberOfElements;

		std::cout << "\ndirect order:\n";

		std::cout << "\nsymmetric order:\n";

		std::cout << "\nbackward-symmetric order:\n";

		std::cout << "\n-1: exit\nelse: continue: ";
		std::cin >> command;
	}
}
