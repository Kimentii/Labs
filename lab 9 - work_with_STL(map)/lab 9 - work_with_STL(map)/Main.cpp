#include "Businessman.h"
#include "Tourist.h"
#include "TourBisn.h"
#include "Interface.cpp"
#include "Exception.h"
#include "SafeFunctions.h"
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
		cout << "6 - TourBissn" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 7);								//Ввод выбора
		system("cls");
		switch (x)												//Вызов соответствующей функции
		{
		case 1:
			menu<int, int>();
			break;
		case 2:
			menu<int, double>();
			break;
		case 3:
			menu<int, char>();
			break;
		case 4:
			menu<int, Tourist>();
			break;
		case 5:
			menu<int, Businessman>();
			break;
		case 6:
			menu<int, TourBisn>();
			break;
		}
	} while (x);
}
int main()
{
	choise();
	system("pause");
	return 0;
}