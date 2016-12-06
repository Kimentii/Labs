#ifndef _RECTANGLE_H_													//Если данное имя еще не определено
#define _RECTANGLE_H_													//То определить его
#include "TwoDShapes.h"
class Rectangle : public TwoDShape										//Общее наследование от TwoDShape
{
private:																//Ptivate, наследоваться не будут
	int X2, Y2;
public:
	~Rectangle() { cout << "Rectangle destructor." << endl; }			//Виртуальный деструктор
	Rectangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, char* s = "Rectangle") : TwoDShape(x1, y1, s), X2(x2), Y2(y2)
	{																	//Конструктор с параметрами по умолчанию
		cout << "Rectangle constuctor." << endl;
	}
	void Print();														//Функция вывода
	double CountVolume() { return TwoDShape::CountVolume(); }
	double CountArea();													//Функция подсчета площади
};
#endif																	//Иначе не компилировать код до #endif