#ifndef _CIRCLE_H_													//���� ������ ��� ��� �� ����������
#define _CIRCLE_H_													//�� ���������� ���
#include "TwoDShapes.h"
class Circle: public TwoDShape										//����� ������������ �� TwoDShape
{
private:															//Ptivate ������ ��� ������ ������������� �� �����
	int X2, Y2;
public:
	~Circle() { cout << "Circle destructor." << endl; }				//����������� ����������
	Circle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, char* s = "Circle") : TwoDShape(x1, y1, s), X2(x2), Y2(y2)
	{																//����������� � ����������� �� ���������
		cout << "Circle constuctor." << endl;
	}
	void Print();													//������� ������
	double CountVolume() { return TwoDShape::CountVolume(); }
	double CountArea();												//������� �������� �������
};
#endif																//����� �� ������������� ��� �� #endif