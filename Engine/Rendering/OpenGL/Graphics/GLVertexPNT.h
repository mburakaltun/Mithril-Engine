#pragma once

#include <glm/glm.hpp>

using vec3 = glm::vec3;
using vec2 = glm::vec2;

namespace Mithril
{
	class GLVertexPNT
	{
	public:
		GLVertexPNT(); //initializes evertyhing to 0
		GLVertexPNT(const float x, const float y, const float z);
		GLVertexPNT(const float vx, const float vy, const float vz,
			const float nx, const float ny, const float nz, 
			const float tx, const float ty);
		GLVertexPNT(const vec3& vertexCoords);
		GLVertexPNT(const vec3& vertexCoords, const vec3& normal, const vec2& textureCoords);
		vec3 m_vertexCoords;
		vec3 m_normal;
		vec2 m_textureCoords;
	};
}