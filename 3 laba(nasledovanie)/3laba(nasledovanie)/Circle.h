#ifndef _CIRCLE_H_													//Если данное имя еще не определено
#define _CIRCLE_H_													//То определить его
#include "TwoDShapes.h"
class Circle: public TwoDShape										//Общее наследование от TwoDShape
{
private:															//Ptivate потому что больше наследоваться не будут
	int X2, Y2;
public:
	~Circle() { cout << "Circle destructor." << endl; }				//Виртуальный деструктор
	Circle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, char* s = "Circle") : TwoDShape(x1, y1, s), X2(x2), Y2(y2)
	{																//Конструктор с параметрами по умолчанию
		cout << "Circle constuctor." << endl;
	}
	void Print();													//Функция вывода
	double CountVolume() { return TwoDShape::CountVolume(); }
	double CountArea();												//Функция подсчета площади
};
#endif																//Иначе не компилировать код до #endif