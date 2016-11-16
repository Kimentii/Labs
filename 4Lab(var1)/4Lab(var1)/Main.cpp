#include "Businessman.h"
#include "Tourist.h"
#include "TourBisn.h"
#include "Queue.cpp"
#include "Interface.cpp"
#include "Exception.h"
#include "SafeFunctions.h"
void choise()
{
	int x;
	cout.setf(ios::left);
	do
	{
		cout << "What type do you want to check?" << endl;		//����� ����
		cout << "1 - int" << endl;
		cout << "2 - double" << endl;
		cout << "3 - char" << endl;
		cout << "4 - Human" << endl;
		cout << "5 - Tourist" << endl;
		cout << "6 - Businesman" << endl;
		cout << "7 - TourBissn" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 7);								//���� ������
		system("cls");
		switch (x)												//����� ��������������� �������
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
			menu<Human>();
			break;
		case 5:
			menu<Tourist>();
			break;
		case 6:
			menu<Businessman>();
			break;
		case 7:
			menu<TourBisn>();
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