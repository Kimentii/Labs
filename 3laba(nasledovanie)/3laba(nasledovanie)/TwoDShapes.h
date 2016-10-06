#include "Shape.h"
#include <iostream>
using namespace std;
class TwoDShape : public Shape
{
protected:
	int m_cArea;
	int m_cFirstCoord;
public:
	TwoDShape( int fc = 0 ,char* s="2D figure.", int ar=0) : m_cFirstCoord(fc), Shape("2D fiure"), m_cArea(0)
	{ 
		cout << "2DShape constructor." << endl;
	}
	void Print();
	virtual void CountArea() = 0;
};