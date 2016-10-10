#include "Triangle.h"
Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3, char* s) : TwoDShape(x1, y1, s), X2(x2), Y2(y2), X3(x3), Y3(y3)
{
	cout << "Triangle constructor." << endl;
}
void Triangle::Print()
{
	TwoDShape::Print();
}
double Triangle::CountArea()
{
	double l1, l2, l3;
	l1 = sqrt(pow(abs(X1 - X2), 2) + pow(abs(Y1 - Y2), 2));
	l2 = sqrt(pow(abs(X1 - X3), 2) + pow(abs(Y1 - Y3), 2));
	l3 = sqrt(pow(abs(X2 - X3), 2) + pow(abs(Y2 - Y3), 2));
	double p=(l1+l2+l3)/2;
	m_cArea = sqrt(p*(p - l1)*(p - l2)*(p - l3));
	return m_cArea;
}