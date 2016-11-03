//ƒоделать ввод и вывод.
#include "Businessman.h"
#include "Tourist.h"
#include "TourBisn.h"
#include "Queue.cpp"
#include "Interface.cpp"
#include "Exception.h"
int InputInt(int min, int max)
{
	int num;
	while (1)
	{
		cin >> num;
		try
		{
			if (cin.fail())
			{
				throw new not_int();
			}
			if (num < min || num > max)
			{
				throw new out_of_size();
			}
		}
		catch (InputExp* exp)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Number of error is " << exp->error() << endl;
			cout << exp->what() << endl;
			delete exp;
			continue;
		}
		return num;
	}
}
void TestHuman()
{
	Human h;
	int n;
	char ss[SIZE];
	cout << "Human test";
	cout << endl << endl;
	cout << "Name:";
	cin >> ss;														//¬вод имени
	h.SetName(ss);
	cout << "Surname: ";
	cin >> ss;														//¬вод фамилии
	h.SetSurName(ss);
	cout << "Middle name: ";
	cin >> ss;														//¬вод отчества
	h.SetMiddleName(ss);
	cout << "Year of birth: ";
	cin >> n;														//¬вод года рождени€
	h.SetYearOfBirth(n);
	cout << h;														//¬ывод объекта
	cout << endl << endl;
}
void TestBusinessman()
{
	Businessman b;
	int n;
	char ss[SIZE];
	cout << "Businessman test";
	cout << endl << endl;
	cout << "Name:";
	cin >> ss;														//¬вод имени
	b.SetName(ss);
	cout << "Surname: ";
	cin >> ss;														//¬вод фамилии
	b.SetSurName(ss);
	cout << "Middle name: ";
	cin >> ss;														//¬вод отчества
	b.SetMiddleName(ss);
	cout << "Year of birth: ";
	cin >> n;														//¬вод года рождени€
	b.SetYearOfBirth(n);
	cout << "License num: ";
	cin >> n;														//¬вод номера лицензии
	b.SetLicenseNum(n);
	for (int i = 0; i < NUM; i++)									//¬вод платежей
	{
		cout << "Pay date: ";
		cin >> ss;
		cout << "Sum: ";
		cin >> n;
		b.AddPayment(ss, n);
	}
	cout << b;
	cout << endl << endl;
}
void TestTourist()
{
	Tourist t;
	int n;
	char ss[SIZE];
	cout << "Tourist test";
	cout << endl << endl;
	cout << "Name:";
	cin >> ss;														//¬вод имени
	t.SetName(ss);
	cout << "Surname: ";
	cin >> ss;														//¬вод фамилии
	t.SetSurName(ss);
	cout << "Middle name: ";
	cin >> ss;														//¬вод отчества
	t.SetMiddleName(ss);
	cout << "Year of birth: ";
	cin >> n;														//¬вод года рождени€
	t.SetYearOfBirth(n);
	cout << "Passport ID: ";
	cin >> n;														//¬вод номера паспорта
	t.SetPassportID(n);
	char s2[SIZE];
	for (int i = 0; i < NUM; i++)									//¬вод петешествий
	{
		cout << "Country: ";
		cin >> ss;
		cout << "Date: ";
		cin >> s2;
		t.AddTravel(ss, s2);
	}
	cout << t;
	cout << endl << endl;
}
void TestTourBisn()
{
	TourBisn tb;
	int n;
	char ss[SIZE];
	cout << "TourBisn test";
	cout << endl << endl;
	cout << "Name:";
	cin >> ss;														//¬вод имени
	tb.SetName(ss);
	cout << "Surname: ";
	cin >> ss;														//¬вод фамилии
	tb.SetSurName(ss);
	cout << "Middle name: ";
	cin >> ss;														//¬вод отчества
	tb.SetMiddleName(ss);
	cout << "Year of birth: ";
	cin >> n;														//¬вод года рождени€
	tb.SetYearOfBirth(n);
	cout << "License num: ";
	cin >> n;														//¬вод номера лицензии
	tb.SetLicenseNum(n);
	cout << "Passport ID: ";
	cin >> n;														//¬вод номера паспорта
	tb.SetPassportID(n);
	for (int i = 0; i < NUM; i++)									//¬вод плтежей
	{
		cout << "Pay date: ";
		cin >> ss;
		cout << "Sum: ";
		cin >> n;
		tb.AddPayment(ss, n);
	}
	char s2[SIZE];
	for (int i = 0; i < NUM; i++)									//¬вод путешествий
	{
		cout << "Country: ";
		cin >> ss;
		cout << "Date: ";
		cin >> s2;
		tb.AddTravel(ss, s2);
	}
	cin.clear();
	while (cin.get() != '\n');
	int i = 1;
	do																//¬вод адресов
	{
		cout << "Address: ";
		cin.getline(ss, SIZE);
		tb.AddAddress(ss);
		cout << "One more address?(1/0): ";
		cin >> i;
		cin.clear();
		while (cin.get() != '\n');
	} while (i);
	cout << tb;
	cout << endl << endl;
}
int main()
{
	menu<Tourist>();
	system("pause");
	return 0;
}