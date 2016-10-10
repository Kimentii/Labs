#ifndef _TWODSHAPE_H_													//Если данное имя еще не определено
#define _TWODSHAPE_H_													//То определить его
#include "Shape.h"
using namespace std;
class TwoDShape : public Shape
{
protected:
	double m_cArea;
	int X1, Y1;
public:
	~TwoDShape() {}
	TwoDShape( int x1 = 0, int y1 = 0, char* s="2D figure.") : X1(x1), Y1(y1), Shape(s), m_cArea(0.0)
	{ 
		cout << "2DShape constructor." << endl;
	}
	void Print();
	double CountVolume() = 0;
	double CountArea() = 0;
};
#endif																	//Иначе не компилировать код до #endif