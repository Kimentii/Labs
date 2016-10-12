#include "Sphere.h"
void Sphare::Print()											//Переопределение функции вывода
{
	ThreeDShape::Print();
}
double Sphare::CountVolume()									//Переопределение функции подсчета объема
{
	double R;
	R = sqrt(pow(abs(X1 - X2), 2) * pow(abs(Y1 - Y2), 2));		//Подсчет радиуса
	m_cVolume = 4/3 * 3.14 * R * R;								//Вычисление объема
	return m_cVolume;
}