#include "Triangle.h"
Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3, char* s) : TwoDShape(x1, y1, s), X2(x2), Y2(y2), X3(x3), Y3(y3)
{																//Конструктор
	cout << "Triangle constructor." << endl;
}
void Triangle::Print()											//Переопределение функции вывода
{
	TwoDShape::Print();
}
double Triangle::CountArea()									//Переопределение функции подсчета площади
{
	double l1, l2, l3;
	l1 = sqrt(pow(abs(X1 - X2), 2) + pow(abs(Y1 - Y2), 2));		//Вычисление длин сторон
	l2 = sqrt(pow(abs(X1 - X3), 2) + pow(abs(Y1 - Y3), 2));
	l3 = sqrt(pow(abs(X2 - X3), 2) + pow(abs(Y2 - Y3), 2));
	double p=(l1+l2+l3)/2;
	if (p*(p - l1)*(p - l2)*(p - l3) > 0)						//Если подкоренное выражение отрицательное
	{
		return m_cArea = sqrt(p*(p - l1)*(p - l2)*(p - l3));	//Подсчет самой площади
	}
	else
	{
		return 0.0;												//Иначе треугольник задан неверно
	}
}