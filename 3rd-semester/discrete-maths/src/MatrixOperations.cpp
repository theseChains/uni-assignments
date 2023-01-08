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
	if (power < 0)
		throw std::runtime_error{ "MatrixOperations::getMatrixRaisedToPower: power is less than 0" };

	Matrix result{ getIdentityMatrix() };
	Matrix temporary{};

	// binary exponentation algorithm
	while (power)
	{
		if (power & 1)
		{
			temporary = result * matrix;
			result = temporary;
		}

		power >>= 1;
		if (!power)
			return result;

		matrix *= matrix;
	}

	return result;
}
