#include "../include/vector.h"
#include "../include/math_util.h"
#include <cmath>
#include <cassert>

namespace gml
{
	const vec2 vec2::zero(0.0f, 0.0f);
	const vec2 vec2::one(1.0f, 1.0f);
	const vec2 vec2::left(-1.0f, 0.0f);
	const vec2 vec2::right(1.0f, 0.0f);
	const vec2 vec2::up(0.0f, 1.0f);
	const vec2 vec2::down(0.0f, -1.0f);

	vec2::vec2()
	{
	}

	vec2::vec2(float x, float y)
	{
		set(x, y);
	}

	vec2::vec2(const vec3& vec3)
	{
		set(vec3.x, vec3.y);
	}

	vec2 vec2::operator-() const
	{
		return vec2(-x, -y);
	}
	
	bool vec2::operator==(const vec2& rhs) const
	{
		if (&rhs == this)
			return true;

		return fequal(x, rhs.x) &&
			fequal(y, rhs.y);
	}

	bool vec2::operator!=(const vec2& rhs) const
	{
		return !(*this == rhs);
	}

	vec2 vec2::operator+(float value) const
	{
		vec2 copy(*this);
		copy += value;
		return copy;
	}

	vec2 vec2::operator-(float value) const
	{
		vec2 copy(*this);
		copy -= value;
		return copy;
	}

	vec2 vec2::operator*(float value) const
	{
		vec2 copy(*this);
		copy *= value;
		return copy;
	}

	vec2 vec2::operator+(const vec2& rhs) const
	{
		return vec2(x + rhs.x, y + rhs.y);
	}


	vec2 vec2::operator-(const vec2& rhs) const
	{
		return vec2(x - rhs.x, y - rhs.y);
	}


	vec2 vec2::operator*(const vec2& rhs) const
	{
		return vec2(rhs.x, rhs.y);
	}

	vec2& vec2::operator+=(float value)
	{
		x += value;
		y += value;
		return *this;
	}

	vec2& vec2::operator-=(float value)
	{
		x -= value;
		y -= value;
		return *this;
	}

	vec2& vec2::operator*=(float value)
	{
		x *= value;
		y *= value;
		return *this;
	}

	vec2& vec2::operator+=(const vec2& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	vec2& vec2::operator-=(const vec2& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	vec2& vec2::operator*=(const vec2& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}

	float& vec2::operator[](int index)
	{
		return const_cast<float&>(const_cast<const vec2*>(this)->operator[](index));
	}

	const float& vec2::operator[](int index) const
	{
		assert(index >= 0 && index < 2);
		return *(&x + index);
	}

	vec2::operator float*()
	{
		return &(this->x);
	}

	vec2& vec2::set(float x, float y)
	{
		this->x = x;
		this->y = y;
		return *this;
	}

	vec2& vec2::set(const vec3& other)
	{
		set(other.x, other.y);
		return *this;
	}

	vec2 vec2::normalized() const
	{
		vec2 copy(*this);
		return copy.normalize();
	}

	vec2& vec2::normalize()
	{
		float lengthrev = length();
		if (!fequal(lengthrev, 0.0f))
		{
			lengthrev = 1.0f / lengthrev;
			x *= lengthrev;
			y *= lengthrev;
		}
		else
		{
			*this = zero;
		}
		return *this;
	}

	vec2& vec2::inverse()
	{
		x = 1.0f / x;
		y = 1.0f / y;
		return *this;
	}

	vec2 vec2::inversed() const
	{
		vec2 copy(*this);
		return copy.inverse();
	}

	float vec2::length() const
	{
		return sqrtf(x*x + y*y);
	}

	float vec2::length_sqr() const
	{
		return x*x + y*y;
	}

	vec2 operator+(float value, const vec2& rhs)
	{
		return rhs + value;
	}

	vec2 operator-(float value, const vec2& rhs)
	{
		return rhs - value;
	}

	vec2 operator*(float value, const vec2& rhs)
	{
		return rhs * value;
	}

	float dot(const vec2& lhs, const vec2& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	float cross(const vec2& lhs, const vec2& rhs)
	{
		return lhs.x * rhs.y - lhs.y * rhs.x;
	}

	vec2 min_combine(const vec2& lhs, const vec2& rhs)
	{
		return vec2(
			lhs.x < rhs.x ? lhs.x : rhs.x,
			lhs.y < rhs.y ? lhs.y : rhs.y
			);
	}

	vec2 max_combine(const vec2& lhs, const vec2& rhs)
	{
		return vec2(
			lhs.x > rhs.x ? lhs.x : rhs.x,
			lhs.y > rhs.y ? lhs.y : rhs.y
			);
	}
}