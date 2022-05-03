#include <cassert>
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
#include <new> // for std::nothrow
#include <random>
#include <vector>
#include "constants.h"

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getNumber(char letter)
{
	std::cout << "Введите " << letter << ": ";
	while (true)
	{
		double value{};
		std::cin >> value;
		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Неверный ввод. Введите " << letter << " заново: ";
		}
		else if (static_cast<int>(value) != value || value < 1)
		{
			ignoreLine();
			std::cout << "Неверный ввод. Введите положительный целый " << letter << ": ";
		}
		else
		{
			ignoreLine();
			return static_cast<int>(value);
		}
	}
}

bool getAnswer()
{
	while (true)
	{
		char answer{};
		std::cin >> answer;
		// std::cin can't fail since anything a user enters is a char. just ignore input afterwards
		ignoreLine();
		if (answer == '0' || answer == '1')
		{
			return (answer == '1' ? true : false);
		}
		else
		{
			std::cout << "Неверный ввод. Введите 0 или 1: ";
		}
	}
}

int getRandomNumber(int min = 0, int max = 9)
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	std::uniform_int_distribution range{ min, max };

	return range(mt);
}

int** initializeIntArray(int row, int col)
{
	// creating an array of pointers - those are our rows
	int** array{ new (std::nothrow) int* [row] {} };
	// std::nothrow will return a nullptr if memory allocation failed
	assert(array != nullptr && "Не удалось выделить память.");
	// create an array for each row - those are our columns
	for (int i{ 0 }; i < row; ++i)
	{
		array[i] = new (std::nothrow) int[col] {};
		assert(array[i] != nullptr && "Не удалось выделить память.");
	}

	return array;
}

bool** initializeBoolArray(int row, int col)
{
	// creating an array of pointers - those are our rows
	bool** array{ new (std::nothrow) bool* [row] {} };
	assert(array != nullptr && "Не удалось выделить память.");
	// create an array for each row - those are our columns
	for (int i{ 0 }; i < row; ++i)
	{
		array[i] = new (std::nothrow) bool[col] {};
		assert(array[i] != nullptr && "Не удалось выделить память.");
	}

	return array;
}

void assignRandomValueAndPrintArray(int** initialArray, int row, int col, std::ostream& out)
{
	out << "Исходный массив: \n";
	for (int i{ 0 }; i < row; ++i)
	{
		for (int j{ 0 }; j < col; ++j)
		{
			initialArray[i][j] = getRandomNumber();
			out << initialArray[i][j] << ' ';
		}
		out << '\n';
	}
	out << '\n';
}

void printArray(auto** array, int row, int col, std::ostream& out)
{
	for (int i{ 0 }; i < row; ++i)
	{
		for (int j{ 0 }; j < col; ++j)
		{
			out << array[i][j] << ' ';
		}
		out << '\n';
	}
	out << '\n';
}

void deleteArray(auto**& array, int sizeOfArray)
{
	for (int i{ 0 }; i < sizeOfArray; ++i)
	{
		delete[] array[i];
	}
	delete[] array;
	// set to nullptr since its unclear whether array goes out of scope immediately outside of this function
	array = nullptr;
}

void solve(std::ostream& out)
{
	int row{ getNumber('n') };
	int col{ getNumber('m') };

	int** initialArray{ initializeIntArray(row, col) };
	assignRandomValueAndPrintArray(initialArray, row, col, out);

	bool** lesserNeighboursArray{ initializeBoolArray(row, col) };
	bool** allZerosArray{ initializeBoolArray(row, col) };
	bool** equalNeighboursArray{ initializeBoolArray(row, col) };

	// all 8 cases
	int rowOffset[]{ 1, 0, 1, -1, 0, -1, -1, 1 };
	int colOffset[]{ 0, 1, 1, 0, -1, -1, 1, -1 };
	// iterate through each offset of each array element
	for (int i{ 0 }; i < row; ++i)
	{
		for (int j{ 0 }; j < col; ++j)
		{
			std::vector<int> neighbours{};
			for (int k{ 0 }; k < constants::maxNeighbours; ++k)
			{
				// get indices of all neighbours of a[i][j] throughout the loop
				int rowNeighbIndex{ i + rowOffset[k] };
				int colNeighbIndex{ j + colOffset[k] };
				// if a[i][j] is a corner-type element then some of its 8 neighbours don't exist
				if (rowNeighbIndex < 0 || rowNeighbIndex > row - 1 || colNeighbIndex < 0 || colNeighbIndex > col - 1)
				{
					continue;
				}
				// put all a[i][j] neighbours into an array
				neighbours.push_back(initialArray[rowNeighbIndex][colNeighbIndex]);
			}
			// true if all neighbours of an a[i][j] are less than a[i][j]
			auto lesserNeighbours{ std::all_of(neighbours.begin(), neighbours.end(),
											[=](const int neighbour)
											{
												return (neighbour < initialArray[i][j]);
											}) };
			// true if all neighbours of a[i][j] are equal to 0
			auto allZeros{ std::all_of(neighbours.begin(), neighbours.end(),
											[](const int neighbour)
											{
													return (neighbour == 0);
											}) };
			// amount of neighbours equal to a[i][j]
			auto equalNeighbours{ std::count(neighbours.begin(), neighbours.end(), initialArray[i][j]) };
			if (lesserNeighbours)
			{
				lesserNeighboursArray[i][j] = true;
			}
			if (allZeros && initialArray[i][j] == 0)
			{
				allZerosArray[i][j] = true;
			}
			if (equalNeighbours >= constants::minimumEqualNeighbours)
			{
				equalNeighboursArray[i][j] = true;
			}
		}
	}

	out << "a)\n";
	printArray(lesserNeighboursArray, row, col, out);
	out << "б)\n";
	printArray(allZerosArray, row, col, out);
	out << "в)\n";
	printArray(equalNeighboursArray, row, col, out);

	deleteArray(initialArray, row);
	deleteArray(lesserNeighboursArray, row);
	deleteArray(allZerosArray, row);
	deleteArray(equalNeighboursArray, row);
}

