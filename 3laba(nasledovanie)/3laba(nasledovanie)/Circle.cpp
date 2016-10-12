#include "Circle.h"
void Circle::Print()											//Переопределение функции вывода
{
	TwoDShape::Print();
}
double Circle::CountArea()										//Переопределение функции подсчета площади
{
	double R = sqrt(pow(abs(X1 - X2), 2) + pow(abs(Y1 - Y2), 2));	//Подсчет радиуса
	m_cArea = 3.14 * pow(R, 2);									//Подсчет самой площади
	return m_cArea;
}