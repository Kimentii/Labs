#include "Sphere.h"
void Sphere::Print()											//��������������� ������� ������
{
	ThreeDShape::Print();
}
double Sphere::CountVolume()									//��������������� ������� �������� ������
{
	double R;
	R = sqrt(pow(abs(X1 - X2), 2) * pow(abs(Y1 - Y2), 2));		//������� �������
	m_cVolume = 4/3 * 3.14 * R * R;								//���������� ������
	return m_cVolume;
}
double Sphere::CountArea()
{
	R = sqrt(pow(abs(X1 - X2), 2) * pow(abs(Y1 - Y2), 2));		//������� �������
	m_cArea = 4 * 3.14 * R * R;									//������� ������� �������
	return m_cArea;
}