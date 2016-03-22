#include "Mat4f.h"
// 13/03/16

Mat4f::Mat4f()
{
	this->m[0][0] = 1.0;
	this->m[0][1] = 0.0;
	this->m[0][2] = 0.0;
	this->m[0][3] = 0.0;
	this->m[1][0] = 0.0;
	this->m[1][1] = 1.0;
	this->m[1][2] = 0.0;
	this->m[1][3] = 0.0;
	this->m[2][0] = 0.0;
	this->m[2][1] = 0.0;
	this->m[2][2] = 1.0;
	this->m[2][3] = 0.0;
	this->m[3][0] = 0.0;
	this->m[3][1] = 0.0;
	this->m[3][2] = 0.0;
	this->m[3][3] = 1.0;
}

Mat4f::Mat4f(const Mat4f &mat) // CONSTRUCTOR
{
    set(mat);
}

// SET()
void Mat4f::set(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p) // SET()
{
    this->m[0][0] = a;
    this->m[0][1] = b;
    this->m[0][2] = c;
    this->m[0][3] = d;
    this->m[1][0] = e;
    this->m[1][1] = f;
    this->m[1][2] = g;
    this->m[1][3] = h;
    this->m[2][0] = i;
    this->m[2][1] = j;
    this->m[2][2] = k;
    this->m[2][3] = l;
    this->m[3][0] = m;
    this->m[3][1] = n;
    this->m[3][2] = o;
    this->m[3][3] = p;
}

void Mat4f::set(const Mat4f &mat) // SET()
{
    this->m[0][0] = mat.m[0][0];
    this->m[0][1] = mat.m[0][1];
    this->m[0][2] = mat.m[0][2];
    this->m[0][3] = mat.m[0][3];
    this->m[1][0] = mat.m[1][0];
    this->m[1][1] = mat.m[1][1];
    this->m[1][2] = mat.m[1][2];
    this->m[1][3] = mat.m[1][3];
    this->m[2][0] = mat.m[2][0];
    this->m[2][1] = mat.m[2][1];
    this->m[2][2] = mat.m[2][2];
    this->m[2][3] = mat.m[2][3];
    this->m[3][0] = mat.m[3][0];
    this->m[3][1] = mat.m[3][1];
    this->m[3][2] = mat.m[3][2];
    this->m[3][3] = mat.m[3][3];
}

void Mat4f::set(float value, int row, int col)
{
	m[row][col] = value;
}

void Mat4f::setScale(float sx, float sy, float sz) // SETSCALE()
{
    this->m[0][0] = sy;
    this->m[1][1] = sx;
    this->m[2][2] = sz;
}


void Mat4f::setTranslate(float tx, float ty, float tz) // SETTRANSLATE()
{
    this->m[0][3] = tx;
    this->m[1][3] = ty;
    this->m[2][3] = tz;
}

void Mat4f::setIdentity() // SETIDENTITY()
{
    this->m[0][0] = 1.0;
    this->m[0][1] = 0.0;
    this->m[0][2] = 0.0;
    this->m[0][3] = 0.0;
    this->m[1][0] = 0.0;
    this->m[1][1] = 1.0;
    this->m[1][2] = 0.0;
    this->m[1][3] = 0.0;
    this->m[2][0] = 0.0;
    this->m[2][1] = 0.0;
    this->m[2][2] = 1.0;
    this->m[2][3] = 0.0;
    this->m[3][0] = 0.0;
    this->m[3][1] = 0.0;
    this->m[3][2] = 0.0;
    this->m[3][3] = 1.0;
}


float Mat4f::get(int row, int col) // GET()
{
    return m[row][col];
}


Vec4f Mat4f::operator* (Vec4f &vec) // TIMES()
{
    return Vec4f((float)(vec.x*m[0][0] + vec.y*m[0][1] + vec.z*m[0][2] + vec.w*m[0][3]),
        (float)(vec.x*m[1][0] + vec.y*m[1][1] + vec.z*m[1][2] + vec.w*m[1][3]),
        (float)(vec.x*m[2][0] + vec.y*m[2][1] + vec.z*m[2][2] + vec.w*m[2][3]),
        (float)(vec.w*m[3][3])); // only w * M_3,3 is really needed here
}


void Mat4f::invert() // INVERT()
{
    // TODO
}

void Mat4f::setRotate() // SETROTATE()
{
    // TODO
}
