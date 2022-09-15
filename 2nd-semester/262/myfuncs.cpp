#include "constants.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <string>

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getNumber()
{
	std::cout << "������� n: ";
	while (true)
	{
		double n{};
		std::cin >> n;
		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "�������� ����. ������� ����� n: ";
		}
		else if (static_cast<int>(n) != n || n < 1)
		{
			ignoreLine();
			std::cout << "�������� ����. ������� ������������� ����� ����� n: ";
		}
		else
		{
			ignoreLine();
			return static_cast<int>(n);
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
			return (answer == '1' ? true : false);
		}
		else
		{
			std::cout << "�������� ����. ������� 0 ��� 1: ";
		}
	}
}

int getRandomNumber()
{
	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	std::uniform_int_distribution abcASCII{ constants::aASCII, constants::cASCII };

	return abcASCII(mt);
}

std::string createRandomSequence(int n, std::ostream& out)
{
	std::string sequence{};

	for (int i{ 0 }; i < n; ++i)
	{
		int symbol{ getRandomNumber() };
		sequence.push_back(static_cast<char>(symbol));
	}

	out << "��������� ������������������: " << sequence << '\n';

	return sequence;
}

std::string createUserSequence(int n, std::ostream& out)
{
	std::string sequence{};

	for (int i{ 0 }; i < n; ++i)
	{
		std::cout << 's' << i + 1 << " = ";
		char symbol{};
		std::cin >> symbol;
		sequence.push_back(symbol);
	}

	out << "���� ������������������: " << sequence << '\n';

	return sequence;
}

void abcAndAbaCount(std::string sequence, std::ostream& out)
{
	int abcCount{ 0 };
	int abaCount{ 0 };

	for (int i{ constants::startIndex }; i < sequence.length(); ++i)
	{
		std::string check{};
		check.assign(sequence, static_cast<std::string::size_type>(i - constants::startIndex), constants::substringLength);
		if (check == "abc")
		{
			++abcCount;
		}
		if (check == "aba")
		{
			++abaCount;
		}
	}

	out << "���-�� 'abc': " << abcCount << '\n';
	out << "���-�� 'aba': " << abaCount << '\n';
}

void solve(std::ostream& out)
{
	int n{ getNumber() };
	std::cout << "������ ������������������ " << n << " ������a(-��) �������������? �� - 1, ��� - 0: ";
	int answer{ getAnswer() };

	if (answer)
	{
		std::string sequence{ createRandomSequence(n, out) };
		abcAndAbaCount(sequence, out);
	}
	else
	{
		std::string sequence{ createUserSequence(n, out) };
		abcAndAbaCount(sequence, out);
	}
}

void fileSolve(std::ifstream& inf, std::ostream& out)
{
	double n{};
	inf >> n;

	if (inf.fail() || n < 1 || static_cast<int>(n) != n)
	{
		std::cerr << "�������� ���������� n � �����.\n";
		return;
	}

	std::string sequence{};

	while (inf)
	{
		std::getline(inf, sequence);
	}

	if (sequence.length() != static_cast<int>(n))
	{
		std::cerr << "�������� ���������� �������� � �����.\n";
		return;
	}

	abcAndAbaCount(sequence, out);
}

std::string getFileName(StreamType stream, std::string defaultFileName)
{
	std::cout << "������� ���� ��� " << (stream == StreamType::input ? "�����: " : "������: ");
	std::string fileName{};
	// get input into fileName
	std::getline(std::cin, fileName);
	// if user enters nothing, return default name
	if (fileName.empty())
	{
		std::cout << "������ ���� " << (stream == StreamType::input ? "in.txt" : "out.txt") << " �� ���������.\n";
		return defaultFileName;
	}
	else
	{
		return fileName;
	}
}