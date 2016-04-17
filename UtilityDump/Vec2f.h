#ifndef VEC2F_H
#define VEC2F_H
// 12/03/16
class Vec2f
{
public:
	float x, y;

	Vec2f(); // CONSTRUCTOR

	Vec2f(float a); // CONSTRUCTOR

	Vec2f(float x, float y); // CONSTRUCTOR

	Vec2f(const Vec2f &vec); // CONSTRUCTOR

	void set(float x, float y); // SET()

	void set(const Vec2f &vec); // SET()

	float length(); // LENGTH()

	float lengthSquared(); // LENGTH_SQUARED

	void normalize(); // NORMALIZE()

	Vec2f getNormal(); // GETNORMAL()

	float dot(Vec2f &vec); // DOT()

	Vec2f operator+ (Vec2f &vec); // PLUS()

	Vec2f operator- (Vec2f &vec); // MINUS()

	Vec2f operator* (Vec2f &vec); // TIMES()

	void operator* (float scalar); // TIMES()

	Vec2f operator/ (Vec2f &vec);

	void operator+= (Vec2f &vec);

	void operator-= (Vec2f &vec);

	void operator*= (Vec2f &vec);

	void operator/= (Vec2f &vec);

	void operator= (Vec2f &vec); // ASSIGNMENT;

	bool operator!= (Vec2f &vec); // NOT_EQUALS();

	bool operator== (Vec2f &vec); // EQUALS();

	void rotate (float deg); // COMPLEX ROTATION;

	void rotate (Vec2f &vec); // COMPLEX ROTATION;

//	void rotateByLongVer(float deg); // COMPLEX ROTATION

};

#endif // VEC2F_H

