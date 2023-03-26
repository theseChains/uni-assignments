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

	// print buckets
	for (int i{ 0 }; i < numberOfBuckets; ++i)
	{
		std::cout << "bucket number " << i << ": ";
		Node* current{ buckets[i] };
		while (current)
		{
			std::cout << current->data << ' ';
			current = current->next;
		}
		std::cout << '\n';
	}

	for (int i{ 0 }; i < numberOfBuckets; ++i)
	{
		buckets[i] = sortBucket(buckets[i]);
	}

	// print again after sorting
	std::cout << "\nbuckets after sorting\n";
	for (int i{ 0 }; i < numberOfBuckets; ++i)
	{
		std::cout << "bucket number " << i << ": ";
		Node* current{ buckets[i] };
		while (current)
		{
			std::cout << current->data << ' ';
			current = current->next;
		}
		std::cout << '\n';
	}

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
