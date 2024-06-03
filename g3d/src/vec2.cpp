#include "g3d/vec2.h"

#include <cmath>

namespace g3d
{

	float vec2::magnitude() const
	{
		return sqrt(x*x + y*y);
	}

	float vec2::sqrMagnitude() const
	{
		return (x * x + y * y);
	}

	void vec2::normalize()
	{
		float m = magnitude();

		if (m == 0.0f) 
			return;

		x = x / m;
		y = y / m;
	}

	vec2 vec2::normalized() const
	{
		float m = magnitude();

		if (m == 0.0f)
			return (vec2(0,0));

		vec2 v;
		v.x = x / m;
		v.y = y / m;
		return v;
	}

	float vec2::dot(const vec2& other) const
	{
		return x * other.x + y * other.y;
	}

	float vec2::cross(const vec2& other) const
	{
		return x * other.y - y * other.x;
	}

	std::ostream& operator<<(std::ostream& os, const vec2& vec)
	{
		os << "(" << vec.x << ", " << vec.y << ")";
		return os;
	}
}