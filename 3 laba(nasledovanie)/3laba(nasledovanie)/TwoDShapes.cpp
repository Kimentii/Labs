#include "TwoDShapes.h"
void TwoDShape::Print()											//��������������� ������� ������
{
	cout << Name << endl;										//����� ����� ������
	if (m_cArea > 0)											//���� ������� ���������
	{
		cout << m_cArea;										//����� ������� ������
	}
	cout << endl;
}