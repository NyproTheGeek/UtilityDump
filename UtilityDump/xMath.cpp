#include "xMath.h"
#include "math.h"
// I'm always concious of calling member funtions too much.
// I'm always pre-optimizing. Don't know why. 
// I know this will lead to much largeer code footprint and that it might not make much difference
// But if another code were to be calling this functions, it might lead to extensive nested function calls.

const double xMath::PI = 3.141592653589793238463;
const double xMath::DEG_TO_RAD = PI / 180;
const double xMath::RAD_TO_DEG = 180 / PI;
float xMath::rad;
float xMath::radTo2;
float xMath::radTo3;


float xMath::degToRad(float deg) /// DEG_TO_RAD
{
	return (float)deg * DEG_TO_RAD;
}


float xMath::radToDeg(float rad) /// RAD_TO_DEG
{
	return (float)rad * RAD_TO_DEG;
}


Vec2f xMath::degToVec(float deg) /// DEG_TO_VEC /// degrees represent 2 dimensions, degToVec3 doesn't make much sense
{
	float rad = deg * DEG_TO_RAD;
	return Vec2f(cos(rad), sin(rad));
}

Vec2f xMath::radToVec(float rad) /// RAD_TO_VEC
{
	return Vec2f(cos(rad), sin(rad));
}

float xMath::vecToDeg(Vec2f vec) /// VEC_TO_DEG
{
	Vec2f normVec = vec.getNormal();
	float deg = (float) acos(normVec.x) * RAD_TO_DEG;
	return deg;
}

float xMath::vecToRad(Vec2f vec) /// VEC_TO_RAD
{
	Vec2f normVec = vec.getNormal();
	return acosf(normVec.x);
}

float xMath::sin(float deg) // Approximated taylor series
{
	rad = deg * DEG_TO_RAD;
	radTo2 = rad * rad;
	radTo3 = radTo2 * rad;
	return rad - (radTo3 * 0.1666666666) + (radTo2*radTo3 * 0.0083333333) - (radTo2*radTo2*radTo3 * 0.0001984127) + (radTo3*radTo3*radTo3 * 0.0000027557);
	// there's no need to reset static variables rad, radTo2, radTo3 to zero
}

float xMath::cos(float deg) // error at 1e-4 // need new better approximation algo // looking at Chebshevy
{
	rad = deg * DEG_TO_RAD;
	radTo2 = rad * rad;
	radTo3 = radTo2 * rad;
	return 1 - (radTo2 * 0.5) + (radTo2*radTo2 * 0.0416666666) - (radTo3*radTo3 * 0.0013888888) + (radTo2*radTo3*radTo3 * 0.0000248016);
	// there's no need to reset static variables rad, radTo2, radTo3 to zero
}



