#ifndef _CYLINDER_H_													//���� ������ ��� ��� �� ����������
#define _CYLINDER_H_													//�� ���������� ���
#include "ThreeDShape.h"
class Cylinder : public ThreeDShape
{
private:																//Ptivate, ������������� �� �����
	int X3, Y3;
public:
	~Cylinder() { cout << "Cylinder destructor." << endl; }				//����������� ����������
	Cylinder(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int x3 = 0, int y3 = 0, char*s = "Cylinder") :ThreeDShape(x1, y1, x2, y2, s), X3(x3), Y3(y3) 
	{																	//����������� � ����������� �� ���������
		cout << "Cylinder constuctor." << endl;
	}
	void Print();														//������� ������
	double CountVolume();												//������� �������� ������
	double CountArea();
};
#endif																	//����� �� ������������� ��� �� #endif
