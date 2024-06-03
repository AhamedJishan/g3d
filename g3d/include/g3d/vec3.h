#pragma once

#include <iostream>

namespace g3d
{
	// A 3-dimensional vector (x, y).
	class vec3
	{
	public:
		// Elements of vec2
		float x, y;

		// @brief Constructs a Vec2 object with the specified coordinates.
		// @param X: The x-coordinate of the vector. Default is 0.0f.
		// @param Y: The y-coordinate of the vector. Default is 0.0f.
		// @details This constructor initializes a Vec2 object with the given coordinates.
		// If no coordinates are provided, the default values are (0.0f, 0.0f).
		vec2(float X = 0.0f, float Y = 0.0f)
			: x(X), y(Y) {}

		// @brief Magnitude of the vector.
		// @returns 'magnitude', calculated by sqrt(x*x + y*y).
		float magnitude() const;


		// @brief Square of magnitude.
		// Use this when actual magnitude isn't required.
		// Faster than 'magnitude()'.
		// @returns Square of 'magnitude', calculated by (x*x + y*y).
		float sqrMagnitude() const;

		// @brief Normalizes the given vector.
		void normalize();

		// @brief Returns a normalized version of the vector.
		// @returns Normalized vec2, calculated by x=x/m, y=y/m. ('m' = magnitude of the vector)
		vec2 normalized() const;

		// @brief Computes the dot product of this vec2 with another vec2.
		// @param other: The other vec2 object.
		// @return The dot product of this Vec2(x1, y1) and the other Vec2(x2, y2).
		// Calculated as: dot = x1 * x2 + y1 * y2
		float dot(const vec2& other) const;

		// @brief Computes the dot product of vec2 A with another vec2 B.
		// @param A: The first vec2 object.
		// @param B: The second vec2 object.
		// @return The dot product of this Vec2(x1, y1) and the other Vec2(x2, y2).
		// Calculated as: dot = x1 * x2 + y1 * y2
		static float dot(const vec2& A, const vec2& B)
		{
			return A.x * B.x + A.y * B.y;
		}

		// @brief Computes the cross product of this vec2 with another vec2. (Note: In 2D vectors
		// the cross product just returns a scalar instead of another vector)
		// @param other: The other vec2 object.
		// @return The cross product of this Vec2(x1, y1) and the other Vec2(x2, y2).
		// Calculated as: cross = x1 * y2 - y1 * x2
		float cross(const vec2& other) const;

		// @brief Computes the cross product of two vec2 'A' and 'B'. (Note: In 2D vectors
		// the cross product just returns a scalar instead of another vector)
		// @param A: The first vec2 object.
		// @param B: The second vec2 object.
		// @return The cross product of A and B.
		// Calculated as: cross = A.x * B.y - A.y * B.x
		static float cross(const vec2& A, const vec2& B)
		{
			return A.x * B.y - A.y * B.x;
		}

		// @brief Finds the angle between two vectors in radians.
		// @param A: The first vec2 object.
		// @param B: The second vec2 object.
		// @return The angle between A and B, in radians.
		// Calculated as: Angle = arccos( (A•B) / (|A| * |B|) )
		static float angleBetween(const vec2& A, const vec2& B)
		{
			return acos(dot(A, B) / (A.magnitude() * B.magnitude()));
		}


		// Arithemetical operator overloads
		inline vec2 vec2::operator+(const vec2& other) const { return vec2(x + other.x, y + other.y); }
		inline vec2 vec2::operator-(const vec2& other) const { return vec2(x - other.x, y - other.y); }
		inline vec2 vec2::operator*(const float scalar) const
		{
			if (scalar == 0) return vec2(x, y);
			return vec2(x * scalar, y * scalar);
		}
		inline vec2 vec2::operator/(const float scalar) const
		{
			if (scalar == 0) return vec2(x, y);
			return vec2(x / scalar, y / scalar);
		}

		friend std::ostream& operator<<(std::ostream& os, const vec2& vec);
	};
}