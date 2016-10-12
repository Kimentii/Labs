#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Cylinder.h"
int main()
{
	Shape** p = new Shape*[5];
	{
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
		for (int i = 0; i < 5; i++)
		{
			p[i]->CountArea();									//������� ������ ������
			p[i]->CountVolume();								//������� ������ ������
			p[i]->Print();										//����� ����� � ������/�������
		}
	}
	delete[] p;
	system("pause");
	return 0;
}