#include "xMath.h"
#include "math.h" /// REMOVABLE ///
#include <fstream>
using namespace std;
// I'm always concious of calling member funtions too much.
// I'm always pre-optimizing. Don't know why. 
// I know this will lead to much largeer code footprint and that it might not make much difference
// But if another code were to be calling this functions, it might lead to extensive nested function calls.

const int xMath::DEGREE_LOOKUP_TABLE[91] =
{
	64000, 63990, 63961, 63912, 63844, 63756,
	63649, 63523, 63377, 63212, 63028, 62824,
	62601, 62360, 62099, 61819, 61521, 61204,
	60868, 60513, 60140, 59749, 59340, 58912,
	58467, 58004, 57523, 57024, 56509, 55976,
	55426, 54859, 54275, 53675, 53058, 52426,
	51777, 51113, 50433, 49737, 49027, 48301,
	47561, 46807, 46038, 45255, 44458, 43648,
	42824, 41988, 41138, 40277, 39402, 38516,
	37618, 36709, 35788, 34857, 33915, 32962,
	32000, 31028, 30046, 29055, 28056, 27048,
	26031, 25007, 23975, 22936, 21889, 20836,
	19777, 18712, 17641, 16564, 15483, 14397,
	13306, 12212, 11113, 10012, 8907, 7800,
	6690, 5578, 4464, 3350, 2234, 1117,
	0,
};

float xMath::COS_TABLE[902];
float xMath::COS_TABLE2[9002];
float xMath::ACOS_TABLE[1002];
float xMath::ACOS_TABLE2[10002];

const float xMath::PI = 3.1415927f;
const float xMath::DEG_TO_RAD = PI / 180;
const float xMath::RAD_TO_DEG = 180 / PI;

const int xMath::SIN_BITS = 14; // 14KB. Adjust for accuracy.
const int xMath::SIN_MASK = ~(-1 << SIN_BITS);
const int xMath::SIN_COUNT = SIN_MASK + 1;
const float xMath::radFull = PI * 2;
const float xMath::degFull = 360;
const float xMath::radToIndex = SIN_COUNT / radFull;
const float xMath::degToIndex = SIN_COUNT / degFull;
float xMath::SINE_TAB[SIN_COUNT];

float xMath::rad; 
float xMath::radTo2;

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


/// UNTESTED ///
// For managed languages, it is advisable to inline the algo instead of returning a Vec2f on every call
// In a critical performance application
float xMath::lerp(float a, float b, float t)  /// PINNED! ///
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
Vec2f xMath::lerp(Vec2f posA, Vec2f posB, float t) /// PINNED! ///
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
Vec2f xMath::bezier3(Vec2f posA, Vec2f posB, Vec2f posC, float t) /// PINNED! ///
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
Vec2f xMath::bezier4(Vec2f posA, Vec2f posB, Vec2f posC, Vec2f posD, float t) /// PINNED! ///
{
	if (t >= 0)
	{
		return Vec2f(bezier3(lerp(posA, posB, t), lerp(posB, posC, t), lerp(posC, posD, t), t));
	}
	else
		return Vec2f(0, 0);
	
}


bool xMath::intersect(Vec2f posA, Vec2f posB, Vec2f posC, Vec2f posD)  /// PINNED! ///
{
	return true; /// TODO ///
}


void xMath::initSinTable()
{

	for (int i = 0; i < SIN_COUNT; i++)
		SINE_TAB[i] = sinf((i + 0.5f) / SIN_COUNT * radFull);

	for (int i = 0; i < 360; i += 90)
		SINE_TAB[(int)(i * degToIndex) & SIN_MASK] = (float)sinf(i * DEG_TO_RAD);
}


float xMath::sin_s(float deg)
{
	rad = deg * DEG_TO_RAD;
	return SINE_TAB[(int)(rad * radToIndex) & SIN_MASK];
}


// I got these implementations today (01/04/16) from SO. Written by a Jeremy Trifilo
// They are the fastest implementation I've seen so far, but they are only  accurate 
// from 0 to PI/2.
// The coolest thing, though, is that it works directly with degrees, so mno more
// conversion.
// I don't understand how it works, and I really wish I had a similar implementation
// for arcsine or arccos
// The benchmark he posted was 
// With these trig function implementations I may worry less about several cos/sin 
// calls or even decide not to use the my implemented complex rotation cos it 
// requires more multiplications than this one.
// (02/04/16) Now I understand how he did it and I'm trying to make it better.
float xMath::sin_j(float deg)
{
	int deg_c = 90 - (int)deg;
	float vZ = DEGREE_LOOKUP_TABLE[deg_c] * 0.000015625f;
	return vZ + ((DEGREE_LOOKUP_TABLE[deg_c - 1] * 0.000015625f) - vZ) * (deg - ((int)deg));
}

