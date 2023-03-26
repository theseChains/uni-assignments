#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>

void printVector(const std::vector<int>& numbers);

void bucketSort(std::vector<int> numbers, int option);
void selectionSort(std::vector<int> numbers);
void insertionSort(std::vector<int> numbers);

#endif
