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
	std::cout << "Введите n: ";
	while (true)
	{
		double n{};
		std::cin >> n;
		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Неверный ввод. Введите число n: ";
		}
		else if (static_cast<int>(n) != n || n < 1)
		{
			ignoreLine();
			std::cout << "Неверный ввод. Введите положительное целое число n: ";
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
			std::cout << "Неверный ввод. Введите 0 или 1: ";
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

	out << "Случайная последовательность: " << sequence << '\n';

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

	out << "Ваша последовательность: " << sequence << '\n';

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

	out << "Кол-во 'abc': " << abcCount << '\n';
	out << "Кол-во 'aba': " << abaCount << '\n';
}

void solve(std::ostream& out)
{
	int n{ getNumber() };
	std::cout << "Ввести последовательность " << n << " символa(-ов) автоматически? Да - 1, Нет - 0: ";
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
		std::cerr << "Неверная переменная n в файле.\n";
		return;
	}

	std::string sequence{};

	while (inf)
	{
		std::getline(inf, sequence);
	}

	if (sequence.length() != static_cast<int>(n))
	{
		std::cerr << "Неверное количество символов в файле.\n";
		return;
	}

	abcAndAbaCount(sequence, out);
}

std::string getFileName(StreamType stream, std::string defaultFileName)
{
	std::cout << "Введите файл для " << (stream == StreamType::input ? "ввода: " : "вывода: ");
	std::string fileName{};
	// get input into fileName
	std::getline(std::cin, fileName);
	// if user enters nothing, return default name
	if (fileName.empty())
	{
		std::cout << "Выбран файл " << (stream == StreamType::input ? "in.txt" : "out.txt") << " по умолчанию.\n";
		return defaultFileName;
	}
	else
	{
		return fileName;
	}
}