float xMath::cos_j(float deg)
{
	int deg_c = (int)deg;
	float vX = DEGREE_LOOKUP_TABLE[deg_c] * 0.000015625f;
	return vX + ((DEGREE_LOOKUP_TABLE[deg_c + 1] * 0.000015625f) - vX) * (deg - deg_c);
	
	/*int deg_i = (int)deg;
	float module = deg - deg_i;
	double vX = DEGREE_LOOKUP_TABLE[deg_i] * 0.000015625;
	double mX = DEGREE_LOOKUP_TABLE[deg_i + 1] * 0.000015625;
	float vectorX = vX + (mX - vX) * module;
	return vectorX;*/
}



float xMath::sin_c(float deg) // Chebyshev
{
	rad = deg * DEG_TO_RAD;
	radTo2 = rad * rad;
	// return rad * (1 - radTo2 *(0.1666666666 - radTo2 * (0.0083333333 - radTo2 *(0.0001984127 - 0.0000027557 * radTo2))));
	return rad  *(0.9999966 - radTo2 * (0.16664824 - radTo2 *(0.00830629 - 0.00018363 * radTo2))); // 4 terms // Chebyshev // Good Up To 90 deg
}

float xMath::cos_c(float deg) // Chebyshev
{
	rad = (90 - deg) * DEG_TO_RAD;
	radTo2 = rad * rad;
	return rad  *(0.9999966 - radTo2 * (0.16664824 - radTo2 *(0.00830629 - 0.00018363 * radTo2))); // 4 terms // Chebyshev // Good Up To 90 deg
	// return 1 - radTo2 * (0.5 - radTo2 * (0.0416666666 - radTo2 * (0.0013888888 - radTo2 * 0.0000248016)));
}



/*--------------------------------------------------------------*/


// 03/04/16
// Yes! I was able to create a table with better accuracy than 
// the original implementation
float xMath::cos_m(float deg)
{
	int quadrant = (int)((0.0111111f) * deg);
	if (quadrant == 0)
	{
		float deg10 = deg * 10.0f;
		int degInt = (int)deg10;
		float a = COS_TABLE[degInt];
		return  a + (COS_TABLE[degInt + 1] - a) * (deg10 - degInt);
	}
	else if (quadrant == 1)
	{
		float deg10 = (180.0f - deg) * 10.0f;
		int degInt = (int)deg10;
		float a = COS_TABLE[degInt];
		return  -1 * (a + (COS_TABLE[degInt + 1] - a) * (deg10 - degInt));
	}
	else if (quadrant == 2)
	{
		float deg10 = (deg - 180.0f) * 10.0f;
		int degInt = (int)deg10;
		float a = COS_TABLE[degInt];
		return  -1 * (a + (COS_TABLE[degInt + 1] - a) * (deg10 - degInt));
	}
	else if (quadrant == 3)
	{
		float deg10 = (360.0f - deg) * 10.0f;
		int degInt = (int)deg10;
		float a = COS_TABLE[degInt];
		return  a + (COS_TABLE[degInt + 1] - a) * (deg10 - degInt);
	}
	return 0.0f;
}

// accuracy is nearly similar to the 9001-table implememtation for floats
float xMath::cos_m2(float deg)
{
	int quadrant = (int)((0.0111111f) * deg);
	if (quadrant == 0)
	{
		float deg100 = deg * 100.0f;
		int degInt = (int)deg100;
		float a = COS_TABLE2[degInt];
		return  a + (COS_TABLE2[degInt + 1] - a) * (deg100 - degInt);
	}
	else if (quadrant == 1)
	{
		float deg100 = (180.0f - deg) * 100.0f;
		int degInt = (int)deg100;
		float a = COS_TABLE2[degInt];
		return  -1 * (a + (COS_TABLE2[degInt + 1] - a) * (deg100 - degInt));
	}
	else if (quadrant == 2)
	{
		float deg100 = (deg - 180.0f) * 100.0f;
		int degInt = (int)deg100;
		float a = COS_TABLE2[degInt];
		return  -1 * (a + (COS_TABLE2[degInt + 1] - a) * (deg100 - degInt));
	}
	else if (quadrant == 3)
	{
		float deg100 = (360.0f - deg) * 100.0f;
		int degInt = (int)deg100;
		float a = COS_TABLE2[degInt];
		return  a + (COS_TABLE2[degInt + 1] - a) * (deg100 - degInt);
	}
	return 0.0f;
}


