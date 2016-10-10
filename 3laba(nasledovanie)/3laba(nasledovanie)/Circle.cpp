#include "Circle.h"
#include <math.h>
#pragma warning(disable : 4996)
using namespace std;
void Circle::Print()
{
	TwoDShape::Print();
}
double Circle::CountArea()
{
	double R = sqrt(pow(abs(X1 - X2), 2) + pow(abs(Y1 - Y2), 2));
	return m_cArea = 3.14 * pow(R, 2);
}