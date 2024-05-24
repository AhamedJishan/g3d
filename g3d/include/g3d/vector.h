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

		inline vec2 vec2::operator+(const vec2& other) const
		{
			return vec2(x + other.x, y + other.y);
		}
		inline vec2 vec2::operator-(const vec2& other) const
		{
			return vec2(x - other.x, y - other.y);
		}

		inline vec2 vec2::operator*(const int scalar) const
		{
			return vec2(x * scalar, y * scalar);
		}
		inline vec2 vec2::operator*(const float scalar) const
		{
			return vec2(x * scalar, y * scalar);
		}

		inline vec2 vec2::operator/(const int scalar) const
		{
			return vec2(x / scalar, y / scalar);
		}
		inline vec2 vec2::operator/(const float scalar) const
		{
			return vec2(x / scalar, y / scalar);
		}

		friend std::ostream& operator<<(std::ostream& os, vec2 vec);
	};
}