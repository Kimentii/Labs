//Доделать ввод и вывод.
#include "Businessman.h"
#include "Tourist.h"
#include "TourBisn.h"
void TestHuman()
{
	Human h;
	int n;
	char ss[SIZE];
	cout << "Human test";
	cout << endl << endl;
	cout << "Name:";
	cin >> ss;														//Ввод имени
	h.SetName(ss);
	cout << "Surname: ";
	cin >> ss;														//Ввод фамилии
	h.SetSurName(ss);
	cout << "Middle name: ";
	cin >> ss;														//Ввод отчества
	h.SetMiddleName(ss);
	cout << "Year of birth: ";
	cin >> n;														//Ввод года рождения
	h.SetYearOfBirth(n);
	cout << h;														//Вывод объекта
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
	cin >> ss;														//Ввод имени
	b.SetName(ss);
	cout << "Surname: ";
	cin >> ss;														//Ввод фамилии
	b.SetSurName(ss);
	cout << "Middle name: ";
	cin >> ss;														//Ввод отчества
	b.SetMiddleName(ss);
	cout << "Year of birth: ";
	cin >> n;														//Ввод года рождения
	b.SetYearOfBirth(n);
	cout << "License num: ";
	cin >> n;														//Ввод номера лицензии
	b.SetLicenseNum(n);
	for (int i = 0; i < NUM; i++)									//Ввод платежей
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
	cin >> ss;														//Ввод имени
	t.SetName(ss);
	cout << "Surname: ";
	cin >> ss;														//Ввод фамилии
	t.SetSurName(ss);
	cout << "Middle name: ";
	cin >> ss;														//Ввод отчества
	t.SetMiddleName(ss);
	cout << "Year of birth: ";
	cin >> n;														//Ввод года рождения
	t.SetYearOfBirth(n);
	cout << "Passport ID: ";
	cin >> n;														//Ввод номера паспорта
	t.SetPassportID(n);
	char s2[SIZE];
	for (int i = 0; i < NUM; i++)									//Ввод петешествий
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
	cin >> ss;														//Ввод имени
	tb.SetName(ss);
	cout << "Surname: ";
	cin >> ss;														//Ввод фамилии
	tb.SetSurName(ss);
	cout << "Middle name: ";
	cin >> ss;														//Ввод отчества
	tb.SetMiddleName(ss);
	cout << "Year of birth: ";
	cin >> n;														//Ввод года рождения
	tb.SetYearOfBirth(n);
	cout << "License num: ";
	cin >> n;														//Ввод номера лицензии
	tb.SetLicenseNum(n);
	cout << "Passport ID: ";
	cin >> n;														//Ввод номера паспорта
	tb.SetPassportID(n);
	for (int i = 0; i < NUM; i++)									//Ввод плтежей
	{
		cout << "Pay date: ";
		cin >> ss;
		cout << "Sum: ";
		cin >> n;
		tb.AddPayment(ss, n);
	}
	char s2[SIZE];
	for (int i = 0; i < NUM; i++)									//Ввод путешествий
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
	do																//Ввод адресов
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
	//{
		Tourist TouristMass[3];
		for (int i = 0; i < 3; i++)
		{
			cout << "Vvod " << i << "tourist" << endl;
			cin >> TouristMass[i];
		}
		char ss[SIZE];
		char s2[SIZE];
		int n;
		cout << endl << "Your tourists:" << endl;
		for (int i = 0; i < 3; i++)											//Вывод туристов
		{
			cout << TouristMass[i];
			cout << endl << endl;
		}
		for (int i = 0; i < 3; i++)											//Тест туристов
		{
			cout << endl << endl;
			cout << "Name:";
			cin >> ss;														//Ввод имени
			TouristMass[i].SetName(ss);
			cout << "Surname: ";
			cin >> ss;														//Ввод фамилии
			TouristMass[i].SetSurName(ss);
			cout << "Middle name: ";
			cin >> ss;														//Ввод отчества
			TouristMass[i].SetMiddleName(ss);
			cout << "Year of birth: ";
			cin >> n;														//Ввод года рождения
			TouristMass[i].SetYearOfBirth(n);
			cout << "Passport ID: ";
			cin >> n;														//Ввод номера паспорта
			TouristMass[i].SetPassportID(n);
			char s2[SIZE];
			for (int i = 0; i < NUM; i++)									//Ввод путешествий
			{
				cout << "Country: ";
				cin >> ss;
				cout << "Date: ";
				cin >> s2;
				TouristMass[i].AddTravel(ss, s2);
			}
		}
		cout << endl << "Your tourists:" << endl;
		for (int i = 0; i < 3; i++)											//Вывод туристов
		{
			cout << TouristMass[i];
			cout << endl << endl;
		}
		cout << "What do you want to delete? ";
		cin >> ss;	
		for (int i = 0; i < 3; i++)
		{
			TouristMass[i].DelTravel(ss);
		}	
		for (int i = 0; i < 3; i++)											//Вывод туристов
		{
			cout << TouristMass[i];
			cout << endl << endl;
		}
	//	cout << endl << "Your bisnessmans:" << endl;						//Вывод бизнессменов
	//	for (int i = 0; i < 3; i++)
	//	{
	//		cout << BisMass[i];
	//		cout << endl << endl;
	//	}
	//	for (int i = 0; i < 3; i++)											//Тест Bisenessman
	//	{
	//		cout << "Businessman test";
	//		cout << endl << endl;
	//		cout << "Name:";
	//		cin >> ss;														//Ввод имени
	//		BisMass[i].SetName(ss);
	//		cout << "Surname: ";
	//		cin >> ss;														//Ввод фамилии
	//		BisMass[i].SetSurName(ss);
	//		cout << "Middle name: ";
	//		cin >> ss;														//Ввод отчества
	//		BisMass[i].SetMiddleName(ss);
	//		cout << "Year of birth: ";
	//		cin >> n;														//Ввод года рождения
	//		BisMass[i].SetYearOfBirth(n);
	//		cout << "License num: ";
	//		cin >> n;														//Ввод номера лицензии
	//		BisMass[i].SetLicenseNum(n);
	//		for (int i = 0; i < NUM; i++)									//Ввод платежей
	//		{
	//			cout << "Pay date: ";
	//			cin >> ss;
	//			cout << "Sum: ";
	//			cin >> n;
	//			BisMass[i].AddPayment(ss, n);
	//		}
	//	}
	//	cout << endl << "Your bisnessmans:" << endl;						//Вывод бизнессменов
	//	for (int i = 0; i < 3; i++)
	//	{
	//		cout << BisMass[i];
	//		cout << endl << endl;
	//	}
	//	cout << "What do you want to delete? ";
	//	cin >> ss;
	//	for (int i = 0; i < 3; i++)
	//	{
	//		BisMass[i].DelPayment(ss);
	//	}
	//	for (int i = 0; i < 3; i++)											//Вывод бизнессменов
	//	{
	//		cout << BisMass[i];
	//		cout << endl << endl;
	//	}
	//	cout << "Yout TourBisns: " << endl;
	//	for (int i = 0; i < 3; i++)											//Вывод TourBisn
	//	{
	//		cout << TBMass[i];
	//		cout << endl << endl;
	//	}
	//	for (int i = 0; i < 3; i++)											//TourBisn тест
	//	{
	//		cout << endl << endl;
	//		cout << "Name:";
	//		cin >> ss;														//Ввод имени
	//		TBMass[i].SetName(ss);
	//		cout << "Surname: ";
	//		cin >> ss;														//Ввод фамилии
	//		TBMass[i].SetSurName(ss);
	//		cout << "Middle name: ";
	//		cin >> ss;														//Ввод отчества
	//		TBMass[i].SetMiddleName(ss);
	//		cout << "Year of birth: ";
	//		cin >> n;														//Ввод года рождения
	//		TBMass[i].SetYearOfBirth(n);
	//		cout << "License num: ";
	//		cin >> n;														//Ввод номера лицензии
	//		TBMass[i].SetLicenseNum(n);
	//		cout << "Passport ID: ";
	//		cin >> n;														//Ввод номера паспорта
	//		TBMass[i].SetPassportID(n);
	//		for (int i = 0; i < NUM; i++)									//Ввод плтежей
	//		{
	//			cout << "Pay date: ";
	//			cin >> ss;
	//			cout << "Sum: ";
	//			cin >> n;
	//			TBMass[i].AddPayment(ss, n);
	//		}
	//		char s2[SIZE];
	//		for (int i = 0; i < NUM; i++)									//Ввод путешествий
	//		{
	//			cout << "Country: ";
	//			cin >> ss;
	//			cout << "Date: ";
	//			cin >> s2;
	//			TBMass[i].AddTravel(ss, s2);
	//		}
	//		cin.clear();
	//		while (cin.get() != '\n');
	//		int x = 1;
	//		do																//Ввод адресов
	//		{
	//			cout << "Address: ";
	//			cin.getline(ss, SIZE);
	//			TBMass[i].AddAddress(ss);
	//			cout << "One more address?(1/0): ";
	//			cin >> x;
	//			cin.clear();
	//			while (cin.get() != '\n');
	//		} while (x);
	//	}
	//	cout << "Yout TourBisns: " << endl;
	//	for (int i = 0; i < 3; i++)											//Вывод TourBisn
	//	{
	//		cout << TBMass[i];
	//		cout << endl << endl;
	//	}
	//	cout << "What do you whant to delete? ";
	//	cin >> ss;
	//	for (int i = 0; i < 3; i++)
	//	{
	//		TBMass[i].DelAddress(ss);
	//	}
	//	cout << "Yout TourBisns: " << endl;
	//	for (int i = 0; i < 3; i++)											//Вывод TourBisn
	//	{
	//		cout << TBMass[i];
	//		cout << endl << endl;
	//	}
	//}
	system("pause");
	return 0;
}