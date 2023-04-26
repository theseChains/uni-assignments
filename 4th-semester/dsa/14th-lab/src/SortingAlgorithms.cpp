#include "SortingAlgorithms.h"

#include <cmath>
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
	int numberOfAssignments{ 0 };

	for (std::size_t i{ 0 }; i < numbers.size() - 1; ++i)
	{
		for (std::size_t j{ 0 }; j < numbers.size() - i - 1; ++j)
		{
			++numberOfComparisons;
			if (numbers[j] > numbers[j + 1])
			{
				numberOfAssignments += 3;
				std::swap(numbers[j], numbers[j + 1]);
			}
		}
	}

	// print the copied vector
	std::cout << "\nsorted:\n";
	printVector(numbers);
	std::cout << "number of comparisons: " << numberOfComparisons << '\n';
	std::cout << "number of assignments: " << numberOfAssignments << '\n';
}

void selectionSort(std::vector<int> numbers)
{
	int numberOfComparisons{ 0 };
	int numberOfAssignments{ 0 };

	for (std::size_t i{ 0 }; i < numbers.size() - 1; ++i)
	{
		std::size_t indexOfMinimum{ i };
		for (std::size_t j{ i + 1 }; j < numbers.size(); ++j)
		{
			++numberOfComparisons;
			if (numbers[j] < numbers[indexOfMinimum])
				indexOfMinimum = j;
		}

		++numberOfComparisons;
		if (numbers[indexOfMinimum] != numbers[i])
		{
			numberOfAssignments += 3;
			std::swap(numbers[indexOfMinimum], numbers[i]);
		}
	}

	std::cout << "\nsorted:\n";
	printVector(numbers);
	std::cout << "number of comparisons: " << numberOfComparisons << '\n';
	std::cout << "number of assignments: " << numberOfAssignments << '\n';
}

void insertionSort(std::vector<int> numbers)
{
	int numberOfComparisons{ 0 };
	int numberOfAssignments{ 0 };

	for (std::size_t i{ 1 }; i < numbers.size(); ++i)
	{
		int current{ numbers[i] };
		++numberOfAssignments;
		int j{ static_cast<int>(i - 1) };

		while (j >= 0 && numbers[j] > current)
		{
			++numberOfComparisons;
			numbers[j + 1] = numbers[j];
			++numberOfAssignments;
			--j;
		}

		++numberOfComparisons;
		if (numbers[j + 1] != current)
		{
			++numberOfAssignments;
			numbers[j + 1] = current;
		}
	}

	std::cout << "\nsorted:\n";
	printVector(numbers);
	std::cout << "number of comparisons: " << numberOfComparisons << '\n';
	std::cout << "number of assignments: " << numberOfAssignments << '\n';
}

void heapify(std::vector<int>& numbers, int size, int i, int& numberOfComparisons,
		int& numberOfAssignments)
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

	if (largest != i)
	{
		if (numbers[i] != numbers[largest])
		{
			std::swap(numbers[i], numbers[largest]);
			numberOfAssignments += 3;
		}
		heapify(numbers, size, largest, numberOfComparisons, numberOfAssignments);
	}
}

void heapSort(std::vector<int> numbers)
{
	int numberOfComparisons{ 0 };
	int numberOfAssignments{ 0 };

	int numbersSize{ static_cast<int>(numbers.size()) };
	for (int i{ numbersSize }; i >= 0; --i)
		heapify(numbers, numbersSize, i, numberOfComparisons, numberOfAssignments);

	for (int i{ numbersSize - 1 }; i >= 0; --i)
	{
		if (numbers[0] != numbers[i])
		{
			std::swap(numbers[0], numbers[i]);
			numberOfAssignments += 3;
		}
		heapify(numbers, i, 0, numberOfComparisons, numberOfAssignments);
	}

	std::cout << "\nsorted:\n";
	printVector(numbers);
	std::cout << "number of comparisons: " << numberOfComparisons << '\n';
	std::cout << "number of assignments: " << numberOfAssignments << '\n';
}

void quickSort(std::vector<int>& numbers, int left, int right, int& numberOfComparisons,
		int& numberOfAssignments)
{
	int pivot{ numbers[(left + right) / 2] };

	int low{ left };
	int high{ right };
	while (low <= high)
	{
		++numberOfComparisons;
		while (numbers[low] < pivot)
		{
			++low;
			++numberOfComparisons;
		}

		++numberOfComparisons;
		while (numbers[high] > pivot)
		{
			--high;
			++numberOfComparisons;
		}

		if (low <= high)
		{
			++numberOfComparisons;
			if (numbers[low] != numbers[high])
			{
				std::swap(numbers[low], numbers[high]);
				numberOfAssignments += 3;
			}
			++low;
			--high;
		}
	}

	if (left < high)
		quickSort(numbers, left, high, numberOfComparisons, numberOfAssignments);
	if (low < right)
		quickSort(numbers, low, right, numberOfComparisons, numberOfAssignments);
}

void shellSort(std::vector<int> numbers)
{
	int numberOfComparisons{ 0 };
	int numberOfAssignments{ 0 };

	int numbersSize{ static_cast<int>(numbers.size()) };
	for (int gap{ numbersSize / 2 }; gap > 0; gap /= 2)
	{
		for (int i{ gap }; i < numbersSize; ++i)
		{
			int temporary{ numbers[i] };
			++numberOfAssignments;
			int j{ i - gap };

			++numberOfComparisons;
			while (j >= 0 && temporary < numbers[j])
			{
				++numberOfComparisons;
				numbers[j + gap] = numbers[j];
				++numberOfAssignments;
				j = j - gap;
			}

			if (numbers[j + gap] != temporary)
			{
				++numberOfAssignments;
				numbers[j + gap] = temporary;
			}
		}
	}

	std::cout << "\nsorted:\n";
	printVector(numbers);
	std::cout << "number of comparisons: " << numberOfComparisons << '\n';
	std::cout << "number of assignments: " << numberOfAssignments << '\n';
}
