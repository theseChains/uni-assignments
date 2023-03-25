#include "SortingAlgorithms.h"

#include <iostream>
#include <utility>

void printVector(const std::vector<int>& numbers)
{
	for (const auto& number : numbers)
		std::cout << number << ' ';
}

void bubbleSort(std::vector<int> numbers)
{
	for (std::size_t i{ 0 }; i < numbers.size() - 1; ++i)
	{
		for (std::size_t j{ 0 }; j < numbers.size() - i - 1; ++j)
		{
			if (numbers[j] > numbers[j + 1])
				std::swap(numbers[j], numbers[j + 1]);
		}
	}

	// print the copied vector
	printVector(numbers);
	std::cout << '\n';
}

void selectionSort(std::vector<int> numbers);
void insertionSort(std::vector<int> numbers);
