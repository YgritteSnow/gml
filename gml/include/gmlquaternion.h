#pragma once
#include <gmlvector.h>
namespace gml
{
	class quat
	{
	public:
		static const quat Ipos;
		static const quat Ineg;

	public:
		float w;
		vec3 v;

	public:
		quat();

		quat(const vec3& axis, float radius);

		quat operator-() const;

		quat operator+(const quat& rhs) const;

		quat operator*(const quat& rhs) const;

		quat operator*(float scaler) const;

		quat& operator+=(const quat& rhs);

		quat& operator*=(float scaler);

		quat& normalize();

		quat normalized() const;

		quat& conjugate();

		quat conjugated() const;

		quat& inverse();

		quat inversed() const;

		float length() const;

		float length_sqr() const;

	private:
		quat(float rawW, const vec3& rawN);
	};

	quat operator*(float scaler, const quat& q);

	float dot(const quat& lhs, const quat& rhs);

	vec3 rotate(const quat& rotation, const vec3& point);

	quat slerp(const quat& s, const quat& d, float f);
}