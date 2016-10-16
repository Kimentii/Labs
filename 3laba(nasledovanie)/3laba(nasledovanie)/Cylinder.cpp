#include "Cylinder.h"
void Cylinder::Print()											//Переопределение функции вывода
{
	ThreeDShape::Print();
}
double Cylinder::CountVolume()									//Переопределение функции подсчета объема
{
	double R = sqrt(pow(abs(X1 - X2), 2) + pow(abs(Y1 - Y2), 2));	//Подсчет радиуса
	double S, h;
	S = 3.14*pow(R, 2);											//Вычисление площади основания
	h = sqrt(pow(abs(X2 - X3), 2) + pow(abs(Y2 - Y3), 2));		//Вычисление высоты
	m_cVolume = S * h;											//Подсчет объема
	return m_cVolume;
}
double Cylinder::CountArea()
{
	double R = sqrt(pow(abs(X1 - X2), 2) + pow(abs(Y1 - Y2), 2));	//Подсчет радиуса
	double S, h;
	S = 3.14*pow(R, 2);											//Вычисление площади основания
	h = sqrt(pow(abs(X2 - X3), 2) + pow(abs(Y2 - Y3), 2));		//Вычисление высоты
	m_cArea = S * 2 + 2 * 3.14 * R * h;							//Вычисление боковай площади
	return m_cArea;
}