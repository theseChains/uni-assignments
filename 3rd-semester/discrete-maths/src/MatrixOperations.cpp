#include "MatrixOperations.h"

#include <iostream>
#include <ranges>

// todo: make a matrix class bro

Matrix operator*(const Matrix& first, const Matrix& second)
{
	Matrix result{};
	// 3 цикла, итерирующие от 0 до 9
	for (int row : std::views::iota(0, 10))
	{
		for (int column : std::views::iota(0, 10))
		{
			// todo: change something to a more meaningful name
			for (int something : std::views::iota(0, 10))
			{
				// todo: explain this, i guess?
				result[row][column] += first[row][something] * second[something][column];
			}
		}
	}

	return result;
}

[[nodiscard]] Matrix MatrixOperations::raiseMatrixToPower(Matrix& matrix, int power)
{
	// todo: if power == 0 then return identity matrix
	// если степень равна 1, то возвращаем данную матрицу
	if (power == 1)
		return matrix;

	// определяем результирующую матрицу, инициализируем её данной матрицей
	Matrix result{ matrix };
	// также определяем вспомогательную временную матрицу для сохранения результатов произведений
	Matrix temporary{};

	// можем использовать алгоритм бинарного возведения в степень
	// вычитаем из степени единичку, так как в результате уже находится исходная матрица
	--power;
	while (power)
	{
		// степень нечётная, вычитаем из степени 1
		if (power & 1)
		{
			// перемножаем результирующую матрицу с данной
			temporary = result * matrix;
			// сохраняем результат умножения в результирующую матрицу
			result = temporary;
		}

		// степень чётная
		// делим степень на 2
		power >>= 1;
		// проверяем, не равна ли степень нулю, чтобы лишний раз не возводить матрицу в квадрат
		if (!power)
			return result;

		// возводим данную матрицу в квадрат
		matrix = matrix * matrix;
	}

	return result;
}
