#include <iostream>
#include "Vec2f.h"
#include "math.h"
#include "xMath.h"

using namespace std;


int main()
{
    Vec2f vec1(1, 0);
    Vec2f vec2(0, 1);
    Vec2f vec3(1, -1);
    vec1.rotate(45); // PRECISION ERROR STILL PRESENT BUT SLIGHTLY RESOLVED

    cout << "vec1(x): " << vec1.x << " | vec1(y): " << vec1.y << " | vec1(Length): " << vec1.length() << endl;

	cout << "vec3(x): " << vec3.x << " | vec3(y): " << vec3.y << " | vec3(Length): " << vec3.length() << endl;
	

	//for (float i = 0; i <= 90; i += 5.478456f)
	//{
	//	cout << "sin(" << i << "): " << sinf(i * xMath::DEG_TO_RAD) << " | xMath::sin(" << i << "): " << xMath::sin(i) << endl;
	//}
	xMath::initSinTable();


	for (float deg = 0; deg <= 90; deg += 5)
	{
		cout << "sinf(" << deg << "): " << sinf(deg * xMath::DEG_TO_RAD)
			<< " | xMath::sin(" << deg << "): " << xMath::sin(deg) << endl ;
	}

	


	system("PAUSE");
    return 0;
}



