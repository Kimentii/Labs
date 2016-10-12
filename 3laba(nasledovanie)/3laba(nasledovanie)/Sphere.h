#ifndef _SPHERE_H_													//Если данное имя еще не определено
#define _SPHERE_H_													//То определить его
#include "ThreeDShape.h"
class Sphare : public ThreeDShape
{
public:
	~Sphare() { cout << "Sphare destructor." << endl; }				//Виртуальный деструктор
	Sphare(int x1, int y1, int x2, int y2, char*s = "Sphare") : ThreeDShape(x1, y1, x2, y2, s) 
	{																//Конструктор с параметрами по умолчанию
		cout << "Sphare constuctor." << endl;
	}
	void Print();													//Функция вывода
	double CountVolume();											//Функция подсчета объема
	double CountArea() { return ThreeDShape::CountArea(); }
};
#endif																//Иначе не компилировать код до #endif
