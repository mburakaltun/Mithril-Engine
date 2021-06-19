#include "vec3.h"

namespace Mithril
{
	vec3::vec3() : x(0.0f), y(0.0f), z(0.0f)
	{
	}

	vec3::vec3(float value) : x(value), y(value), z(value)
	{
	}

	vec3::vec3(float x, float y, float z) : x(x), y(y), z(z)
	{
	}

	vec3::vec3(const vec3& other) : x(other.x), y(other.y), z(other.z)
	{
	}

	vec3 vec3::operator+(const vec3& other) const
	{
		return vec3(x + other.x, y + other.y, z + other.z);
	}

	vec3 vec3::operator-(const vec3& other) const
	{
		return vec3(x - other.x, y - other.y, z - other.z);
	}

	void vec3::operator+=(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	}

	void vec3::operator-=(const vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
	}

	bool vec3::operator==(const vec3& other) const
	{
		return x == other.x && y == other.y && z == other.z;
	}

	bool vec3::operator!=(const vec3& other) const
	{
		return x != other.x || y != other.y || z != other.z;
	}

	void vec3::operator*=(const vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
	}

	void vec3::operator*=(const float value)
	{
		x *= value;
		y *= value;
		z *= value;
	}

	vec3 vec3::operator*(const float value) const
	{
		return vec3(x * value, y * value, z * value);
	}

	vec3 vec3::operator/(const float value) const
	{
		return vec3(x/value, y/value, z/value);
	}

	void vec3::operator/=(const float value)
	{
		x /= value;
		y /= value;
		z /= value;
	}

	void vec3::operator=(const float value)
	{
		x = value;
		y = value;
		z = value;
	}
}