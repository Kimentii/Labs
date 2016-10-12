#ifndef _TRIANGLE_H_													//Если данное имя еще не определено
#define _TRIANGLE_H_													//То определить его
#include "TwoDShapes.h"
class Triangle : public TwoDShape										//Общее наследование от TwoDShape
{
private:																//Ptivate, наследоваться не будут
	int X2, Y2;
	int X3, Y3;
public:
	~Triangle() { cout << "Triangle destructor." << endl; }				//Виртуальный деструктор
	Triangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int x3 = 0, int y3 = 0, char* s = "Triangle");	//Конструктор
	void Print();														//Функция вывода
	double CountVolume() { return TwoDShape::CountVolume(); }
	double CountArea();													//Функция подсчета площади
};
#endif					 												//Иначе не компилировать код до #endif