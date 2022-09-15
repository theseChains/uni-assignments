#include <fstream>
#include <iostream>
#include <limits>
#include "constants.h"

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
			std::cout << "�������� ����.\n������� ����� n ������: ";
		}
		else if (static_cast<int>(n) != n)
		{
			ignoreLine();
			std::cout << "�������� ����.\n������� ����� ����� n: ";
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

double getDoubleValue()
{
	while (true)
	{
		double a{};
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "�������� ����.\n������� ����� x ������: ";
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

double arraySum(double* numbers, int n)
{
	double sum{ 0.0 };
	for (int i{ 0 }; i < n; ++i)
	{
		sum += numbers[i];
	}
	return sum;
}

void solution(std::ostream& out)
{
	std::cout << "������� n: ";
	int n{ getNumber() };
	std::cout << "������� x: ";
	double x{ getDoubleValue() };

	double numerator{};
	double xPower{ 1.0 };
	double numbers[constants::maxArraySize]{};

	for (int i{ 0 }; i < n; ++i)
	{
		numerator = std::pow(-1.0, static_cast<int>(std::sqrt(i + 1)));
		xPower *= x;
		numbers[i] = numerator / (i + 1) * xPower;
	}
	// output on screen if out == std::cout, else in file
	out << "����� �����: " << arraySum(numbers, n) << '\n';
}

void fileSolution(std::ifstream& inf, std::ostream& out)
{
	double numerator{};
	double xPower{ 1.0 };
	double numbers[constants::maxArraySize]{};

	int n{};
	inf >> n;
	if (inf.fail() || n < 1)
	{
		std::cerr << "�������� n � �����.\n";
		return;
	}

	double x{};
	inf >> x;

	if (inf.fail())
	{
		std::cerr << "�������� � � �����.\n";
		return;
	}

	for (int i{ 0 }; i < n; ++i)
	{
		numerator = std::pow(-1.0, static_cast<int>(std::sqrt(i + 1)));
		xPower *= x;
		numbers[i] = numerator / (i + 1) * xPower;
	}

	// output on screen if out == std::cout, else in file
	out << "����� �����: " << arraySum(numbers, n) << '\n';
	std::cout << "����� ���������.\n";
}