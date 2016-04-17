#include "Vec2f.h"
#include "math.h"
#include "xMath.h"
// 12/03/16

Vec2f::Vec2f() // CONSTRUCTOR
{
    set(0.0f, 0.0f);
}

Vec2f::Vec2f(float a) // CONSTRUCTOR
{
    set(a, a);
}

Vec2f::Vec2f(float x, float y) // CONSTRUCTOR
{
    set(x, y);
}

Vec2f::Vec2f(const Vec2f &vec) // CONSTRUCTOR
{
    set(vec);
}

void Vec2f::set(float x, float y) // SET();
{
    this->x = x;
    this->y = y;
}

void Vec2f::set(const Vec2f &vec) // SET();
{
    this->x = vec.x;
    this->y = vec.y;
}

float Vec2f::length() // LENGTH();
{
    float len = sqrt(((x*x) + (y*y)));
    return len;
}

/// UNTESTED ///
float Vec2f::lengthSquared() // LENGTH_SQUARED
{
	return (x*x) + (y*y);
}

void Vec2f::normalize() // NORMALIZE();
{
    float len = length();
    if (len > 0 || len == 1)
    {
        float invLen = 1 / len;
        x *= invLen;
        y *= invLen;
    }
}

Vec2f Vec2f::getNormal() // GETNORMAL();
{
    Vec2f vec;
    float len = length();
	if (len = 0)
	{
		vec.set(0.0f, 0.0f);
		return vec;
	}

    float invLen = 1 / len;
    vec.x = x * invLen;
    vec.y = y * invLen;
    return vec;
}

float Vec2f::dot(Vec2f &vec) // DOT();
{
    return ((x*vec.x) + (y*vec.y));
}

Vec2f Vec2f::operator+ (Vec2f &vec) // PLUS();
{
    return Vec2f(x + vec.x, y + vec.y);
}

Vec2f Vec2f::operator- (Vec2f &vec) // MINUS();
{
    return Vec2f(x - vec.x, y - vec.y);
}

Vec2f Vec2f::operator* (Vec2f &vec) // TIMES();
{
	return Vec2f(x * vec.x, y * vec.y);
}

void Vec2f::operator* (float scalar) // TIMES();
{
	x *= scalar;
	y *= scalar;
}

/// UNTESTED ///
Vec2f Vec2f::operator/ (Vec2f &vec) // TIMES();
{
	return Vec2f(x / vec.x, y / vec.y);
}

/// UNTESTED ///
void Vec2f::operator+= (Vec2f &vec) // PLUS();
{
	x += vec.x;
	y += vec.y;
}

/// UNTESTED ///
void Vec2f::operator-= (Vec2f &vec) // MINUS();
{
	x -= vec.x;
	y -= vec.y;
}

/// UNTESTED ///
void Vec2f::operator*= (Vec2f &vec) // TIMES();
{
	x *= vec.x;
	y *= vec.y;
}

/// UNTESTED ///
void Vec2f::operator/= (Vec2f &vec) // TIMES();
{
	x /= vec.x;
	y /= vec.y;
}

void Vec2f::operator= (Vec2f &vec) // ASSIGNMENT;
{
    this->x = vec.x;
    this->y = vec.y;
}

bool Vec2f::operator== (Vec2f &vec) // EQUALS();
{
	if (x == vec.x && y == vec.y)
		return true;
	else return false;
}

bool Vec2f::operator!= (Vec2f &vec) // NOT_EQUALS();
{
	if (x != vec.x || y != vec.y)
		return true;
	else return false;
}

/// UNTESTED ///
void Vec2f::rotate (float deg) // COMPLEX_ROTATION;
{
	// getting the unit vector out of the angle
	float q = xMath::cos_m(deg); // the x of the angle
    float r = xMath::sin_m(deg); // the y of the angle
	// could have assigned the calculation straight to x and y 
	// but x is going to change before y is assigned
	// so I used temp variables to hold the value and then assign them to x and y
	// it can get rid of temp u here, but I choose to leave it for legibility
    float t = (x * q) - (y * r);
    float u = (x * r) + (y * q);
    x = t;
    y = u;
}

/// UNTESTED ///
void Vec2f::rotate (Vec2f &vec) // COMPLEX_ROTATION;
{
    float t = (x * vec.x) - (y * vec.y);
    float u = (x * vec.y) + (y * vec.x);
    x = t;
    y = u;
}


