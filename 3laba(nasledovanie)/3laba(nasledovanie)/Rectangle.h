#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include "TwoDShapes.h"
class Rectangle : public TwoDShape
{
private:
	int X2, Y2;
public:
	Rectangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, char* s = "Rectangle") : TwoDShape(x1, y1, s), X2(x2), Y2(y2)
	{
		cout << "Rectangle constuctor." << endl;
	}
	void Print();
	double CountVolume() { return 0.0; }
	double CountArea();
};
#endif