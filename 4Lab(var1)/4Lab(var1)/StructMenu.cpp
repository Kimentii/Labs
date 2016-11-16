#include "Human.h"
void StructMenu(Human& el)
{
	char s[SIZE];
	int x;
	cout.setf(ios::left);
	system("cls");
	do
	{
		cout << "What do you want to do?" << endl;
		cout << "1 - Show struct" << endl;
		cout << "2 - Change name" << endl;
		cout << "3 - Change surname" << endl;
		cout << "4 - Change middle name" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 4);
		switch (x)
		{
		case 1:
			system("cls");
			cout << el << endl;
			break;
		case 2:
			system("cls");
			cout << "Enter new name: ";
			InputString(cin, s, SIZE);
			el.SetName(s);
			break;
		case 3:
			system("cls");
			break;
		case 4:
			break;
		}
	} while (x);
}