#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "Vec2f.h"
// 13/03/16

class xMath
{
public:
	static const double PI;
	static const double DEG_TO_RAD;
	static const double RAD_TO_DEG;
	static float rad;
	static float radTo2;
	static float radTo3;

	static float degToRad(float deg);

	static float radToDeg(float rad);

	static Vec2f degToVec(float deg); // degrees represent 2 dimensions

	static Vec2f radToVec(float rad);
		
	static float vecToDeg(Vec2f vec);

	static float vecToRad(Vec2f vec);

	static float sin(float deg); 

	static float cos(float deg);
	
};


#endif // CONSTANTS_H
