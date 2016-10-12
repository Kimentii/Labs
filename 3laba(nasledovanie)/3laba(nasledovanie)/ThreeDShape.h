#ifndef _THREEDSHAPE_H_													//���� ������ ��� ��� �� ����������
#define _THREEDSHAPE_H_													//�� ���������� ���
#include "Shape.h"
class ThreeDShape : public Shape
{
protected:																//protected �������, ����� �������������
	int m_cVolume;
	int X1, Y1;
	int X2, Y2;
public:
	~ThreeDShape() { cout << "ThreeDShape destructor." << endl; }		//����������� ����������
	ThreeDShape(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, char* s = "3Dfigure") :Shape(s), X1(x1), Y1(y1), X2(x2), Y2(y2) 
	{																	//����������� � ����������� �� ���������
		cout << "ThreeDShape constuctor." << endl;
	}
	void Print();														//������� ������
	double CountVolume() = 0;
	double CountArea() { return 0.0; }
};
#endif																	//����� �� ������������� ��� �� #endif