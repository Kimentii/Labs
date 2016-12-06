#include "Cylinder.h"
void Cylinder::Print()											//��������������� ������� ������
{
	ThreeDShape::Print();
}
double Cylinder::CountVolume()									//��������������� ������� �������� ������
{
	double R = sqrt(pow(abs(X1 - X2), 2) + pow(abs(Y1 - Y2), 2));	//������� �������
	double S, h;
	S = 3.14*pow(R, 2);											//���������� ������� ���������
	h = sqrt(pow(abs(X2 - X3), 2) + pow(abs(Y2 - Y3), 2));		//���������� ������
	m_cVolume = S * h;											//������� ������
	return m_cVolume;
}
double Cylinder::CountArea()
{
	double R = sqrt(pow(abs(X1 - X2), 2) + pow(abs(Y1 - Y2), 2));	//������� �������
	double S, h;
	S = 3.14*pow(R, 2);											//���������� ������� ���������
	h = sqrt(pow(abs(X2 - X3), 2) + pow(abs(Y2 - Y3), 2));		//���������� ������
	m_cArea = S * 2 + 2 * 3.14 * R * h;							//���������� ������� �������
	return m_cArea;
}