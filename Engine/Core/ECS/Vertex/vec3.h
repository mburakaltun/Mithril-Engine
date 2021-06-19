#pragma once

namespace Mithril
{
	class vec3
	{
	public:
		vec3();
		vec3(float value);
		vec3(float x, float y, float z);
		vec3(const vec3& other);

		vec3 operator+(const vec3& other) const;
		vec3 operator-(const vec3& other) const;
		void operator+=(const vec3& other);
		void operator-=(const vec3& other);
		bool operator==(const vec3& other) const;
		bool operator!=(const vec3& other) const;
		void operator*=(const vec3& other);
		void operator*=(const float value);
		vec3 operator*(const float value) const;
		vec3 operator/(const float value) const;
		void operator/=(const float value);
		void operator=(const float value);

		float x;
		float y;
		float z;
	};
}