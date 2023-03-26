#include "SortingAlgorithms.h"

#include <iostream>
#include <utility>

void printVector(const std::vector<int>& numbers)
{
	for (const auto& number : numbers)
		std::cout << number << ' ';
	std::cout << '\n';
}

void bucketSort(std::vector<int> numbers, int option)
{
	if (option == 0)
	{
		for (std::size_t i{ 0 }; i < numbers.size(); ++i)
		{
			while (numbers[i] != static_cast<int>(i))
			{
				int temporary{ numbers[numbers[i]] };
				numbers[numbers[i]] = numbers[i];
				numbers[i] = temporary;
			}
		}

		std::cout << "\nsorted:\n";
		printVector(numbers);
	}
	else
	{
		std::vector<int> sorted(numbers.size());
		for (std::size_t i{ 0 }; i < numbers.size(); ++i)
			sorted[numbers[i]] = numbers[i];

		std::cout << "\nsorted:\n";
		printVector(sorted);
	}
}
