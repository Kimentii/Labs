#ifndef _THREEDSHAPE_H_
#define _THREEDSHAPE_H_
#include "Shape.h"
class ThreeDShape : public Shape
{
protected:
	int m_cVolume;
	int X1, Y1;
	int X2, Y2;
public:
	~ThreeDShape() {}
	void Print();
	virtual double CountVolume() = 0;
	virtual double CountArea() = 0;
};
#endif