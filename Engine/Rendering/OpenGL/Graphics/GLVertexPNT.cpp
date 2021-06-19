#include "GLVertexPNT.h"

namespace Mithril
{
	GLVertexPNT::GLVertexPNT() :
		m_vertexCoords(0.0f),
		m_normal(0.0f),
		m_textureCoords(0.0f)
	{
	}

	GLVertexPNT::GLVertexPNT(const float x, const float y, const float z) : m_vertexCoords(x, y, z)
	{
	}

	GLVertexPNT::GLVertexPNT(const float vx, const float vy, const float vz,
		const float nx, const float ny, const float nz, 
		const float tx, const float ty) : 
		m_vertexCoords(vx, vy, vz),
		m_normal(nx, ny, nz),
		m_textureCoords(tx, ty)
	{
	}

	GLVertexPNT::GLVertexPNT(const vec3& vertexCoords) : m_vertexCoords(vertexCoords)
	{
	}

	GLVertexPNT::GLVertexPNT(const vec3& vertexCoords, const vec3& normal, const vec2& textureCoords) :
		m_vertexCoords(vertexCoords),
		m_normal(normal),
		m_textureCoords(textureCoords)
	{
	}
}