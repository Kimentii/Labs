//Добавить меню для записи в файл
//Сделать нормальный вывод статуса файла
#include "Businessman.h"
#include "Tourist.h"
#include "Queue.cpp"
#include "Interface.cpp"
#include "Exception.h"
#include "SafeFunctions.h"
#include <exception>
#include "TextFile.cpp"
#include "BinaryFile.cpp"
void choise()
{
	int x;
	cout.setf(ios::left);
	do
	{
		cout << "What type do you want to check?" << endl;		//Вывод меню
		cout << "1 - int" << endl;
		cout << "2 - double" << endl;
		cout << "3 - char" << endl;
		cout << "4 - Tourist" << endl;
		cout << "5 - Businesman" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 5);								//Ввод выбора
		system("cls");
		switch (x)												//Вызов соответствующей функции
		{
		case 1:
			menu<int>();
			break;
		case 2:
			menu<double>();
			break;
		case 3:
			menu<char>();
			break;
		case 4:
			menu<Tourist>();
			break;
		case 5:
			menu<Businessman>();
			break;
		}
	} while (x);
}
const char NAME[] = "C:/Users/Семен/Desktop/a.txt";
int main()
{
	cout.setf(ios::boolalpha);
	choise();													//Вызов функции выбора типа
	system("pause");
	return 0;
}