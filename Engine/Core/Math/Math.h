#pragma once

#include <Core/ECS/Vertex/vec3.h>

namespace Mithril
{
	class Math
	{
	public:
		static float radians(const float value);

		static float length(const vec3& v);

		static vec3 normalize(const vec3& v);

		//cross product of two vectors
		static vec3 cross(const vec3& v1, const vec3& v2);

		//dot product of two vectors
		static float dot(const vec3& v1, const vec3& v2);
	};
}