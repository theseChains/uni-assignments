#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "Matrix.h"

class MatrixOperations
{
public:
	[[nodiscard]] static Matrix getMatrixRaisedToPower(Matrix matrix, int power);
};

#endif
