#include "ThreeDShape.h"
void ThreeDShape::Print()											//Переопределение функции вывода
{
	cout << Name << endl;											//Вывод имени фигуры
	if (m_cVolume > 0)												//Если объем подсчитан
	{
		cout << m_cVolume;											//Вывод объема фигуры
	}
	cout << endl;
}