#include "Circle.h"
void Circle::Print()											//��������������� ������� ������
{
	TwoDShape::Print();
}
double Circle::CountArea()										//��������������� ������� �������� �������
{
	double R = sqrt(pow(abs(X1 - X2), 2) + pow(abs(Y1 - Y2), 2));	//������� �������
	m_cArea = 3.14 * pow(R, 2);									//������� ����� �������
	return m_cArea;
}