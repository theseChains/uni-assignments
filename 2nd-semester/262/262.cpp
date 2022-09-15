#include <fstream>
#include <iostream>
#include "constants.h"
#include "myfuncs.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	std::ifstream inf{};
	std::ofstream outf{};

	while (true)
	{
		std::cout << "Ввод данных с консоли - 0, с файла - 1: ";
		bool input{ getAnswer() };
		std::cout << "Вывод данных в консоль - 0, в файл - 1: ";
		bool output{ getAnswer() };
		// get input file name
		if (input == 1)
		{
			inf = static_cast<std::ifstream>(getFileName(StreamType::input, constants::defaultInputFile));
			if (!inf)
			{
				std::cerr << "Не удалось открыть файл для ввода данных.\n";
				return 1;
			}
		}
		// get output file name
		if (output == 1)
		{
			outf = static_cast<std::ofstream>(getFileName(StreamType::output, constants::defaultOutputFile));
			if (!outf)
			{
				std::cerr << "Не удалось открыть файл для вывода данных.\n";
				return 1;
			}
		}
		// check all 4 possible outputs
		if (input == 0 && output == 0)
		{
			solve(std::cout);
			std::cout << "Повторить ввод исходных данных? Да - 1, Нет - 0: ";
			if (getAnswer())
				continue;
			else
			{
				std::cout << "Конец программы.\n";
				break;
			}
		}
		else if (input == 0 && output == 1)
		{
			solve(outf);
			std::cout << "Повторить ввод исходных данных? Да - 1, Нет - 0: ";
			if (getAnswer())
				continue;
			else
			{
				std::cout << "Конец программы.\n";
				break;
			}
		}
		else if (input == 1 && output == 0)
		{
			fileSolve(inf, std::cout);
			std::cout << "Конец программы.\n";
			break;
		}
		else if (input == 1 && output == 1)
		{
			fileSolve(inf, outf);
			std::cout << "Конец программы.\n";
			break;
		}
	}

	return 0;
}
