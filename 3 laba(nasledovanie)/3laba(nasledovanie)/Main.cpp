#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Cylinder.h"
int main()
{
	{
		Shape** p = new Shape*[5];
		p[0] = new Circle(1, 2, 3, 4);										//Создание круга
		p[1] = new Rectangle(1, 2, 3, 4);									//Создание квадрата
		p[2] = new Triangle(0, 0, 1, 1, 0, 1);								//Создание треугольника
		p[3] = new Sphere(1, 2, 3, 4);										//Создание сферы
		p[4] = new Cylinder(1, 2, 3, 4, 5, 6);								//Создание цилиндра
		for (int i = 0; i < 5; i++)											//Доступ к дочерним классам через их базовый класс
		{																	//Позднее связывание
			p[i]->CountArea();												//Подсчет площди фигуры
			p[i]->CountVolume();											//Подсчет объема фигуры
			p[i]->Print();													//Вывод имени и объема/площади
		}
		for (int i = 0; i < 5; i++)
			delete p[i];
		delete[] p;
	}
	system("pause");
	return 0;
}