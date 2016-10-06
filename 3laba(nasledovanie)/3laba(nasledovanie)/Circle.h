#include "TwoDShapes.h"
class Circle: public TwoDShape
{
protected:
	int m_cSecondCoord;
public:
	Circle(int fc = 0, int sc = 0, char* s = "Circle", int ar = 0) : TwoDShape(fc, s), m_cSecondCoord(sc)
	{
		cout << "Circle constuctor." << endl;
	}
	void Print();
	void CountArea();
};