float xMath::sin_m(float deg) 
{
	int quadrant = (int)((0.0111111f) * deg);
	if (quadrant == 0)
	{
		float deg10 = (90.0f - deg) * 10.0f;
		int degInt = (int)deg10;
		float a = COS_TABLE[degInt];
		return  a + (COS_TABLE[degInt + 1] - a) * (deg10 - degInt);
	}
	else if (quadrant == 1)
	{
		float deg10 = (deg - 90.0f) * 10.0f;
		int degInt = (int)deg10;
		float a = COS_TABLE[degInt];
		return a + (COS_TABLE[degInt + 1] - a) * (deg10 - degInt);
	}
	else if (quadrant == 2)
	{
		float deg10 = (270.0f - deg) * 10.0f;
		int degInt = (int)deg10;
		float a = COS_TABLE[degInt];
		return -1 * (a + (COS_TABLE[degInt + 1] - a) * (deg10 - degInt));
	}
	else if (quadrant == 3)
	{
		float deg10 = (deg - 270.0f) * 10.0f;
		int degInt = (int)deg10;
		float a = COS_TABLE[degInt];
		return -1 * (a + (COS_TABLE[degInt + 1] - a) * (deg10 - degInt));
	}
	return 0.0f;
}


float xMath::sin_m2(float deg)
{
	int quadrant = (int)((0.0111111f) * deg);
	if (quadrant == 0)
	{
		float deg100 = (90.0f - deg) * 100.0f;
		int degInt = (int)deg100;
		float a = COS_TABLE2[degInt];
		return  a + (COS_TABLE2[degInt + 1] - a) * (deg100 - degInt);
	}
	else if (quadrant == 1)
	{
		float deg100 = (deg - 90.0f) * 100.0f;
		int degInt = (int)deg100;
		float a = COS_TABLE2[degInt];
		return  a + (COS_TABLE2[degInt + 1] - a) * (deg100 - degInt);
	}
	else if (quadrant == 2)
	{
		float deg100 = (270.0f - deg) * 100.0f;
		int degInt = (int)deg100;
		float a = COS_TABLE2[degInt];
		return  -1 * (a + (COS_TABLE2[degInt + 1] - a) * (deg100 - degInt));
	}
	else if (quadrant == 3)
	{
		float deg100 = (deg - 270.0f) * 100.0f;
		int degInt = (int)deg100;
		float a = COS_TABLE2[degInt];
		return  -1 * (a + (COS_TABLE2[degInt + 1] - a) * (deg100 - degInt));
	}
	return 0.0f;
}

void xMath::initCosTable()
{
	// (03/04/16) For some crazy unidentified reason, the accuracy 
	// of this implementation goes haywire if I change this var to float.
	double b = 0.0;
	double DEG_TO_RAD = 3.14159265359 / 180;
	double rad;

	for (int a = 0; a < 900; a++, b += 0.1)
	{
		rad = b * DEG_TO_RAD;
		COS_TABLE[a] = cosf(rad);
	}

	// The last two indexes are set to 0
	COS_TABLE[900] = 0.0f;
	COS_TABLE[901] = 0.0f;
}


void xMath::initCosTable2()
{
	// (03/04/16) For some crazy unidentified reason, the accuracy 
	// of this implementation goes haywire if I change this var to float.
	double b = 0.0;
	double DEG_TO_RAD = 3.14159265359 / 180;
	double rad;

	for (int a = 0; a < 9000; a++, b += 0.01)
	{
		rad = b * DEG_TO_RAD;
		COS_TABLE2[a] = cosf(rad);
	}

	// The last two indexes are set to 0
	COS_TABLE2[9000] = 0.0f;
	COS_TABLE2[9001] = 0.0f;
}


void xMath::printCosTableToFile()
{
	ofstream writer;
	ofstream tableLog;
	writer.open("COS_TABLE.txt");
	tableLog.open("COS_TABLE_LOG.txt");

	float b = 0.0;

	for (int a = 0; a < 900; a++, b += 0.1)
	{
		writer << COS_TABLE[a] << "\n";
		tableLog << a << ": " << b << ": " << COS_TABLE[a] << "\n";
	}

	writer << 0.0f << "\n" << 0.0f;
	tableLog << "900: " << 90.0f << ": " << 0.0f << "\n"
		<< "901: " << 90.0f << ": " << 0.0f;

	writer.close();
	tableLog.close();
}

