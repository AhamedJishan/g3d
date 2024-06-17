#pragma once

#include <iostream>

#include "g3d/vec3.h"

namespace g3d
{
	// A 3x3 matrix
	class mat3
	{
	private:
		float m_data[3][3];

	public:

		// mat3 Constructor constructing a default zero matrix
		mat3();

		// mat3 Constructor constructing a diagonal matrix with the provided value
		mat3(const float value);

		// mat3 Constructor constructing a matrix from the given 2D Array
		mat3(const float value[3][3]);

		// mat3 Constructor for constructing a diagonal matrix with the given vec3
		mat3(const vec3& vec);

		/**
		* @brief Accesses the element at the specified row and column of the matrix.
		* 
		* EXAMPLE (set the value): matrix.at(0, 0) = 1.0f;
		* EXAMPLE (get the value): float value = matrix.at(0, 0);
		*
		* This function provides access to the element at the specified position
		* in the matrix. It performs no bounds checking, so it is the caller's
		* responsibility to ensure the indices are within valid range.
		* 
		* @param row: The row index of the element to access (0-based).
		* @param col: The column index of the element to access (0-based).
		* @return A reference to the element at the specified position.
		* 
		* @throws std::out_of_range If the indices are out of bounds (optional, if you choose to add bounds checking).
		*/
		float& at(int row, int col) { return m_data[row][col]; }
		float at(int row, int col) const { return m_data[row][col]; }

		/**
		* @brief Accesses the element at the specified row and column of the matrix.
		* 
		* EXAMPLE (set the value): matrix(0, 0) = 1.0f;
		* EXAMPLE (get the value): float value = matrix(0, 0);
		*
		* This function provides access to the element at the specified position
		* in the matrix. It performs no bounds checking, so it is the caller's
		* responsibility to ensure the indices are within valid range.
		* 
		* @param row: The row index of the element to access (0-based).
		* @param col: The column index of the element to access (0-based).
		* @return A reference to the element at the specified position.
		* 
		* @throws std::out_of_range If the indices are out of bounds (optional, if you choose to add bounds checking).
		*/
		float& operator() (int row, int col) { return m_data[row][col]; }
		float operator() (int row, int col) const { return m_data[row][col]; }
		
		mat3 operator+(const mat3& other) const;
		mat3 operator-(const mat3& other) const;
		mat3 operator*(float scalar) const;
		mat3 operator/(float scalar) const;
		mat3 operator*(const mat3& other) const;

		bool operator==(const mat3& other) const;
		bool operator!=(const mat3& other) const;

		friend std::ostream& operator<<(std::ostream& os, const mat3& mat);
	};

}