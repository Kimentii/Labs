//�������� ���� � �����.
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
		for (int i = 0; i < 3; i++)											//����� ��������
		{
			cout << TouristMass[i];
			cout << endl << endl;
		}
		for (int i = 0; i < 3; i++)											//���� ��������
		{
			cout << endl << endl;
			cout << "Name:";
			cin >> ss;														//���� �����
			TouristMass[i].SetName(ss);
			cout << "Surname: ";
			cin >> ss;														//���� �������
			TouristMass[i].SetSurName(ss);
			cout << "Middle name: ";
			cin >> ss;														//���� ��������
			TouristMass[i].SetMiddleName(ss);
			cout << "Year of birth: ";
			cin >> n;														//���� ���� ��������
			TouristMass[i].SetYearOfBirth(n);
			cout << "Passport ID: ";
			cin >> n;														//���� ������ ��������
			TouristMass[i].SetPassportID(n);
			char s2[SIZE];
			for (int i = 0; i < NUM; i++)									//���� �����������
			{
				cout << "Country: ";
				cin >> ss;
				cout << "Date: ";
				cin >> s2;
				TouristMass[i].AddTravel(ss, s2);
			}
		}
		cout << endl << "Your tourists:" << endl;
		for (int i = 0; i < 3; i++)											//����� ��������
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
		for (int i = 0; i < 3; i++)											//����� ��������
		{
			cout << TouristMass[i];
			cout << endl << endl;
		}
	//	cout << endl << "Your bisnessmans:" << endl;						//����� ������������
	//	for (int i = 0; i < 3; i++)
	//	{
	//		cout << BisMass[i];
	//		cout << endl << endl;
	//	}
	//	for (int i = 0; i < 3; i++)											//���� Bisenessman
	//	{
	//		cout << "Businessman test";
	//		cout << endl << endl;
	//		cout << "Name:";
	//		cin >> ss;														//���� �����
	//		BisMass[i].SetName(ss);
	//		cout << "Surname: ";
	//		cin >> ss;														//���� �������
	//		BisMass[i].SetSurName(ss);
	//		cout << "Middle name: ";
	//		cin >> ss;														//���� ��������
	//		BisMass[i].SetMiddleName(ss);
	//		cout << "Year of birth: ";
	//		cin >> n;														//���� ���� ��������
	//		BisMass[i].SetYearOfBirth(n);
	//		cout << "License num: ";
	//		cin >> n;														//���� ������ ��������
	//		BisMass[i].SetLicenseNum(n);
	//		for (int i = 0; i < NUM; i++)									//���� ��������
	//		{
	//			cout << "Pay date: ";
	//			cin >> ss;
	//			cout << "Sum: ";
	//			cin >> n;
	//			BisMass[i].AddPayment(ss, n);
	//		}
	//	}
	//	cout << endl << "Your bisnessmans:" << endl;						//����� ������������
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
	//	for (int i = 0; i < 3; i++)											//����� ������������
	//	{
	//		cout << BisMass[i];
	//		cout << endl << endl;
	//	}
	//	cout << "Yout TourBisns: " << endl;
	//	for (int i = 0; i < 3; i++)											//����� TourBisn
	//	{
	//		cout << TBMass[i];
	//		cout << endl << endl;
	//	}
	//	for (int i = 0; i < 3; i++)											//TourBisn ����
	//	{
	//		cout << endl << endl;
	//		cout << "Name:";
	//		cin >> ss;														//���� �����
	//		TBMass[i].SetName(ss);
	//		cout << "Surname: ";
	//		cin >> ss;														//���� �������
	//		TBMass[i].SetSurName(ss);
	//		cout << "Middle name: ";
	//		cin >> ss;														//���� ��������
	//		TBMass[i].SetMiddleName(ss);
	//		cout << "Year of birth: ";
	//		cin >> n;														//���� ���� ��������
	//		TBMass[i].SetYearOfBirth(n);
	//		cout << "License num: ";
	//		cin >> n;														//���� ������ ��������
	//		TBMass[i].SetLicenseNum(n);
	//		cout << "Passport ID: ";
	//		cin >> n;														//���� ������ ��������
	//		TBMass[i].SetPassportID(n);
	//		for (int i = 0; i < NUM; i++)									//���� �������
	//		{
	//			cout << "Pay date: ";
	//			cin >> ss;
	//			cout << "Sum: ";
	//			cin >> n;
	//			TBMass[i].AddPayment(ss, n);
	//		}
	//		char s2[SIZE];
	//		for (int i = 0; i < NUM; i++)									//���� �����������
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
	//		do																//���� �������
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
	//	for (int i = 0; i < 3; i++)											//����� TourBisn
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
	//	for (int i = 0; i < 3; i++)											//����� TourBisn
	//	{
	//		cout << TBMass[i];
	//		cout << endl << endl;
	//	}
	//}
	system("pause");
	return 0;
}