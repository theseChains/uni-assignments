#include "Menu.h"
#include "SortingAlgorithms.h"

#include <iostream>
#include <random>
#include <vector>

namespace rnd
{
	std::mt19937 mt{ std::random_device{}() };

	int get(int min, int max)
	{
		std::uniform_int_distribution range{ min, max };
		return range(mt);
	}
}

void printMenu()
{
	std::cout << "\n1:  sort using bubble sort algorithm\n";
	std::cout << "2:  sort using selection sort algorithm\n";
	std::cout << "3:  sort using insertion sort algorithm\n";
	std::cout << "4:  sort using heap sort algorithm\n";
	std::cout << "5:  sort using quick sort algorithm\n";
	std::cout << "6:  sort using shell sort algorithm\n";
	std::cout << "7:  generate vector\n";
	std::cout << "-1: exit\n";
}

int getNumber()
{
	int number{};
	std::cin >> number;
	return number;
}

void generateVector(std::vector<int>& numbers)
{
	numbers.clear();
	std::cout << "\nenter number of elements to generate: ";
	int numberOfElements{ getNumber() };
	numbers.reserve(numberOfElements);

	for (int i{ 0 }; i < numberOfElements; ++i)
		numbers.push_back(rnd::get(0, numberOfElements));
}

void handleSorting(const std::vector<int>& numbers, int command)
{
	if (numbers.empty())
	{
		std::cout << "\nthe array is empty, cannot sort\n";
		return;
	}

	std::cout << "\noriginal:\n";
	printVector(numbers);

	switch (command)
	{
		case 1:
			bubbleSort(numbers);
			break;
		case 2:
			selectionSort(numbers);
			break;
		case 3:
			insertionSort(numbers);
			break;
		case 4:
			heapSort(numbers);
			break;
		case 5:
		{
			std::vector<int> numbersCopy{ numbers };
			int numberOfComparisons{ 0 };
			int numberOfAssignments{ 0 };

			quickSort(numbersCopy, 0, static_cast<int>(numbersCopy.size() - 1),
					numberOfComparisons, numberOfAssignments);

			std::cout << "\nsorted:\n";
			printVector(numbersCopy);
			std::cout << "number of comparisons: " << numberOfComparisons << '\n';
			std::cout << "number of assignments: " << numberOfAssignments << '\n';
			break;
		}
		case 6:
			shellSort(numbers);
			break;
	}
}

void handleCommand(std::vector<int>& numbers, int command)
{
	switch (command)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			handleSorting(numbers, command);
			break;
		case 7:
			generateVector(numbers);
			break;
	}
}

void runMenuLoop()
{
	std::vector<int> numbers{};

	int command{};
	while (command != -1)
	{
		printMenu();
		command = getNumber();
		handleCommand(numbers, command);
	}
}
