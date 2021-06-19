#pragma once 

#include <functional>
#include "VertexPNT.h"
/*
* Hassing functions for vector and vertex classes. Requirement of unordered map data structure
*/

namespace Mithril
{
	//Hashing helper function
	void hashCombine(size_t& seed, size_t hash);

	size_t hash(const vec2& v);

	size_t hash(const vec3& v);
}

//Hashing structs

namespace std
{
	template<> struct hash<Mithril::vec2>
	{
		size_t operator()(Mithril::vec2 const& v) const;
	};

	template<> struct hash<Mithril::vec3>
	{
		size_t operator()(Mithril::vec3 const& v) const;
	};

	template<> struct hash<Mithril::VertexPNT>
	{
		size_t operator()(Mithril::VertexPNT const& v) const;
	};
}