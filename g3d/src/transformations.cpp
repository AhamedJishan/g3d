#include "g3d/transformations.h"

namespace g3d
{
	mat3 scale(const mat3& mat, const vec3& vec)
	{
		mat3 scaledMat(vec);
		scaledMat = mat * scaledMat;

		return scaledMat;
		return mat3();
	}
}