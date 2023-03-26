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
	int numberOfComparisons{ 0 };
	int numberOfSwaps{ 0 };

	for (std::size_t i{ 0 }; i < numbers.size() - 1; ++i)
	{
		for (std::size_t j{ 0 }; j < numbers.size() - i - 1; ++j)
		{
			++numberOfComparisons;
			if (numbers[j] > numbers[j + 1])
			{
				++numberOfSwaps;
				std::swap(numbers[j], numbers[j + 1]);
			}
		}
	}

	// print the copied vector
	std::cout << "\nsorted:\n";
	printVector(numbers);
	std::cout << "number of comparisons: " << numberOfComparisons << '\n';
	std::cout << "number of swaps: " << numberOfSwaps << '\n';
}

void selectionSort(std::vector<int> numbers)
{
	int numberOfComparisons{ 0 };
	int numberOfSwaps{ 0 };

	for (std::size_t i{ 0 }; i < numbers.size() - 1; ++i)
	{
		std::size_t indexOfMinimum{ i };
		for (std::size_t j{ i + 1 }; j < numbers.size(); ++j)
		{
			++numberOfComparisons;
			if (numbers[j] < numbers[indexOfMinimum])
				indexOfMinimum = j;
		}

		++numberOfSwaps;
		std::swap(numbers[indexOfMinimum], numbers[i]);
	}

	std::cout << "\nsorted:\n";
	printVector(numbers);
	std::cout << "number of comparisons: " << numberOfComparisons << '\n';
	std::cout << "number of swaps: " << numberOfSwaps << '\n';
}

void insertionSort(std::vector<int> numbers)
{
	int numberOfComparisons{ 0 };
	int numberOfSwaps{ 0 };

	for (std::size_t i{ 1 }; i < numbers.size(); ++i)
	{
		int current{ numbers[i] };
		int j{ static_cast<int>(i - 1) };

		++numberOfComparisons;
		while (j >= 0 && numbers[j] > current)
		{
			++numberOfComparisons;
			++numberOfSwaps;
			numbers[j + 1] = numbers[j];
			--j;
		}

		++numberOfSwaps;
		numbers[j + 1] = current;
	}

	std::cout << "\nsorted:\n";
	printVector(numbers);
	std::cout << "number of comparisons: " << numberOfComparisons << '\n';
	std::cout << "number of swaps: " << numberOfSwaps << '\n';
}