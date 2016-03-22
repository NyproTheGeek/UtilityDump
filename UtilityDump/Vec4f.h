#ifndef VEC4F_H
#define VEC4F_H
// 12/03/16
class Vec4f
{
public:
	float x, y, z, w;

	Vec4f (); // CONSTRUCTOR

	Vec4f (float xx); // CONSTRUCTOR

	Vec4f (float x, float y, float z, float w); // CONSTRUCTOR

	Vec4f (const Vec4f &vec); // CONSTRUCTOR

	void set(float x, float y, float z, float w); // SET();

	void set(Vec4f vec); // SET();

	float length(); // LENGTH();

	float lengthSquared(); // LENGTH_SQUARED;

	void normalize(); // NORMALIZE();

	Vec4f getNormal(); // GETNORMAL();

	float dot(Vec4f &vec); // DOT();

	Vec4f cross(Vec4f &vec); // CROSS();

	Vec4f operator+ (Vec4f &vec); // PLUS();

	Vec4f operator- (Vec4f &vec); // MINUS();

	Vec4f operator* (Vec4f &vec); // TIMES();

	void operator* (float scalar); // TIMES();

	Vec4f operator/ (Vec4f &vec);

	void operator+= (Vec4f &vec);

	void operator-= (Vec4f &vec);

	void operator*= (Vec4f &vec);

	void operator/= (Vec4f &vec);

	void operator= (Vec4f vec); // ASSIGNMENT;

	bool operator== (Vec4f &vec); // EQUALS();

	bool operator!= (Vec4f &vec); // EQUALS();
};
#endif // VEC4F_H

