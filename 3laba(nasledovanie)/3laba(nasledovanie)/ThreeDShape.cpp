#include "ThreeDShape.h"
void ThreeDShape::Print()											//��������������� ������� ������
{
	cout << Name << endl;											//����� ����� ������
	if (m_cVolume > 0)												//���� ����� ���������
	{
		cout << m_cVolume;											//����� ������ ������
	}
	cout << endl;
}