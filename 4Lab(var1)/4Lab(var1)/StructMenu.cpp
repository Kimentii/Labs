#include "Human.h"
#include "Businessman.h"
#include "Tourist.h"
#include "TourBisn.h"
#define MENU cout << "What do you want to do?" << endl << "1 - Show struct" << endl << "2 - Change name" << endl << "3 - Change surname" << endl << "4 - Change middle name" << endl << "5 - Chenge year of birth" << endl;
void StructMenu(Human& el)
{
	char s[SIZE];
	int x, buf;
	cout.setf(ios::left);
	system("cls");
	do
	{
		MENU
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 5);
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
			cout << "Enter new surname: ";
			InputString(cin, s, SIZE);
			el.SetSurName(s);
			break;
		case 4:
			system("cls");
			cout << "Enter new middle name: ";
			InputString(cin, s, SIZE);
			el.SetMiddleName(s);
			break;
		case 5:
			system("cls");
			cout << "Enter new year: " << endl;
			buf = InputInt(cin, 1800, 2100);
			el.SetYearOfBirth(buf);
			break;
		}
	} while (x);
}
void StructMenu(Businessman& el)
{
	char s[SIZE];
	int x, buf;
	cout.setf(ios::left);
	system("cls");
	do
	{
		MENU
		cout << "6 - Change license number" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 6);
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
			cout << "Enter new surname: ";
			InputString(cin, s, SIZE);
			el.SetSurName(s);
			break;
		case 4:
			system("cls");
			cout << "Enter new middle name: ";
			InputString(cin, s, SIZE);
			el.SetMiddleName(s);
			break;
		case 5:
			system("cls");
			cout << "Enter new year: " << endl;
			buf = InputInt(cin, 1800, 2100);
			el.SetYearOfBirth(buf);
			break;
		case 6:
			system("cls");
			cout << "Enter new license number: ";
			buf = InputInt();
			el.SetLicenseNum(buf);
			break;
		}
	} while (x);
}
void StructMenu(Tourist& el)
{
	char s[SIZE];
	int x, buf;
	cout.setf(ios::left);
	system("cls");
	do
	{
		MENU
		cout << "6 - Change passport ID" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 6);
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
			cout << "Enter new surname: ";
			InputString(cin, s, SIZE);
			el.SetSurName(s);
			break;
		case 4:
			system("cls");
			cout << "Enter new middle name: ";
			InputString(cin, s, SIZE);
			el.SetMiddleName(s);
			break;
		case 5:
			system("cls");
			cout << "Enter new year: " << endl;
			buf = InputInt(cin, 1800, 2100);
			el.SetYearOfBirth(buf);
			break;
		case 6:
			system("cls");
			cout << "Enter new passpord ID: ";
			buf = InputInt();
			el.SetPassportID(buf);
			break;
		}
	} while (x);
}
void StructMenu(TourBisn& el)
{
	char s[SIZE];
	int x, buf;
	cout.setf(ios::left);
	system("cls");
	do
	{
		MENU
		cout << "6 - Change license number" << endl;
		cout << "7 - Change license number" << endl;
		cout << "0 - exit" << endl;
		cout << "Your choice: ";
		x = InputInt(cin, 0, 7);
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
			cout << "Enter new surname: ";
			InputString(cin, s, SIZE);
			el.SetSurName(s);
			break;
		case 4:
			system("cls");
			cout << "Enter new middle name: ";
			InputString(cin, s, SIZE);
			el.SetMiddleName(s);
			break;
		case 5:
			system("cls");
			cout << "Enter new year: " << endl;
			buf = InputInt(cin, 1800, 2100);
			el.SetYearOfBirth(buf);
			break;
		case 6:
			system("cls");
			cout << "Enter new license number: ";
			buf = InputInt();
			el.SetLicenseNum(buf);
			break;
		case 7:
			system("cls");
			cout << "Enter new passpord ID: ";
			buf = InputInt();
			el.SetPassportID(buf);
			break;
		}
	} while (x);
}