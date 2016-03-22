#include "Vec4f.h"
#include "math.h"
// 13/03/16
Vec4f::Vec4f () // CONSTRUCTOR
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 1.0f;
}

Vec4f::Vec4f (float a) // CONSTRUCTOR
{
    x = a;
    y = a;
    z = a;
    w = 1.0f;
}


Vec4f::Vec4f (float x, float y, float z, float w) // CONSTRUCTOR
{
    set(x, y, z, w);
}

Vec4f::Vec4f (const Vec4f &vec) // CONSTRUCTOR
{
    set(vec);
}


void Vec4f::set(float x, float y, float z, float w) // SET();
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

void Vec4f::set(Vec4f vec) // SET();
{
    this->x = vec.x;
    this->y = vec.y;
    this->z = vec.z;
    this->w = vec.w;
}


float Vec4f::length() // LENGTH();
{
    float len = sqrt(((x*x) + (y*y) + (z*z)));
    return len;
}

/// UNTESTED ///
float Vec4f::lengthSquared() // LENGTH_SQUARED
{
	return (x*x) + (y*y) + (z*z);
}


void Vec4f::normalize() // NORMALIZE();
{
    float len = length();
    if (len > 0 || len == 1)
    {
        float invLen = 1 / len;
        x *= invLen;
        y *= invLen;
        z *= invLen;
    }
}

Vec4f Vec4f::getNormal() // GETNORMAL();
{
    Vec4f vec;
    float len = length();
	if (len == 0)
	{
		vec.set(0.0f, 0.0f, 0.0f, 0.0f);
		return vec;
	}

    float invLen = 1 / len;
    vec.x = x * invLen;
    vec.y = y * invLen;
    vec.z = z * invLen;
    return vec;
}


float Vec4f::dot(Vec4f &vec) // DOT();
{
    return ((x*vec.x) + (y*vec.y) + (z*vec.z));
}


Vec4f Vec4f::cross(Vec4f &vec) // CROSS();
{
    return Vec4f(
        (y * vec.x) - (z * vec.y),
        (z * vec.y) - (x * vec.z),
        (x * vec.z) - (y * vec.x),
        0.0f); // note new w is 0.0 bcos most ops are vec * vec = vec (DIRECTION!)
}

Vec4f Vec4f::operator+ (Vec4f &vec) // PLUS();
{
    return Vec4f(x + vec.x, y + vec.y, z + vec.z, w); /* note w remains the same */
}

Vec4f Vec4f::operator- (Vec4f &vec) // MINUS();
{
    return Vec4f(x - vec.x, y - vec.y, z - vec.z, w); /* note w remains the same */
}

Vec4f Vec4f::operator* (Vec4f &vec) // TIMES();
{
	return Vec4f(x * vec.x, y * vec.y, z * vec.z, w); /* note w remains the same */
}

void Vec4f::operator* (float scalar) // TIMES();
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
}

/// UNTESTED ///
Vec4f Vec4f::operator/ (Vec4f &vec)
{
	return Vec4f(x / vec.x, y / vec.y, z / vec.z, w); /* note w remains the same */
}

/// UNTESTED ///
void Vec4f::operator+= (Vec4f &vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
}

/// UNTESTED ///
void Vec4f::operator-= (Vec4f &vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
}

/// UNTESTED ///
void Vec4f::operator*= (Vec4f &vec)
{
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
}

/// UNTESTED ///
void Vec4f::operator/= (Vec4f &vec)
{
	x /= vec.x;
	y /= vec.y;
	z /= vec.z;
}

void Vec4f::operator= (Vec4f vec) // ASSIGNMENT;
{
    this->x = vec.x;
    this->y = vec.y;
    this->z = vec.z;
    this->w = vec.w;
}

bool Vec4f::operator== (Vec4f &vec) // EQUALS();
{
	if (x == vec.x && y == vec.y && z == vec.z && w == vec.w)
		return true;
	else return false;
}

bool Vec4f::operator!= (Vec4f &vec) // EQUALS();
{
	if (x != vec.x || y != vec.y || z != vec.z || w != vec.w)
		return true;
	else return false;
}
