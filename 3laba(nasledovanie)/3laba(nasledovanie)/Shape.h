#ifndef _SHAPE_H_													//���� ������ ��� ��� �� ����������
#define _SHAPE_H_													//�� ���������� ���
#include <iostream>
#include <math.h>
#pragma warning(disable : 4996)
using namespace std;
class Shape															//����������� �����
{
protected:															//protected ������ ��� ����� �������������
	double m_cArea;													//������� ������
	char Name[80];
public:
	Shape(char* s = "No name", double Ar = 0.0) : m_cArea(Ar)		//����������� � ���������� �� ���������
	{
		cout << "Shape constructor." << endl;
		strcpy_s(Name, s);
	}
	virtual ~Shape() { cout << "Shape destructor." << endl; }		//����������� ����������
	virtual void Print() = 0;										//������ ����������� �������
	virtual double CountVolume() = 0;								//������ ����������� �������
	virtual double CountArea() = 0;									//������ ����������� �������
};
#endif																//����� �� ������������� ��� �� #endif