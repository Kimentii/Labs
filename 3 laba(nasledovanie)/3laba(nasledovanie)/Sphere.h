#ifndef _SPHERE_H_													//Если данное имя еще не определено
#define _SPHERE_H_													//То определить его
#include "ThreeDShape.h"
class Sphere : public ThreeDShape
{
	double R;
public:
	~Sphere() { cout << "Sphere destructor." << endl; }				//Виртуальный деструктор
	Sphere(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, char*s = "Sphare") : ThreeDShape(x1, y1, x2, y2, s), R(0.0)
	{																//Конструктор с параметрами по умолчанию
		cout << "Sphare constuctor." << endl;
	}
	void Print();													//Функция вывода
	double CountVolume();											//Функция подсчета объема
	double CountArea();
};
#endif																//Иначе не компилировать код до #endif