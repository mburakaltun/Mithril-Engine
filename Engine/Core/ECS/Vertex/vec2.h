#pragma once

namespace Mithril
{
	class vec2
	{
	public:
		vec2();
		vec2(float x, float y);
		vec2(const vec2& other);

		bool operator==(const vec2& other) const;

		float x;
		float y;
	};
}