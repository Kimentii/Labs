#ifndef _SPHERE_H_													//���� ������ ��� ��� �� ����������
#define _SPHERE_H_													//�� ���������� ���
#include "ThreeDShape.h"
class Sphare : public ThreeDShape
{
public:
	~Sphare() { cout << "Sphare destructor." << endl; }				//����������� ����������
	Sphare(int x1, int y1, int x2, int y2, char*s = "Sphare") : ThreeDShape(x1, y1, x2, y2, s) 
	{																//����������� � ����������� �� ���������
		cout << "Sphare constuctor." << endl;
	}
	void Print();													//������� ������
	double CountVolume();											//������� �������� ������
	double CountArea() { return ThreeDShape::CountArea(); }
};
#endif																//����� �� ������������� ��� �� #endif
