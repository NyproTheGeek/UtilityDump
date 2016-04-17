// 14/03/16
#ifndef LINE2F_H
#define LINE2F_H
#include "Vec2f.h"

class Line2f
{
public:
	float a_x, a_y, b_x, b_y;
	Vec2f vector;
	float angle;


	Line2f();

	Line2f(Vec2f positionA, Vec2f positionB);

	Line2f(float a, float b);

	Line2f(float a_x, float a_y, float b_x, float b_y);

	Line2f(const Line2f &line);


	void set(Vec2f positionA, Vec2f positionB);

	void set(float a, float b);

	void set(float a_x, float a_y, float b_x, float b_y);

	void set(const Line2f &line);

	void setA(float x, float y);

	void setA(Vec2f &vec);

	void setB(float x, float y);

	void setB(Vec2f &vec);


	Vec2f getA();

	Vec2f getB();


	void rotate(float deg);

	void rotate(Vec2f &vec);

	void rotate(float x, float y);

	void scale(Vec2f &vec);

	void scale(float x, float y);

	void translate(float x, float y);

	void translate(Vec2f &vec);

	void translateA(float x, float y);

	void translateA(Vec2f &vec);

	void translateB(float x, float y);

	void translateB(Vec2f &vec);


	float length();

	void normalize();

	Vec2f getNormal();

	float dot(Line2f &line);

	float angleDeg();

	float angleRad();

	void operator= (Line2f &line);

	bool operator== (Line2f &line);

	bool operator!= (Line2f &line);

	void setVector();
};
#endif // LINE2F_H
