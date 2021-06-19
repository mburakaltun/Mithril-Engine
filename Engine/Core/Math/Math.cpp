#include "Math.h"
#include <math.h>

namespace Mithril
{
	float Math::radians(const float value)
	{
		return value * 0.0174533f;
	}
	float Math::length(const vec3& v)
	{
		return sqrtf(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	}
	vec3 Math::normalize(const vec3& v)
	{
		return v / length(v);
	}

	vec3 Math::cross(const vec3& v1, const vec3& v2)
	{
		return vec3(
			v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x
		);
	}

	float Math::dot(const vec3& v1, const vec3& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}
}
