#ifndef _CYLINDER_H_													//Если данное имя еще не определено
#define _CYLINDER_H_													//То определить его
#include "ThreeDShape.h"
class Cylinder : public ThreeDShape
{
private:																//Ptivate, наследоваться не будут
	int X3, Y3;
public:
	~Cylinder() { cout << "Cylinder destructor." << endl; }				//Виртуальный деструктор
	Cylinder(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int x3 = 0, int y3 = 0, char*s = "Cylinder") :ThreeDShape(x1, y1, x2, y2, s), X3(x3), Y3(y3) 
	{																	//Конструктор с параметрами по умолчанию
		cout << "Cylinder constuctor." << endl;
	}
	void Print();														//Функция вывода
	double CountVolume();												//Функция подсчета объема
	double CountArea();
};
#endif																	//Иначе не компилировать код до #endif
