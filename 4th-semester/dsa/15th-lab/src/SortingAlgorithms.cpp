#include "SortingAlgorithms.h"

#include <algorithm>
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
				std::swap(numbers[numbers[i]], numbers[i]);
		}

		std::cout << "\nsorted:\n";
		printVector(numbers);
	}
	else if (option == 1)
	{
		std::vector<int> sorted(numbers.size());
		for (std::size_t i{ 0 }; i < numbers.size(); ++i)
			sorted[numbers[i]] = numbers[i];

		std::cout << "\nsorted:\n";
		printVector(sorted);
	}
	else
		std::cout << "\nincorrect option\n";
}

struct Node
{
	int data{};
	Node* next{ nullptr };
};

Node* insertionListSort(Node* newNode, Node* sorted)
{
	if (sorted == nullptr || sorted->data >= newNode->data)
	{
		newNode->next = sorted;
		return newNode;
	}
	else
	{
		Node* current{ sorted };

		while (current->next != nullptr && current->next->data < newNode->data)
			current = current->next;

		newNode->next = current->next;
		current->next = newNode;
	}

	return sorted;
}

Node* sortBucket(Node* head)
{
	Node* current{ head };
	Node* sorted{ nullptr };

	while (current != nullptr)
	{
		Node* next{ current->next };
		sorted = insertionListSort(current, sorted);
		current = next;
	}

	return sorted;
}

void genericBucketSort(std::vector<int> numbers)
{
	int numberOfBuckets{ 10 };
	int bucketCapacity{ static_cast<int>(numbers.size() / numberOfBuckets) + 1 };
	std::vector<Node*> buckets(numberOfBuckets);

	for (std::size_t i{ 0 }; i < numbers.size(); ++i)
	{
		int position{ numbers[i] / bucketCapacity };
		Node* current{ new Node{} };
		current->data = numbers[i];
		current->next = buckets[position];
		buckets[position] = current;
	}

	for (int i{ 0 }; i < numberOfBuckets; ++i)
		buckets[i] = sortBucket(buckets[i]);

	for (int j{ 0 }, i{ 0 }; i < numberOfBuckets; ++i)
	{
		Node* node{ buckets[i] };
		while (node)
		{
			numbers[j++] = node->data;
			node = node->next;
		}
	}

	std::cout << "\nsorted:\n";
	printVector(numbers);
}

void countingSortForRadix(std::vector<int>& numbers, int size, int digit)
{
	// working with 10 digits
	std::vector<int> workingStorage(10);
	std::vector<int> result(numbers.size());

	for (int i{ 0 }; i < size; ++i)
		++workingStorage[(numbers[i] / digit) % 10];

	for (int i{ 1 }; i < 10; ++i)
		workingStorage[i] += workingStorage[i - 1];

	for (int i{ size - 1 }; i >= 0; --i)
	{
		result[workingStorage[(numbers[i] / digit) % 10] - 1] = numbers[i];
		--workingStorage[(numbers[i] / digit) % 10];
	}

	numbers = result;
}

void radixSort(std::vector<int> numbers)
{
	int size{ static_cast<int>(numbers.size()) };
	int maximum{ *std::ranges::max_element(numbers) };

	for (int digitPlace{ 1 }; maximum / digitPlace > 0; digitPlace *= 10)
		countingSortForRadix(numbers, size, digitPlace);

	std::cout << "\nsorted:\n";
	printVector(numbers);
}
