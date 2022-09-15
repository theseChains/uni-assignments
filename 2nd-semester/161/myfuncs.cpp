#include <fstream>
#include <iostream>
#include <limits>
#include "constants.h"
#include "myfuncs.h"

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getNumber()
{
	while (true)
	{
		double n{};
		std::cin >> n;
		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "�������� ����.\n�������� ����� n ������: ";
		}
		else if (static_cast<int>(n) != n)
		{
			ignoreLine();
			std::cout << "�������� ����.\n�������� ����� ����� n: ";
		}
		else if (n < 1)
		{
			ignoreLine();
			std::cout << "�������� ����.\n������� ������������� ����� n: ";
		}
		else
		{
			ignoreLine();
			return static_cast<int>(n);
		}
	}
}

double getValue(int k)
{
	while (true)
	{
		double a{};
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "�������� ����.\n������� ����� �" << k << " ������: ";
		}
		else
		{
			ignoreLine();
			return a;
		}
	}
}

bool getAnswer()
{
	while (true)
	{
		char answer{};
		std::cin >> answer;
		ignoreLine();
		if (answer == '0' || answer == '1')
		{
			return answer == '1' ? true : false;
		}
		else
		{
			std::cout << "�������� ����.\n������� 0 ��� 1: ";
		}
	}
}

// fixed array as a parameter
void printAnswer(double* numbers, int index, std::ostream& out)
{
	for (int i{ 0 }; i < index - 1; ++i)
	{
		out << 'b' << i + 1 << " = " << numbers[i] << '\n';
	}
}

void solution(std::ostream& out)
{
	std::cout << "������� n: ";
	int n{ getNumber() };
	if (n)
	{
		double denominatorSum{ 0.0 };
		int index{ constants::startIndex };
		double numbers[constants::maxArraySize]{};

		std::cout << "������� �����: \n";
		for (int i{ 0 }; i < n; ++i)
		{
			std::cout << 'a' << index << " = ";
			double a{ getValue(index) };
			denominatorSum += a;
			double b{ a / (1.0 + denominatorSum * denominatorSum) };
			numbers[i] = b;
			++index;
		}
		printAnswer(numbers, index, out);
	}
}

void fileSolution(std::ifstream& inf, std::ostream& out)
{
	int n{};
	inf >> n;
	if (inf.fail() || n < 0)
	{
		std::cout << "����������� ������� ����� ����������.\n";
		return;
	}

	double denominatorSum{ 0.0 };
	int index{ constants::startIndex };
	double numbers[constants::maxArraySize]{};

	for (int i{ 0 }; i < n; ++i)
	{
		double a{};
		inf >> a;
		if (inf.fail())
		{
			std::cout << "����������� ������� �������������� ���������� a" << index << ".\n";
			return;
		}
		denominatorSum += a;
		double b{ a / (1.0 + denominatorSum * denominatorSum) };
		numbers[i] = b;
		++index;
	}
	printAnswer(numbers, index, out);
	std::cout << "����� ���������.\n";
}