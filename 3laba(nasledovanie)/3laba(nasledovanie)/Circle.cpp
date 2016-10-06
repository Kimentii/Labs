#include "Circle.h"
void Circle::Print()
{
	TwoDShape::Print();
}
void Circle::CountArea()
{
	m_cArea = 3.14 * (m_cSecondCoord - m_cFirstCoord);
}
