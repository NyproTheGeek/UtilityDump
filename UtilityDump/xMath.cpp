#include "xMath.h"
#include "math.h" /// REMOVABLE ///
// I'm always concious of calling member funtions too much.
// I'm always pre-optimizing. Don't know why. 
// I know this will lead to much largeer code footprint and that it might not make much difference
// But if another code were to be calling this functions, it might lead to extensive nested function calls.

const float xMath::PI = 3.1415927f;
const float xMath::DEG_TO_RAD = PI / 180;
const float xMath::RAD_TO_DEG = 180 / PI;
float xMath::SINE_TABLE[65536]; /// REMOVABLE ///
const int xMath::SIN_BITS = 16; // 16KB. Adjust for accuracy.
const int xMath::SIN_MASK = ~(-1 << SIN_BITS);
const int xMath::SIN_COUNT = SIN_MASK + 1;
const float xMath::radFull = PI * 2;
const float xMath::degFull = 360;
const float xMath::radToIndex = SIN_COUNT / radFull;
const float xMath::degToIndex = SIN_COUNT / degFull;
float xMath::SINE_TAB[SIN_COUNT];

float xMath::rad; 
float xMath::radTo2;
float xMath::radTo3; /// REMOVABLE ///

/// UNTESTED ///
float xMath::degToRad(float deg)
{
	return (float)deg * DEG_TO_RAD;
}

/// UNTESTED ///
float xMath::radToDeg(float rad)
{
	return (float)rad * RAD_TO_DEG;
}

/// UNTESTED ///
/// degrees represent 2 dimensions, degToVec3 doesn't make much sense
Vec2f xMath::degToVec(float deg)
{
	float rad = deg * DEG_TO_RAD;
	return Vec2f(cos(rad), sin(rad));
}

/// UNTESTED ///
Vec2f xMath::radToVec(float rad)
{
	return Vec2f(cos(rad), sin(rad));
}

/// UNTESTED ///
float xMath::vecToDeg(Vec2f vec)
{
	Vec2f normVec = vec.getNormal();
	float deg = (float) acos(normVec.x) * RAD_TO_DEG;
	return deg;
}

/// UNTESTED ///
float xMath::vecToRad(Vec2f vec)
{
	Vec2f normVec = vec.getNormal();
	return acosf(normVec.x);
}

/// REDUCE MULTIPLICATIONS ///
float xMath::sin(float deg) // Approximated taylor series
{
	rad = deg * DEG_TO_RAD;
	radTo2 = rad * rad;
	// return rad - (radTo3 * 0.1666666666) + (radTo2*radTo3 * 0.0083333333) - (radTo2*radTo2*radTo3 * 0.0001984127) + (radTo3*radTo3*radTo3 * 0.0000027557);
	// return rad * (1 - radTo2 *(0.1666666666 - radTo2 * (0.0083333333 - radTo2 *(0.0001984127 - 0.0000027557 * radTo2))));
	return rad  *(0.9999966 - radTo2 * (0.16664824 - radTo2 *(0.00830629 - 0.00018363 * radTo2))); // ChebySev
	// there's no need to reset static variables rad, radTo2, radTo3 to zero
}

/// REDUCE MULTIPLICATIONS ///
float xMath::cos(float deg) // error at 1e-4 // need new better approximation algo // looking at Chebshevy
{
	rad = deg * DEG_TO_RAD;
	radTo2 = rad * rad;
	// radTo3 = rad * radTo2;
	// return 1 - (radTo2 * 0.5) + (radTo2*radTo2 * 0.0416666666) - (radTo3*radTo3 * 0.0013888888) + (radTo2*radTo3*radTo3 * 0.0000248016);
	return 1 - radTo2 * (0.5 - radTo2 * (0.0416666666 - radTo2 * (0.0013888888 - radTo2 * 0.0000248016))); 
	// there's no need to reset static variables rad, radTo2, radTo3 to zero
}

/// UNTESTED ///
// For managed languages, it is advisable to inline the algo instead of returning a Vec2f on every call
// In a critical performance application
float xMath::lerp(float a, float b, float t) 
{
	if (t >= 0)
	{
		return ((b - a)* t) + a;
	}
	else
		return 0;
}

/// UNTESTED ///
// For managed languages, it is advisable to inline the algo instead of returning a Vec2f on every call
// In a performance critical application
Vec2f xMath::lerp(Vec2f posA, Vec2f posB, float t)
{
	if (t >= 0)
	{
		return Vec2f((posB.x - posA.x)* t + posA.x,
			(posB.y - posA.y)* t + posA.y);
	}
	else
		return Vec2f(0, 0);
}

/// UNTESTED ///
// For managed languages, it is advisable to inline the algo instead of returning a Vec2f on every call
// In a performance critical application
Vec2f xMath::bezier3(Vec2f posA, Vec2f posB, Vec2f posC, float t)
{
	if (t >= 0)
	{
		return Vec2f((1-t) * ((1-t) * posA.x + posB.x * t) + t * ((1-t) * posB.x + posC.x * t),
			(1 - t) * ((1 - t) * posA.y + posB.y * t) + t * ((1 - t) * posB.y + posC.y * t));
		// return Vec2f(lerp(posA, posB, t), lerp(posB, posC, t));
	}
	else
		return Vec2f(0, 0);
}

/// UNTESTED ///
// For managed languages, it is advisable to inline the algo instead of returning a Vec2f on every call
// In a performance critical application
Vec2f xMath::bezier4(Vec2f posA, Vec2f posB, Vec2f posC, Vec2f posD, float t)
{
	if (t >= 0)
	{
		return Vec2f(bezier3(lerp(posA, posB, t), lerp(posB, posC, t), lerp(posC, posD, t), t));
	}
	else
		return Vec2f(0, 0);
	
}

/// REMOVABLE ///
void xMath::initSinTable()
{
	// For the first the sine table
	for (int i = 0; i < 65536; ++i) {
		SINE_TABLE[i] = sinf(i * PI * 2 / 65536);
	}

	// For the second the sine table
	for (int i = 0; i < SIN_COUNT; i++)
		SINE_TAB[i] = (float)sinf((i + 0.5f) / SIN_COUNT * radFull);

	for (int i = 0; i < 360; i += 90)
		SINE_TAB[(int)(i * degToIndex) & SIN_MASK] = (float)sinf(i * DEG_TO_RAD);
}

/// REMOVABLE ///
float xMath::_sin(float deg)
{
	rad = deg * DEG_TO_RAD;
	return SINE_TABLE[(int)(rad * 10430.378) & 65535];
}

/// REMOVABLE ///
float xMath::__sin(float deg)
{
	rad = deg * DEG_TO_RAD;
	return SINE_TAB[(int)(rad * radToIndex) & SIN_MASK];
}


