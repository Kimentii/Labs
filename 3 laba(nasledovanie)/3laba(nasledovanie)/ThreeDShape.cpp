#include "ThreeDShape.h"
void ThreeDShape::Print()											//��������������� ������� ������
{
	cout << Name << endl;											//����� ����� ������
	if (m_cVolume > 0)												//���� ����� ���������
	{
		cout << "Volume: " << m_cVolume;							//����� ������ ������
		cout << endl;
	}
	if (m_cArea > 0)
	{
		cout << "Area: " << m_cArea;
		cout << endl;
	}
}