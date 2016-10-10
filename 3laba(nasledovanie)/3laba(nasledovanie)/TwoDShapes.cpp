#include "TwoDShapes.h"
void TwoDShape::Print()
{
	cout << "Name(2Dfigure):" << Name << endl;
	if (m_cArea)
	{
		cout << "Area: " << m_cArea;
	}
	else
	{
		cout << "Please count area.";
	}
	cout << endl;
}