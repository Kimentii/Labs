#ifndef _SPHERE_H_													//���� ������ ��� ��� �� ����������
#define _SPHERE_H_													//�� ���������� ���
#include "ThreeDShape.h"
class Sphere : public ThreeDShape
{
	double R;
public:
	~Sphere() { cout << "Sphere destructor." << endl; }				//����������� ����������
	Sphere(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, char*s = "Sphare") : ThreeDShape(x1, y1, x2, y2, s), R(0.0)
	{																//����������� � ����������� �� ���������
		cout << "Sphare constuctor." << endl;
	}
	void Print();													//������� ������
	double CountVolume();											//������� �������� ������
	double CountArea();
};
#endif																//����� �� ������������� ��� �� #endif