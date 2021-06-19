#include "VertexPNT.h"

namespace Mithril
{
	VertexPNT::VertexPNT() : coords(), normal(), uv()
	{
	}

	VertexPNT::VertexPNT(const vec3& coords, const vec3& normal, const vec2& uv) : coords(coords), normal(normal), uv(uv)
	{
	}

	VertexPNT::VertexPNT(float cx, float cy, float cz, float nx, float ny, float nz, float uvx, float uvy) :
		coords(cx, cy, cz),
		normal(nx, ny, nz),
		uv(uvx, uvy)
	{
	}

	bool VertexPNT::operator==(const VertexPNT& other) const
	{
		return (coords == other.coords) && (normal == other.normal) && (uv == other.uv);
	}
}