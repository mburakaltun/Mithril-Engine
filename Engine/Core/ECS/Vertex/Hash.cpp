#include "Hash.h"

namespace Mithril
{
	void hashCombine(size_t& seed, size_t hash)
	{
		hash += 0x9e3779b9 + (seed << 6) + (seed >> 2);
		seed ^= hash;
	}

	size_t hash(const vec2& v)
	{
		std::hash<float> hasher;
		size_t seed = 0;

		hashCombine(seed, hasher(v.x));
		hashCombine(seed, hasher(v.y));

		return seed;
	}

	size_t hash(const vec3& v)
	{
		std::hash<float> hasher;
		size_t seed = 0;

		hashCombine(seed, hasher(v.x));
		hashCombine(seed, hasher(v.y));
		hashCombine(seed, hasher(v.z));

		return seed;
	}
}

namespace std
{
	size_t hash<Mithril::vec2>::operator()(Mithril::vec2 const& v) const
	{
		return Mithril::hash(v);
	}

	size_t hash<Mithril::vec3>::operator()(Mithril::vec3 const& v) const
	{
		return Mithril::hash(v);
	}

	size_t hash<Mithril::VertexPNT>::operator()(Mithril::VertexPNT const& v) const
	{
		return (Mithril::hash(v.coords) ^
				(Mithril::hash(v.normal) >> 1) ^
				(Mithril::hash(v.uv) << 1)
			);
	}
}