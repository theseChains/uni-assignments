#include "Menu.h"
#include "SortingAlgorithms.h"

#include <algorithm>
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
	std::cout << "\n1:  sort using bucket sort algorithm\n";
	std::cout << "2:  sort using generic bucket sort algorithm\n";
	std::cout << "3:  sort using radix sort algorithm\n";
	std::cout << "-1: exit\n";
}

int getNumber()
{
	int number{};
	std::cin >> number;
	return number;
}

void generateUniformDistribution(std::vector<int>& numbers)
{
	std::cout << "\nenter number of elements to generate: ";
	int numberOfElements{ getNumber() };
	numbers.clear();

	for (int i{ 0 }; i < numberOfElements; ++i)
		numbers.push_back(i);

	std::shuffle(numbers.begin(), numbers.end(), rnd::mt);
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

void handleSorting(std::vector<int>& numbers, int command)
{
	switch (command)
	{
		case 1:
		{
			generateUniformDistribution(numbers);

			std::cout << "\n0: use secondary array";
			std::cout << "\n1: don't use secondary array\n";
			int option{ getNumber() };

			std::cout << "\noriginal:\n";
			printVector(numbers);
			bucketSort(numbers, option);
			break;
		}
		case 2:
		{
			generateVector(numbers);

			std::cout << "\noriginal:\n";
			printVector(numbers);
			genericBucketSort(numbers);
			break;
		}
		case 3:
		{
			generateVector(numbers);

			std::cout << "\noriginal:\n";
			printVector(numbers);
			radixSort(numbers);
			break;
		}
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
		handleSorting(numbers, command);
	}
}
