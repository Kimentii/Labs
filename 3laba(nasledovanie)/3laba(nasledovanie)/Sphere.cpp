#include "Sphere.h"
void Sphare::Print()											//��������������� ������� ������
{
	ThreeDShape::Print();
}
double Sphare::CountVolume()									//��������������� ������� �������� ������
{
	double R;
	R = sqrt(pow(abs(X1 - X2), 2) * pow(abs(Y1 - Y2), 2));		//������� �������
	m_cVolume = 4/3 * 3.14 * R * R;								//���������� ������
	return m_cVolume;
}