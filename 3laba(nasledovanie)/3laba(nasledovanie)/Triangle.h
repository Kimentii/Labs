#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include "TwoDShapes.h"
class Triangle : public TwoDShape
{
private:
	int X2, Y2;
	int X3, Y3;
public:
	Triangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int x3 = 0, int y3 = 0, char* s = "Triangle");
	void Print();
	double CountVolume() { return 0.0; }
	double CountArea();
};
#endif _TRIANGLE_H_