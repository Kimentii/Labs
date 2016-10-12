#ifndef _TWODSHAPE_H_													//Если данное имя еще не определено
#define _TWODSHAPE_H_													//То определить его
#include "Shape.h"
class TwoDShape : public Shape											//Общее наследование от класса Shape
{
protected:																//protected днанный, будуд наследоваться
	double m_cArea;														//Площадь фигуры
	int X1, Y1;
public:
	~TwoDShape() { cout << "TwoDShape destructor." << endl; }			//Виртуальный деструктор
	TwoDShape( int x1 = 0, int y1 = 0, char* s="2D figure.") : X1(x1), Y1(y1), Shape(s), m_cArea(0.0)
	{ 																	//Конструктор с параметрами по умолчанию
		cout << "TwoDShape constructor." << endl;
	}
	void Print();														//Функция вывода
	double CountVolume() { return 0.0; }								//Виртуальная функция подсчета объема
	double CountArea() = 0;												//Чистая виртуальная функция подсчета площади
};
#endif																	//Иначе не компилировать код до #endif