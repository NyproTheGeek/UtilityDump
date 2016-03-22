// 14/03/16
#ifndef POSVEC2F_H
#define POSVEC2F_H
#include "Vec2f.h"

class PosVec2f
{
public:
	float a_x, a_y, b_x, b_y;
	Vec2f vector;
	float angle;


	PosVec2f();

	PosVec2f(Vec2f positionA, Vec2f positionB);

	PosVec2f(float a, float b);

	PosVec2f(float a_x, float a_y, float b_x, float b_y);

	PosVec2f(const PosVec2f &posVec);


	void set(Vec2f positionA, Vec2f positionB);

	void set(float a, float b);

	void set(float a_x, float a_y, float b_x, float b_y);

	void set(const PosVec2f &posVec);

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

	float dot(PosVec2f &posVec);

	float angleDeg();

	float angleRad();

	void operator= (PosVec2f &posVec);

	bool operator== (PosVec2f &posVec);

	bool operator!= (PosVec2f &posVec);

	void setVector();
};
#endif // POSVEC2F_H
