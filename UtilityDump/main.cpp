#include <iostream>
#include "Vec2f.h"
#include "math.h"
#include "xMath.h"
#include <fstream>


using namespace std;

float COS_TABLE[9001];
float cos_e(float);



int main()
{
	xMath::initSinTable();
	xMath::initCosTable();
    Vec2f vec1(1, 0);
    Vec2f vec2(0, 1);
    Vec2f vec3(2, 0);
	Vec2f vec4(0.707107, 0.707107);
	vec3.rotate(vec4);
    vec1.rotate(45);

    cout << "vec1(x): " << vec1.x << " | vec1(y): " << vec1.y << " | vec1(Length): " << vec1.length() << endl;

	cout << "vec3(x): " << vec3.x << " | vec3(y): " << vec3.y << " | vec3(Length): " << vec3.length() << endl;
	
	/*----------------------------------------------------*/


	cout
		<< xMath::SIN_COUNT << endl;


	for (float deg = 0; deg <= 400; deg += 5.11)
	{
		cout
			<< "(" << deg << ") "
			<< "sinf: " << sinf(deg * xMath::DEG_TO_RAD)
			<< " | sin_m: " << xMath::sin_m(deg)
			<< " | sin_s: " << xMath::sin_s(deg)
			<< " | sin_c: " << xMath::sin_c(deg) << endl;
	}

	cout << "\n\n\n\n" << endl;
 	

	/*----------------------------------------------------*/

	//ofstream myfile;
	//myfile.open("COS TABLE.txt");

	//float b = .0f;
	//for (int a = 0; a < 9001; a++, b += .01f)
	//{
	//	COS_TABLE[a] = cosf(b * xMath::DEG_TO_RAD);
	//	myfile << COS_TABLE[a] << ",\n";
	//}
	//myfile.close();

	system("PAUSE");
    return 0;
}


//float cos_e(float deg)
//{
//	if (deg == 90)
//	{
//		return 0;
//	}
//	float deg100 = deg * 100.0f;
//	int degInt = (int)deg100;
//	double a = COS_TABLE[degInt];
//	return (float)a + (COS_TABLE[degInt + 1] - a) * (deg100 - degInt);
//}