void xMath::printCosTable2ToFile()
{
	ofstream writer;
	ofstream tableLog;
	writer.open("COS_TABLE2.txt");
	tableLog.open("COS_TABLE_LOG2.txt");

	float b = 0.0;

	for (int a = 0; a < 9000; a++, b += 0.01)
	{
		writer << COS_TABLE2[a] << "\n";
		tableLog << a << ": " << b << ": " << COS_TABLE2[a] << "\n";
	}

	writer << 0.0f << "\n" << 0.0f;
	tableLog << "9000: " << 90.0f << ": " << 0.0f << "\n"
		<< "9001: " << 90.0f << ": " << 0.0f;

	writer.close();
	tableLog.close();
}


/*------------------------------------------------------*/

float xMath::acos_m(float cosX)  /// PINNED! ///
{
	float cosX1000 = cosX * 1000;
	int cosXInt = (int)cosX1000;
	float a = ACOS_TABLE[cosXInt];
	return  a + (ACOS_TABLE[cosXInt + 1] - a) * (cosX1000 - cosXInt);
}

float xMath::acos_m2(float cosX)
{
	float cosX10000 = cosX * 10000;
	int cosXInt = (int)cosX10000;
	float a = ACOS_TABLE2[cosXInt];
	return  a + (ACOS_TABLE2[cosXInt + 1] - a) * (cosX10000 - cosXInt);
}

float xMath::asin_m(float cosX) /// PINNED! ///
{
	float cosX1000 = cosX * 1000;
	int cosXInt = (int)cosX1000;
	float a = ACOS_TABLE[cosXInt];
	return 90 - (a + (ACOS_TABLE[cosXInt + 1] - a) * (cosX1000 - cosXInt));
}

float xMath::asin_m2(float cosX)
{
	float cosX10000 = cosX * 10000;
	int cosXInt = (int)cosX10000;
	float a = ACOS_TABLE2[cosXInt];
	return 90 - (a + (ACOS_TABLE2[cosXInt + 1] - a) * (cosX10000 - cosXInt));
}

void xMath::initAcosTable() /// PINNED! ///
{
	// (03/04/16) For some crazy unidentified reason, the accuracy 
	// of this implementation goes haywire if I change this var to float.
	double b = 0.0;
	double RAD_TO_DEG = 180 / 3.14159265359;

	for (int a = 0; a < 1000; a++, b += 0.001)
	{
		ACOS_TABLE[a] = acosf(b) * RAD_TO_DEG;
	}

	// The last two indexes are set to 1
	ACOS_TABLE[1000] = 0.0f;
	ACOS_TABLE[1001] = 0.0f;
}

void xMath::initAcosTable2()
{
	// (03/04/16) For some crazy unidentified reason, the accuracy 
	// of this implementation goes haywire if I change this var to float.
	double b = 0.0;
	double RAD_TO_DEG = 180 / 3.14159265359;

	for (int a = 0; a < 10000; a++, b += 0.0001)
	{
		ACOS_TABLE2[a] = acosf(b) * RAD_TO_DEG;
	}

	// The last two indexes are set to 1
	ACOS_TABLE2[10000] = 0.0f;
	ACOS_TABLE2[10001] = 0.0f;
}

void xMath::printAcosTableToFile()
{
	ofstream writer;
	ofstream tableLog;
	writer.open("ACOS_TABLE.txt");
	tableLog.open("ACOS_TABLE_LOG.txt");

	float b = 0.0;

	for (int a = 0; a < 1000; a++, b += 0.001)
	{
		writer << ACOS_TABLE[a] << "\n";
		tableLog << a << ": " << b << ": " << ACOS_TABLE[a] << "\n";
	}

	writer << 0.0f << "\n" << 0.0f;
	tableLog << "1000 :  " << 1.0f << ": " << 0.0f << "\n"
		<< "1001: " << 1.0f << ": " << 0.0f;

	writer.close();
	tableLog.close();
}

void xMath::printAcosTable2ToFile()
{
	ofstream writer;
	ofstream tableLog;
	writer.open("ACOS_TABLE2.txt");
	tableLog.open("ACOS_TABLE_LOG2.txt");

	float b = 0.0;

	for (int a = 0; a < 10000; a++, b += 0.0001)
	{
		writer << ACOS_TABLE2[a] << "\n";
		tableLog << a << ": " << b << ": " << ACOS_TABLE2[a] << "\n";
	}

	writer << 0.0f << "\n" << 0.0f;
	tableLog << "10000 :  " << 1.0f << ": " << 0.0f << "\n"
		<< "10001: " << 1.0f << ": " << 0.0f;

	writer.close();
	tableLog.close();
}

