#include <cmath>
#include <iostream>
#include "myfuncs.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	std::ifstream inf{ "in.txt" };
	std::ofstream outf{ "out.txt" };

	if (!inf || !outf)
	{
		std::cerr << "Не получилось открыть файл(ы).\n";
		return 1;
	}

	while (true)
	{
		std::cout << "Введите 0 для ввода с консоли, 1 для ввода с файла: ";
		bool input{ getAnswer() };
		std::cout << "Введите 0 для вывода в консоль, 1 для вывода в файл: ";
		bool output{ getAnswer() };
		// check all possible outputs
		if (input == false && output == false)
		{
			// outputting on console
			solution(std::cout);
			std::cout << "Хотите повторить ввод исходных данных? Да — 1, Нет — 0.\n";
			if (getAnswer())
				continue;
			else
			{
				std::cout << "Конец программы.\n";
				break;
			}
		}
		else if (input == false && output == true)
		{
			// outputting in file
			solution(outf);
			std::cout << "Хотите повторить ввод исходных данных? Да — 1, Нет — 0.\n";
			if (getAnswer())
				continue;
			else
			{
				std::cout << "Конец программы.\n";
				break;
			}
		}
		else if (input == true && output == false)
		{
			// file to console
			fileSolution(inf, std::cout);
			break;
		}
		else if (input == true && output == true)
		{
			// file to file
			fileSolution(inf, outf);
			break;
		}
	}

	return 0;
}
