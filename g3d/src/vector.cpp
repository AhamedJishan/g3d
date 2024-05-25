#include "g3d/vector.h"

#include <cmath>

namespace g3d
{

	float vec2::magnitude() const
	{
		return sqrt(x*x + y*y);
	}

	std::ostream& operator<<(std::ostream& os, vec2 vec)
	{
		os << "vec2 (" << vec.x << ", " << vec.y << ")";
		return os;
	}
}