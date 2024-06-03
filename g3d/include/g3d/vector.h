#pragma once

#include <iostream>

namespace g3d
{
	class vec2
	{
	public:
		float x, y;

		vec2(float X = 0.0f, float Y = 0.0f)
			: x(X), y(Y) {}

		// Magnitude of the Vector
		float magnitude() const;

		// Square of the magnitude, use this when actual magnitude isn't required
		// and you just want to compare magnitudes. Faster than magnitude().
		float sqrMagnitude() const;

		// Normalizes the vector.
		void normalize();

		// Returns a normalized version of the vector.
		vec2 normalized() const;


		// Arithemetical operator overloads
		inline vec2 vec2::operator+(const vec2& other) const { return vec2(x + other.x, y + other.y); }
		inline vec2 vec2::operator-(const vec2& other) const { return vec2(x - other.x, y - other.y); }
		inline vec2 vec2::operator*(const float scalar) const
		{
			if (scalar == 0) return vec2(x,y);
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