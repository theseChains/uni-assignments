#include "MatrixOperations.h"

#include <ranges>
#include <stdexcept>

Matrix getIdentityMatrix()
{
	Matrix identityMatrix{};

	for (int row : std::views::iota(0, 10))
	{
		for (int column : std::views::iota(0, 10))
		{
			identityMatrix[row,column] = (row == column);
		}
	}

	return identityMatrix;
}

[[nodiscard]] Matrix MatrixOperations::getMatrixRaisedToPower(Matrix matrix, int power)
{
	// в нашем случае степень - это длина маршрута, отрицательная степень не имеет смысла
	if (power < 0)
		throw std::runtime_error{ "Matrix::raiseMatrixToPower: power is less than 0" };

	// определяем результирующую матрицу, инициализируем её единичной матрицей
	Matrix result{ getIdentityMatrix() };
	// также определяем вспомогательную временную матрицу для сохранения результатов произведений
	Matrix temporary{};

	// можем использовать алгоритм бинарного возведения в степень
	// таким образом, асимптотика алгоритма равна O(n^3 * logk), n - размер матрицы, k - степень
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
		matrix *= matrix;
	}

	return result;
}
