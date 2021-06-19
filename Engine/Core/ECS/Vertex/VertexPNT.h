#pragma once

//Vertex object that has Position, normals and UV's as its attributes
#include "vec2.h"
#include "vec3.h"

namespace Mithril
{
	class VertexPNT
	{
	public:
		VertexPNT();
		VertexPNT(const vec3& coords, const vec3& normal, const vec2& uv);
		VertexPNT(float cx, float cy, float cz, float nx, float ny, float nz, float uvx, float uvy);
		//3D coordinates

		bool operator==(const VertexPNT& other) const;

		vec3 coords;

		//Normal coordinates
		vec3 normal;

		//Texture coordinates
		vec2 uv;
	};

	class VertexPNT;
}