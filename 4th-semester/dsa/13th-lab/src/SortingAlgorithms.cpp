#include "SortingAlgorithms.h"

#include <iostream>
#include <utility>

void printVector(const std::vector<int>& numbers)
{
	for (const auto& number : numbers)
		std::cout << number << ' ';
	std::cout << '\n';
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
	std::cout << "\nsorted:\n";
	printVector(numbers);
}

void selectionSort(std::vector<int> numbers)
{
	for (std::size_t i{ 0 }; i < numbers.size() - 1; ++i)
	{
		std::size_t indexOfMinimum{ i };
		for (std::size_t j{ i + 1 }; j < numbers.size(); ++j)
		{
			if (numbers[j] < numbers[indexOfMinimum])
				indexOfMinimum = j;
		}

		std::swap(numbers[indexOfMinimum], numbers[i]);
	}

	std::cout << "\nsorted:\n";
	printVector(numbers);
}

void insertionSort(std::vector<int> numbers)
{
	for (std::size_t i{ 1 }; i < numbers.size(); ++i)
	{
		int key{ numbers[i] };
		int j{ static_cast<int>(i - 1) };

		while (j >= 0 && numbers[j] > key)
		{
			numbers[j + 1] = numbers[j];
			--j;
		}

		numbers[j + 1] = key;
	}

	std::cout << "\nsorted:\n";
	printVector(numbers);
}
