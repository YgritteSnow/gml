#include "../include/vector.h"
#include "../include/math_util.h"
#include <cmath>
#include <cassert>

namespace gml
{
	const vec3 vec3::zero(0.0f, 0.0f, 0.0f);
	const vec3 vec3::one(1.0f, 1.0f, 1.0f);
	const vec3 vec3::left(-1.0f, 0.0f, 0.0f);
	const vec3 vec3::right(1.0f, 0.0f, 0.0f);
	const vec3 vec3::up(0.0f, 1.0f, 0.0f);
	const vec3 vec3::down(0.0f, -1.0f, 0.0f);
	const vec3 vec3::forward(0.0f, 0.0f, 1.0f);
	const vec3 vec3::backward(0.0f, 0.0f, -1.0f);

	vec3::vec3()
	{
	}

	vec3::vec3(float x, float y, float z)
	{
		set(x, y, z);
	}

	vec3::vec3(const vec2& vec2, float z)
	{
		set(vec2.x, vec2.y, z);
	}

	vec3::vec3(const vec3& other)
	{
		set(other.x, other.y, other.z);
	}

	vec3::vec3(const vec4& vec4)
	{
		set(vec4.x, vec4.y, vec4.z);
	}

	vec3 vec3::operator-() const
	{
		return vec3(-x, -y, -z);
	}

	vec3& vec3::operator=(const vec3& rhs)
	{
		if (&rhs != this)
		{
			set(rhs.x, rhs.y, rhs.z);
		}
		return *this;
	}

	bool vec3::operator==(const vec3& rhs) const
	{
		if (&rhs == this)
			return true;

		return fequal(x, rhs.x) &&
			fequal(y, rhs.y) &&
			fequal(z, rhs.z);
	}

	bool vec3::operator!=(const vec3& rhs) const
	{
		return !(*this == rhs);
	}

	vec3 vec3::operator+(float value) const
	{
		vec3 copy(*this);
		copy += value;
		return copy;
	}

	vec3 vec3::operator-(float value) const
	{
		vec3 copy(*this);
		copy -= value;
		return copy;
	}

	vec3 vec3::operator*(float value) const
	{
		vec3 copy(*this);
		copy *= value;
		return copy;
	}

	vec3 vec3::operator+(const vec3& rhs) const
	{
		return vec3(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	vec3 vec3::operator-(const vec3& rhs) const
	{
		return vec3(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	vec3 vec3::operator*(const vec3& rhs) const
	{
		return vec3(x * rhs.x, y * rhs.y, z * rhs.z);
	}

	vec3& vec3::operator+=(float value)
	{
		x += value;
		y += value;
		z += value;
		return *this;
	}

	vec3& vec3::operator-=(float value)
	{
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	vec3& vec3::operator*=(float value)
	{
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	vec3& vec3::operator+=(const vec3& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	vec3& vec3::operator-=(const vec3& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	vec3& vec3::operator*=(const vec3& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}

	float& vec3::operator[](int index)
	{
		return const_cast<float&>(const_cast<const vec3*>(this)->operator[](index));
	}

	const float& vec3::operator[](int index) const
	{
		assert(index >= 0 && index < 3);
		return *(&x + index);
	}

	vec3& vec3::set(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		return *this;
	}

	vec3& vec3::set(const vec4& vec4)
	{
		set(vec4.x, vec4.y, vec4.z);
		return *this;
	}

	vec3 vec3::normalized() const
	{
		vec3 copy(*this);
		return copy.normalize();
	}

	vec3& vec3::normalize()
	{
		float lengthrev = length();
		if (!fequal(lengthrev, 0.0f))
		{
			lengthrev = 1.0f / lengthrev;
			this->x *= lengthrev;
			this->y *= lengthrev;
			this->z *= lengthrev;
		}
		else
		{
			*this = zero;
		}
		return *this;
	}
	
	vec3& vec3::clamp()
	{
		if (x > 1.0f) x = 1.0f;
		else if (x < 0.0f) x = 0.0f;

		if (y > 1.0f) y = 1.0f;
		else if (y < 0.0f) y = 0.0f;

		if (z > 1.0f) z = 1.0f;
		else if (z < 0.0f) z = 0.0f;

		return *this;
	}

	vec3 vec3::clamped() const
	{
		vec3 copy(*this);
		return copy.clamp();
	}

	vec3& vec3::inverse()
	{
		x = 1.0f / x;
		y = 1.0f / y;
		z = 1.0f / z;
		return *this;
	}

	vec3 vec3::inversed() const
	{
		vec3 copy(*this);
		return copy.inverse();
	}

	float vec3::length() const
	{
		return sqrtf(x*x + y*y + z*z);
	}

	float vec3::length_sqr() const
	{
		return x*x + y*y + z*z;
	}

	vec3 operator+(float value, const vec3& rhs)
	{
		return rhs + value;
	}

	vec3 operator-(float value, const vec3& rhs)
	{
		return rhs - value;
	}

	vec3 operator*(float value, const vec3& rhs)
	{
		return rhs * value;
	}

	float dot(const vec3& lhs, const vec3& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	vec3 cross(const vec3& lhs, const vec3& rhs)
	{
		return vec3(
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x
			);
	}

	vec3 min_combine(const vec3& lhs, const vec3& rhs)
	{
		return vec3(
			lhs.x < rhs.x ? lhs.x : rhs.x,
			lhs.y < rhs.y ? lhs.y : rhs.y,
			lhs.z < rhs.z ? lhs.z : rhs.z
			);
	}

	vec3 max_combine(const vec3& lhs, const vec3& rhs)
	{
		return vec3(
			lhs.x > rhs.x ? lhs.x : rhs.x,
			lhs.y > rhs.y ? lhs.y : rhs.y,
			lhs.z > rhs.z ? lhs.z : rhs.z
			);
	}
}