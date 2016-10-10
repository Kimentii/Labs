#include "Rectangle.h"
void Rectangle::Print()
{
	TwoDShape::Print();
}
double Rectangle::CountArea()
{
	double D = sqrt(pow(abs(X1 - X2), 2) * pow(abs(Y1 - Y2), 2));
	return m_cArea = 0.5 * D * D;
}