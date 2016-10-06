#include "TwoDShapes.h"
void TwoDShape::Print()
{
	cout << "2D figure(" << Name << ")" << endl;
	if (m_cArea)
	{
		cout << "Area is " << m_cArea;
	}
	else
	{
		cout << "Please count area.";
	}
	cout << endl;
}