#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <array>

class MatrixOperations
{
public:
	using Matrix = std::array<std::array<bool, 10>, 10>;
	static Matrix raiseMatrixToPower(const Matrix& matrix, int power);
};

#endif
