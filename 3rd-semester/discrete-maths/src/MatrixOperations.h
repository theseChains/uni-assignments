#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <array>

using Matrix = std::array<std::array<int, 10>, 10>;

class MatrixOperations
{
public:
	static Matrix raiseMatrixToPower(Matrix& matrix, int power);
};

#endif
