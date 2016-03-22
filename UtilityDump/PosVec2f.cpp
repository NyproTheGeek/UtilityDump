#include "PosVec2f.h"
#include "math.h"
#include "xMath.h"

/// UNTESTED ///
PosVec2f::PosVec2f() // CONSTRUCTOR
{
	float a_x = 0.0f;
	float a_y = 0.0f;
	float b_x = 0.0f;
	float b_y = 0.0f;
	vector.set(0.0f, 0.0f);
}

/// UNTESTED ///
PosVec2f::PosVec2f(Vec2f positionA, Vec2f positionB) // CONSTRUCTOR
{
	set(positionA, positionB);
}

/// UNTESTED ///
PosVec2f::PosVec2f(float a, float b) // CONSTRUCTOR
{
	set(a, b);
}

/// UNTESTED ///
PosVec2f::PosVec2f(float a_x, float a_y, float b_x, float b_y) // CONSTRUCTOR
{
	set(a_x, a_y, b_x, b_y);
}

/// UNTESTED ///
PosVec2f::PosVec2f(const PosVec2f &posVec) // CONSTRUCTOR
{
	set(posVec);
}






/// UNTESTED ///
void PosVec2f::set(Vec2f positionA, Vec2f positionB) // SET
{
	this->a_x = positionA.x;
	this->a_y = positionA.y;
	this->b_x = positionB.x;
	this->b_y = positionB.y;
	setVector();
}

/// UNTESTED ///
void PosVec2f::set(float a, float b) // SET
{
	this->a_x = a;
	this->a_y = a;
	this->b_x = b;
	this->b_y = b;
	setVector();
}

/// UNTESTED ///
void PosVec2f::set(float a_x, float a_y, float b_x, float b_y) // SET
{
	this->a_x = a_x;
	this->a_y = a_y;
	this->b_x = b_x;
	this->b_y = b_y;
	setVector();
}

/// UNTESTED ///
void PosVec2f::set(const PosVec2f &posVec) // SET
{
	this->a_x = posVec.a_x;
	this->a_y = posVec.a_x;
	this->b_x = posVec.b_x;
	this->b_y = posVec.b_y;
	setVector();
}

/// UNTESTED ///
void PosVec2f::setA(float x, float y) // SET_A
{
	a_x = x;
	a_y = y;
	setVector();
}

/// UNTESTED ///
void PosVec2f::setA(Vec2f &vec) // SET_A
{
	a_x = vec.x;
	a_y = vec.y;
	setVector();
}

/// UNTESTED ///
void PosVec2f::setB(float x, float y) // SET_B
{
	b_x = x;
	b_y = y;
	setVector();
}

/// UNTESTED ///
void PosVec2f::setB(Vec2f &vec) // SET_B
{
	b_x = vec.x;
	b_y = vec.y;
	setVector();
}

/// UNTESTED ///
Vec2f PosVec2f::getA() // SET_A
{
	return Vec2f(a_x, a_y);
}

/// UNTESTED ///
Vec2f PosVec2f::getB() // SET_B
{
	return Vec2f(b_x, b_y);
}






/// UNTESTED ///
void PosVec2f::rotate(float deg) // Complex rotation
{
	Vec2f angleVec(xMath::degToVec(deg));
	Vec2f newVec((vector.x * angleVec.x - vector.y * angleVec.y), (vector.x * angleVec.y + vector.y * angleVec.x));
	Vec2f diffVec(newVec - vector);
	b_x += diffVec.x;
	b_y += diffVec.y;
	vector = newVec;
}

/// UNTESTED ///
void PosVec2f::rotate(Vec2f &vec) // Complex rotation
{
	Vec2f newVec((vector.x * vec.x - vector.y * vec.y), (vector.x * vec.y + vector.y * vec.x));
	Vec2f diffVec(newVec - vector);
	b_x += diffVec.x;
	b_y += diffVec.y;
	vector = newVec;
}

/// UNTESTED ///
void PosVec2f::rotate(float x, float y) // Complex rotation
{
	Vec2f newVec((vector.x * x - vector.y * y), (vector.x * y + vector.y * x));
	Vec2f diffVec(newVec - vector);
	b_x += diffVec.x;
	b_y += diffVec.y;
	vector = newVec;
}

/// UNTESTED ///
void PosVec2f::scale(Vec2f &vec) // SCALE;
{
	b_x *= vec.x;
	b_y *= vec.y;
	setVector();
}

/// UNTESTED ///
void PosVec2f::scale(float x, float y) // SCALE;
{
	b_x *= x;
	b_y *= y;
	setVector();
}



/// UNTESTED ///
void PosVec2f::translate(float x, float y) // Translated at Both. Both moves
{
	a_x += x;
	a_y += y;
	b_x += x;
	b_y += y;
}

/// UNTESTED ///
void PosVec2f::translate(Vec2f &vec) // Translated at Both. Both moves
{
	a_x += vec.x;
	a_y += vec.y;
	b_x += vec.x;
	b_y += vec.y;
}

/// UNTESTED ///
void PosVec2f::translateA(float x, float y) // Translated at A. Only A moves
{
	a_x += x;
	a_y += y;
	setVector();
}

/// UNTESTED ///
void PosVec2f::translateA(Vec2f &vec) // Translated at A. Only A moves
{
	a_x += vec.x;
	a_y += vec.y;
	setVector();
}

/// UNTESTED ///
void PosVec2f::translateB(float x, float y) // Translated at B. Only B moves
{
	b_x += x;
	b_y += y;
	setVector();
}

/// UNTESTED ///
void PosVec2f::translateB(Vec2f &vec) // Translated at B. Only B moves
{
	b_x += vec.x;
	b_y += vec.y;
	setVector();
}





/// UNTESTED ///
float PosVec2f::length() // LENGTH
{
	return vector.length();
}

/// UNTESTED ///
void PosVec2f::normalize() // NORMALIZE 
{
	vector.normalize();
	b_x *= vector.x;
	b_y *= vector.y;
}

/// UNTESTED ///
Vec2f PosVec2f::getNormal() // GET_NORMAL
{
	return vector.getNormal();
}

/// UNTESTED ///
float PosVec2f::dot(PosVec2f &posVec) // SET_B
{
	return ((vector.x * posVec.vector.x) + (vector.y * posVec.vector.y));
}

/// UNTESTED ///
float PosVec2f::angleDeg()
{
	Vec2f normVec = vector.getNormal();
	float deg = (float) acosf(normVec.x) * xMath::RAD_TO_DEG;
	return deg;
}

/// UNTESTED ///
float PosVec2f::angleRad()
{
	Vec2f normVec = vector.getNormal();
	return acosf(normVec.x);
}

/// UNTESTED ///
void PosVec2f::operator= (PosVec2f &posVec)
{
	this->a_x = posVec.a_x;
	this->a_y = posVec.a_x;
	this->b_x = posVec.b_x;
	this->b_y = posVec.b_y;
	setVector();
}

/// UNTESTED ///
bool PosVec2f::operator== (PosVec2f &posVec)
{
	if (a_x == posVec.a_x || a_y == posVec.a_y || b_x == posVec.b_x || b_y == posVec.b_y)
		return true;
	else return false;
}

/// UNTESTED ///
bool PosVec2f::operator!= (PosVec2f &posVec)
{
	if (a_x != posVec.a_x || a_y != posVec.a_y || b_x != posVec.b_x|| b_y != posVec.b_y)
		return true;
	else return false;
}

/// UNTESTED ///
void PosVec2f::setVector() // SET_VECTOR;
{
	vector.set((b_x - a_x), (b_y - a_y)); 
}
