#include "TwoDShapes.h"
void TwoDShape::Print()											//Переопределение функции вывода
{
	cout << Name << endl;										//Вывод имени фигуры
	if (m_cArea > 0)											//Если площадь подсчтана
	{
		cout << m_cArea;										//Вывод площиди фигуры
	}
	cout << endl;
}