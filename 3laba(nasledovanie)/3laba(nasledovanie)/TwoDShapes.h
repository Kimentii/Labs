#ifndef _TWODSHAPE_H_													//���� ������ ��� ��� �� ����������
#define _TWODSHAPE_H_													//�� ���������� ���
#include "Shape.h"
class TwoDShape : public Shape											//����� ������������ �� ������ Shape
{
protected:																//protected �������, ����� �������������
	double m_cArea;														//������� ������
	int X1, Y1;
public:
	~TwoDShape() { cout << "TwoDShape destructor." << endl; }			//����������� ����������
	TwoDShape( int x1 = 0, int y1 = 0, char* s="2D figure.") : X1(x1), Y1(y1), Shape(s), m_cArea(0.0)
	{ 																	//����������� � ����������� �� ���������
		cout << "TwoDShape constructor." << endl;
	}
	void Print();														//������� ������
	double CountVolume() { return 0.0; }								//����������� ������� �������� ������
	double CountArea() = 0;												//������ ����������� ������� �������� �������
};
#endif																	//����� �� ������������� ��� �� #endif