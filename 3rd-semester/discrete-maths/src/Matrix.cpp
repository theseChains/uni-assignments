#include "Matrix.h"

#include <iostream>
#include <ranges>
#include <stdexcept>

Matrix::Matrix(const std::array<std::array<int, 10>, 10>& matrix) : m_matrix{ matrix }
{
}

int& Matrix::operator[](int row, int column)
{
	if (row < 0 || row > 9 || column < 0 || column > 9)
		throw std::out_of_range{ "Matrix::operator[]: index out of range" };

	return m_matrix[row][column];
}

const int& Matrix::operator[](int row, int column) const
{
	if (row < 0 || row > 9 || column < 0 || column > 9)
		throw std::out_of_range{ "Matrix::operator[]: index out of range" };

	return m_matrix[row][column];
}

Matrix Matrix::operator*(const Matrix& multiplier)
{
	Matrix result{};
	for (int row : std::views::iota(0, 10))
	{
		for (int column : std::views::iota(0, 10))
		{
			for (int index : std::views::iota(0, 10))
			{
				result[row,column] += m_matrix[row][index] * multiplier[index,column];
			}
		}
	}

	return result;
}

Matrix& Matrix::operator*=(const Matrix& multiplier)
{
	*this = *this * multiplier;
	return *this;
}

void Matrix::printMatrix() const
{
	for (const auto& row : m_matrix)
	{
		for (const auto& element : row)
		{
			std::cout << element << ' ';
		}
		std::cout << '\n';
	}
}
