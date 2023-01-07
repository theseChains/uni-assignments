#ifndef MATRIX_H
#define MATRIX_H

#include <array>

class Matrix
{
private:
	std::array<std::array<int, 10>, 10> m_matrix{};

public:
	Matrix() = default;
	Matrix(const std::array<std::array<int, 10>, 10>& matrix);

	int& operator[](int row, int column);
	const int& operator[](int row, int column) const;
	Matrix operator*(const Matrix& multiplier);
	Matrix& operator*=(const Matrix& multiplier);

	void printMatrix() const;
};

#endif
