//�������� ���� � �����.
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
	cin >> ss;														//���� �����
	h.SetName(ss);
	cout << "Surname: ";
	cin >> ss;														//���� �������
	h.SetSurName(ss);
	cout << "Middle name: ";
	cin >> ss;														//���� ��������
	h.SetMiddleName(ss);
	cout << "Year of birth: ";
	cin >> n;														//���� ���� ��������
	h.SetYearOfBirth(n);
	cout << h;														//����� �������
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
	cin >> ss;														//���� �����
	b.SetName(ss);
	cout << "Surname: ";
	cin >> ss;														//���� �������
	b.SetSurName(ss);
	cout << "Middle name: ";
	cin >> ss;														//���� ��������
	b.SetMiddleName(ss);
	cout << "Year of birth: ";
	cin >> n;														//���� ���� ��������
	b.SetYearOfBirth(n);
	cout << "License num: ";
	cin >> n;														//���� ������ ��������
	b.SetLicenseNum(n);
	for (int i = 0; i < NUM; i++)									//���� ��������
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
	cin >> ss;														//���� �����
	t.SetName(ss);
	cout << "Surname: ";
	cin >> ss;														//���� �������
	t.SetSurName(ss);
	cout << "Middle name: ";
	cin >> ss;														//���� ��������
	t.SetMiddleName(ss);
	cout << "Year of birth: ";
	cin >> n;														//���� ���� ��������
	t.SetYearOfBirth(n);
	cout << "Passport ID: ";
	cin >> n;														//���� ������ ��������
	t.SetPassportID(n);
	char s2[SIZE];
	for (int i = 0; i < NUM; i++)									//���� �����������
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
	cin >> ss;														//���� �����
	tb.SetName(ss);
	cout << "Surname: ";
	cin >> ss;														//���� �������
	tb.SetSurName(ss);
	cout << "Middle name: ";
	cin >> ss;														//���� ��������
	tb.SetMiddleName(ss);
	cout << "Year of birth: ";
	cin >> n;														//���� ���� ��������
	tb.SetYearOfBirth(n);
	cout << "License num: ";
	cin >> n;														//���� ������ ��������
	tb.SetLicenseNum(n);
	cout << "Passport ID: ";
	cin >> n;														//���� ������ ��������
	tb.SetPassportID(n);
	for (int i = 0; i < NUM; i++)									//���� �������
	{
		cout << "Pay date: ";
		cin >> ss;
		cout << "Sum: ";
		cin >> n;
		tb.AddPayment(ss, n);
	}
	char s2[SIZE];
	for (int i = 0; i < NUM; i++)									//���� �����������
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
	do																//���� �������
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