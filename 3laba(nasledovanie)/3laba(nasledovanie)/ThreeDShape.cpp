#include "ThreeDShape.h"
void ThreeDShape::Print()
{
	cout << "Name(3Dfigure):" << Name << endl;
	if (m_cVolume)
	{
		cout << "Volume: " << m_cVolume;
	}
	else
	{
		cout << "Please count volume.";
	}
	cout << endl;
}