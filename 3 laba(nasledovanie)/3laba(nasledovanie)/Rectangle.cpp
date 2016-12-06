#include "Rectangle.h"
void Rectangle::Print()											//Переопределение функции вывода
{
	TwoDShape::Print();
}
double Rectangle::CountArea()									//Переопределение функции подсчета площади
{
	double D = sqrt(pow(abs(X1 - X2), 2) * pow(abs(Y1 - Y2), 2));	//Вычисление длины диагонали
	return m_cArea = 0.5 * D * D;								//Подсчет самой площади
}