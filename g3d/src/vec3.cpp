#include "g3d/vec3.h"

#include <cmath>

namespace g3d
{

	float vec3::magnitude() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	float vec3::sqrMagnitude() const
	{
		return (x * x + y * y + z * z);
	}

	void vec3::normalize()
	{
		float m = magnitude();

		if (m == 0.0f)
			return;

		x = x / m;
		y = y / m;
		z = z / m;
	}

	vec3 vec3::normalized() const
	{
		float m = magnitude();

		if (m == 0.0f)
			return (vec3(0, 0, 0));

		vec3 v;
		v.x = x / m;
		v.y = y / m;
		v.z = z / m;

		return v;
	}

	float vec3::dot(const vec3& other) const
	{
		return (x * other.x) + (y * other.y) + (z * other.z);
	}

	vec3 vec3::cross(const vec3& other) const
	{
		return vec3((y * other.z - z * other.y),
					(z * other.x - x * other.z),
					(x * other.y - y * other.x));
	}

	std::ostream& operator<<(std::ostream& os, const vec3& vec)
	{
		os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
		return os;
	}
}