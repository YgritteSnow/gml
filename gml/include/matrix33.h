#pragma once
#include <gml/include/vector3.h>

namespace gml
{
	class matrix33
	{
	public:
		static const matrix33 I;
	public:
		union
		{
			float m[3][3] = { 0,0,0,0,0,0,0,0,0 };
			struct { float _00, _01, _02, _10, _11, _12, _20, _21, _22; };
			struct { vector3 row[3]; };
		};

		matrix33();

		explicit matrix33(float _00, float _01, float _02, float _10, float _11, float _12, float _20, float _21, float _22);

		matrix33(const matrix33& other);

		matrix33& operator=(const matrix33& other);

		float& operator[] (int index);

		const float& operator[] (int index) const;

		matrix33& identity();

		matrix33& transpose();

		matrix33& inverse();

		float determinant();
	};
}
