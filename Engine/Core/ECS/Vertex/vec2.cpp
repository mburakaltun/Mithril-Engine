#include "vec2.h"
#include <functional>

namespace Mithril
{
	vec2::vec2() : x(0), y(0)
	{
	}

	vec2::vec2(float x, float y) : x(x), y(y)
	{
	}

	vec2::vec2(const vec2& other) : x(other.x), y(other.y)
	{
	}

	bool vec2::operator==(const vec2& other) const
	{
		return (x == other.x) && (y == other.y);
	}
}