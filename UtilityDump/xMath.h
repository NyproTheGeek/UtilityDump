#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "Vec2f.h"
#include "cstdint"

#ifdef COMPILE_MYLIBRARY   
#define MYLIBRARY_EXPORT __declspec(dllexport) 
#else   
#define MYLIBRARY_EXPORT __declspec(dllimport) 
#endif

// 13/03/16

class xMath
{
	

public:
	static const float PI;
	static const float DEG_TO_RAD;
	static const float RAD_TO_DEG;

	static const int DEGREE_LOOKUP_TABLE[];

	static float COS_TABLE[];
	static float COS_TABLE2[];
	static float ACOS_TABLE[];
	static float ACOS_TABLE2[];

	static float rad;
	static float radTo2;
	static const int SIN_BITS; /// REMOVABLE /// // 16KB. Adjust for accuracy. 
	static const int SIN_MASK; /// REMOVABLE ///
	static const int SIN_COUNT; /// REMOVABLE ///
	static const float radFull; /// REMOVABLE ///
	static const float degFull; /// REMOVABLE ///
	static const float radToIndex; /// REMOVABLE ///
	static const float degToIndex; /// REMOVABLE ///
	static float SINE_TAB[]; /// REMOVABLE ///


	static float degToRad(float deg);

	static float radToDeg(float rad);

	static Vec2f degToVec(float deg); // degrees represent 2 dimensions

	static Vec2f radToVec(float rad);
		
	static float vecToDeg(Vec2f vec);

	static float vecToRad(Vec2f vec);

	static float lerp(float pointA, float pointB, float trace);

	static Vec2f lerp(Vec2f posA, Vec2f pointB, float trace);

	static Vec2f bezier3(Vec2f posA, Vec2f posB, Vec2f posC, float t);

	static Vec2f bezier4(Vec2f posA, Vec2f posB, Vec2f posC, Vec2f posD, float t);

	static bool intersect(Vec2f posA, Vec2f posB, Vec2f posC, Vec2f posD);

	static void initSinTable(); /// REMOVABLE ///

	static float sin_s(float deg);

	static float sin_c(float deg);

	static float cos_c(float deg);

	static float sin_j(float deg);

	static float cos_j(float deg);

	static float cos_m(float cosX);

	static float cos_m2(float cosX);

	static float sin_m(float cosX);

	static float sin_m2(float cosX);

	static void initCosTable();

	static void initCosTable2();

	static void printCosTableToFile();

	static void printCosTable2ToFile();

	static float acos_m(float cosX); 

	static float acos_m2(float cosX);

	static float asin_m(float cosX);

	static float asin_m2(float cosX);

	static void initAcosTable();

	static void initAcosTable2();

	static void printAcosTableToFile();

	static void printAcosTable2ToFile();

	//static float cos(float deg);

	//static float asin(float deg);

	//static float acos(float deg);
};

#endif // CONSTANTS_H
