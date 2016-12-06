#ifndef _TRIANGLE_H_													//���� ������ ��� ��� �� ����������
#define _TRIANGLE_H_													//�� ���������� ���
#include "TwoDShapes.h"
class Triangle : public TwoDShape										//����� ������������ �� TwoDShape
{
private:																//Ptivate, ������������� �� �����
	int X2, Y2;
	int X3, Y3;
public:
	~Triangle() { cout << "Triangle destructor." << endl; }				//����������� ����������
	Triangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int x3 = 0, int y3 = 0, char* s = "Triangle");	//�����������
	void Print();														//������� ������
	double CountVolume() { return TwoDShape::CountVolume(); }
	double CountArea();													//������� �������� �������
};
#endif					 												//����� �� ������������� ��� �� #endif