void fileSolve(std::ifstream& inf, std::ostream& out)
{
	double n{};
	inf >> n;
	if (inf.fail() || n < 1 || static_cast<int>(n) != n)
	{
		std::cerr << "Неправильно указана переменная n в файле.\n";
		return;
	}

	double m{};
	inf >> m;
	if (inf.fail() || m < 1 || static_cast<int>(m) != m)
	{
		std::cerr << "Неправильно указана переменная m в файле.\n";
		return;
	}

	int row{ static_cast<int>(n) };
	int col{ static_cast<int>(m) };

	int** initialArray{ initializeIntArray(row, col) };
	assignRandomValueAndPrintArray(initialArray, row, col, out);

	bool** lesserNeighboursArray{ initializeBoolArray(row, col) };
	bool** allZerosArray{ initializeBoolArray(row, col) };
	bool** equalNeighboursArray{ initializeBoolArray(row, col) };

	// all 8 cases
	int rowOffset[]{ 1, 0, 1, -1, 0, -1, -1, 1 };
	int colOffset[]{ 0, 1, 1, 0, -1, -1, 1, -1 };
	// iterate through each offset of each array element
	for (int i{ 0 }; i < row; ++i)
	{
		for (int j{ 0 }; j < col; ++j)
		{
			std::vector<int> neighbours{};
			for (int k{ 0 }; k < constants::maxNeighbours; ++k)
			{
				// get indices of all neighbours of a[i][j] throughout the loop
				int rowNeighbIndex{ i + rowOffset[k] };
				int colNeighbIndex{ j + colOffset[k] };
				// if a[i][j] is a corner-type element then some of its 8 neighbours don't exist
				if (rowNeighbIndex < 0 || rowNeighbIndex > row - 1 || colNeighbIndex < 0 || colNeighbIndex > col - 1)
				{
					continue;
				}
				// put all a[i][j] neighbours into an array
				neighbours.push_back(initialArray[rowNeighbIndex][colNeighbIndex]);
			}
			// true if all neighbours of an a[i][j] are less than a[i][j]
			auto lesserNeighbours{ std::all_of(neighbours.begin(), neighbours.end(),
											[=](const int neighbour) {
												return (neighbour < initialArray[i][j]);
											}) };
			// true if all neighbours of a[i][j] are equal to 0
			auto allZeros{ std::all_of(neighbours.begin(), neighbours.end(),
											[](const int neighbour) {
												return (neighbour == 0);
											}) };
			// amount of neighbours equal to a[i][j]
			auto equalNeighbours{ std::count(neighbours.begin(), neighbours.end(), initialArray[i][j]) };
			if (lesserNeighbours)
			{
				lesserNeighboursArray[i][j] = true;
			}
			if (allZeros && initialArray[i][j] == 0)
			{
				allZerosArray[i][j] = true;
			}
			if (equalNeighbours >= constants::minimumEqualNeighbours)
			{
				equalNeighboursArray[i][j] = true;
			}
		}
	}

	out << "a)\n";
	printArray(lesserNeighboursArray, row, col, out);
	out << "б)\n";
	printArray(allZerosArray, row, col, out);
	out << "в)\n";
	printArray(equalNeighboursArray, row, col, out);

	deleteArray(initialArray, row);
	deleteArray(lesserNeighboursArray, row);
	deleteArray(allZerosArray, row);
	deleteArray(equalNeighboursArray, row);
}