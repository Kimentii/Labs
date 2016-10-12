#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Cylinder.h"
int main()
{
	Shape** p = new Shape*[5];
	{
		Circle A(1, 2, 3, 4);									//Создание круга
		Rectangle B(1, 2, 3, 4);								//Создание квадрата
		Triangle C(0, 0, 1, 1, 0, 1);							//Создание треугольника
		Sphare D(1, 2, 3, 4);									//Создание сферы
		Cylinder I(1, 2, 3, 4, 5, 6);							//Создание цилиндра
		p[0] = &A;
		p[1] = &B;
		p[2] = &C;
		p[3] = &D;
		p[4] = &I;
		for (int i = 0; i < 5; i++)
		{
			p[i]->CountArea();									//Подсчет площди фигуры
			p[i]->CountVolume();								//Подсчет объема фигуры
			p[i]->Print();										//Вывод имени и объема/площади
		}
	}
	delete[] p;
	system("pause");
	return 0;
}