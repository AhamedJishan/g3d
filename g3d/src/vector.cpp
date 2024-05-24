#include "g3d/vector.h"

namespace g3d
{
	std::ostream& operator<<(std::ostream& os, vec2 vec)
	{
		os << "vec2 (" << vec.x << ", " << vec.y << ")";
		return os;
	}
}