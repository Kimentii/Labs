#include "ThreeDShape.h"
void ThreeDShape::Print()											//Переопределение функции вывода
{
	cout << Name << endl;											//Вывод имени фигуры
	if (m_cVolume > 0)												//Если объем подсчитан
	{
		cout << "Volume: " << m_cVolume;							//Вывод объема фигуры
		cout << endl;
	}
	if (m_cArea > 0)
	{
		cout << "Area: " << m_cArea;
		cout << endl;
	}
}