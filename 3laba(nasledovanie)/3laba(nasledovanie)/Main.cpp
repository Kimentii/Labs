#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Cylinder.h"
int main()
{
	{
		Shape** p = new Shape*[5];
		Circle A(1, 2, 3, 4);									//�������� �����
		Rectangle B(1, 2, 3, 4);								//�������� ��������
		Triangle C(0, 0, 1, 1, 0, 1);							//�������� ������������
		Sphare D(1, 2, 3, 4);									//�������� �����
		Cylinder I(1, 2, 3, 4, 5, 6);							//�������� ��������
		p[0] = &A;
		p[1] = &B;
		p[2] = &C;
		p[3] = &D;
		p[4] = &I;
		for (int i = 0; i < 5; i++)								//������ � �������� ������� ����� �� ������� �����
		{
			p[i]->CountArea();									//������� ������ ������
			p[i]->CountVolume();								//������� ������ ������
			p[i]->Print();										//����� ����� � ������/�������
		}
		delete[] p;
	}
	{
		TwoDShape** p2D = new TwoDShape*[3];
		Circle A(1, 2, 3, 4);									//�������� �����
		Rectangle B(1, 2, 3, 4);								//�������� ��������
		Triangle C(0, 0, 1, 1, 0, 1);							//�������� ������������
		p2D[0] = &A;
		p2D[1] = &B;
		p2D[2] = &C;
		for (int i = 0; i < 3; i++)								//������ � �������� ������� ����� �� ������� �����
		{
			p2D[i]->CountArea();
			p2D[i]->Print();
		}
		delete[] p2D;
	}
	{
		ThreeDShape** p3D = new ThreeDShape*[2];
		Sphare D(1, 2, 3, 4);									//�������� �����
		Cylinder I(1, 2, 3, 4, 5, 6);							//�������� ��������
		p3D[0] = &D;
		p3D[1] = &I;
		for (int i = 0; i < 2; i++)								//������ � �������� ������� ����� �� ������� �����
		{
			p3D[i]->CountArea();
			p3D[i]->CountVolume();
			p3D[i]->Print();
		}
		delete[] p3D;
	}
	system("pause");
	return 0;
}