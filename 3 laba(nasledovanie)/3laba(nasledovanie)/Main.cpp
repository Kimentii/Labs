#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Cylinder.h"
int main()
{
	{
		Shape** p = new Shape*[5];
		p[0] = new Circle(1, 2, 3, 4);										//�������� �����
		p[1] = new Rectangle(1, 2, 3, 4);									//�������� ��������
		p[2] = new Triangle(0, 0, 1, 1, 0, 1);								//�������� ������������
		p[3] = new Sphere(1, 2, 3, 4);										//�������� �����
		p[4] = new Cylinder(1, 2, 3, 4, 5, 6);								//�������� ��������
		for (int i = 0; i < 5; i++)											//������ � �������� ������� ����� �� ������� �����
		{																	//������� ����������
			p[i]->CountArea();												//������� ������ ������
			p[i]->CountVolume();											//������� ������ ������
			p[i]->Print();													//����� ����� � ������/�������
		}
		for (int i = 0; i < 5; i++)
			delete p[i];
		delete[] p;
	}
	system("pause");
	return 0;
}