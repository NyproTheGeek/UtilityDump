#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "Vec2f.h"
// 13/03/16

class xMath
{
private:
	static float rad;
	static float radTo2;
	static float SINE_TABLE[];

public:
	static const float PI;
	static const float DEG_TO_RAD;
	static const float RAD_TO_DEG;

	static float degToRad(float deg);

	static float radToDeg(float rad);

	static Vec2f degToVec(float deg); // degrees represent 2 dimensions

	static Vec2f radToVec(float rad);
		
	static float vecToDeg(Vec2f vec);

	static float vecToRad(Vec2f vec);

	static float sin(float deg); 

	static float cos(float deg);

	static float lerp(float pointA, float pointB, float trace);

	static Vec2f lerp(Vec2f posA, Vec2f pointB, float trace);

	static Vec2f bezier3(Vec2f posA, Vec2f posB, Vec2f posC, float t);

	static Vec2f bezier4(Vec2f posA, Vec2f posB, Vec2f posC, Vec2f posD, float t);

	static void initSinTable();

	static float _sin(float deg);

	//static float cos(float deg);

	//static float asin(float deg);

	//static float acos(float deg);
};

#endif // CONSTANTS_H
