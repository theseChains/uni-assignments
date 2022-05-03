#include <fstream>
#include <iostream>
#include "myfuncs.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	std::ifstream inf{ "in.txt" };
	std::ofstream outf{ "out.txt" };

	if (!inf || !outf)
	{
		std::cerr << "Не удалось открыть файл(ы)!\n";
		return 1;
	}

	while (true)
	{
		std::cout << "Ввести данные с консоли - 0, с файла - 1: ";
		bool input{ getAnswer() };
		std::cout << "Вывести данные в консоль - 0, в файл - 1: ";
		bool output{ getAnswer() };
		// check all 4 outcomes
		if (input == 0 && output == 0)
		{
			solve(std::cout);
			std::cout << "Повторить ввод? Да - 1, Нет - 0: ";
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
			std::cout << "Повторить ввод? Да - 1, Нет - 0: ";
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