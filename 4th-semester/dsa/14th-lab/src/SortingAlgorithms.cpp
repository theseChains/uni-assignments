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

void heapify(std::vector<int>& numbers, int size, int i, int& numberOfComparisons, int& numberOfSwaps)
{
	// find largest among root, left child and right child
	int largest{ i };
	int left{ 2 * i + 1 };
	int right{ 2 * i + 2 };

	++numberOfComparisons;
	if (left < size && numbers[left] > numbers[largest])
		largest = left;

	++numberOfComparisons;
	if (right < size && numbers[right] > numbers[largest])
		largest = right;

	++numberOfComparisons;
	if (largest != i)
	{
		std::swap(numbers[i], numbers[largest]);
		++numberOfSwaps;
		heapify(numbers, size, largest, numberOfComparisons, numberOfSwaps);
	}
}

void heapSort(std::vector<int> numbers)
{
	int numberOfComparisons{ 0 };
	int numberOfSwaps{ 0 };

	int numbersSize{ static_cast<int>(numbers.size()) };
	// build max heap
	for (int i{ numbersSize }; i >= 0; --i)
		heapify(numbers, numbersSize, i, numberOfComparisons, numberOfSwaps);

	for (int i{ numbersSize - 1 }; i >= 0; --i)
	{
		std::swap(numbers[0], numbers[i]);
		++numberOfSwaps;
		heapify(numbers, i, 0, numberOfComparisons, numberOfSwaps);
	}

	std::cout << "\nsorted:\n";
	printVector(numbers);
	std::cout << "number of comparisons: " << numberOfComparisons << '\n';
	std::cout << "number of swaps: " << numberOfSwaps << '\n';
}

int partition(std::vector<int>& numbers, int low, int high, int& numberOfComparisons,
		int& numberOfSwaps)
{
	int pivot{ numbers[high] };
	int pivotIndex{ low - 1 };

	for (int current{ low }; current <= high - 1; ++current)
	{
		++numberOfComparisons;
		if (numbers[current] < pivot)
		{
			++pivotIndex;
			std::swap(numbers[pivotIndex], numbers[current]);
			++numberOfSwaps;
		}
	}

	std::swap(numbers[pivotIndex + 1], numbers[high]);
	++numberOfSwaps;
	return pivotIndex + 1;
}

void quickSort(std::vector<int>& numbers, int low, int high, int& numberOfComparisons,
		int& numberOfSwaps)
{
	if (low < high)
	{
		int pivotIndex{ partition(numbers, low, high, numberOfComparisons, numberOfSwaps) };
		quickSort(numbers, low, pivotIndex - 1, numberOfComparisons, numberOfSwaps);
		quickSort(numbers, pivotIndex + 1, high, numberOfComparisons, numberOfSwaps);
	}
}

void shellSort(std::vector<int> numbers)
{
	int numberOfComparisons{ 0 };
	int numberOfSwaps{ 0 };

	int numbersSize{ static_cast<int>(numbers.size()) };
	for (int gap{ numbersSize }; gap > 0; gap /= 2)
	{
		for (int i{ gap }; i < numbersSize; ++i)
		{
			int temporary{ numbers[i] };
			int j{};
			++numberOfComparisons;
			for (j = i; j >= gap && numbers[j - gap] > temporary; j -= gap)
			{
				numbers[j] = numbers[j - gap];
				++numberOfSwaps;
			}

			numbers[j] = temporary;
			++numberOfSwaps;
		}
	}

	std::cout << "\nsorted:\n";
	printVector(numbers);
	std::cout << "number of comparisons: " << numberOfComparisons << '\n';
	std::cout << "number of swaps: " << numberOfSwaps << '\n';
}
