#ifndef MAT4F_H
#define MAT4F_H

#include "Vec4f.h"
// 12/03/16
class Mat4f
{
private:
	float m [4][4];


public:
	Mat4f();
	Mat4f(const Mat4f &mat); // CONSTRUCTOR

	// SET()
	void set(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p); // SET()

	void set(const Mat4f &mat); // SET()

	void set(float value, int row, int col); // SET()

	void setScale(float sx, float sy, float sz); // SETSCALE()

	void setTranslate(float tx, float ty, float tz); // SETTRANSLATE()

	void setIdentity(); // SETIDENTITY()

	float get (int row, int col); // GET()

	Vec4f operator* (Vec4f &vec); // TIMES()

	void invert(); // INVERT()

	void setRotate(); // SETROTATE()
};
#endif // MAT4F_H
