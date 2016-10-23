#include "Businessman.h"
#include "Tourist.h"
#include "TourBisn.h"
int main()
{
	{
		Human A("Name1", "surname", "middle name", 1998);
		Businessman B("Name2", "surname2", "middle name2", 1999, 2222);
		Tourist T1("Name3", "surname3", "middle name3", 2000, 3333);
		TourBisn T2("Name4", "surname4", "middle name4", 4440, 4441, 4442, -5);
		//A.SetName("A1");
		//A.SetMiddleName("mA1");
		//A.SetSurName("sA1");
		//A.SetYearOfBirth(14);
		//B.SetName("A1");
		//B.SetMiddleName("mA1");
		//B.SetSurName("sA1");
		//B.SetYearOfBirth(14);
		//T2.SetName("A1");
		//T2.SetMiddleName("mA1");
		//T2.SetSurName("sA1");
		//T2.SetYearOfBirth(14);
		//T2.SetLicenseNum(333);
		//B.SetLicenseNum(42);
		//T1.SetPassportID(NUM);
		//T2.SetPassportID(111);
		//B.AddPayment("1", 897);
		//B.AddPayment("2", 100);
		//T2.AddPayment("3", 999);
		//T2.AddPayment("4", 999);
		//B.DelPayment("33333");
		//T2.DelPayment("4");
		//T2.AddTravel("aaa", "111");
		//T2.AddTravel("bbb", "222");	
		//T2.AddTravel("ccc", "333");
		//T2.AddTravel("aaa", "444");
		//T1.AddTravel("aaa", "111");
		//T1.AddTravel("bbb", "222");
		//T1.AddTravel("ccc", "333");
		//T1.DelTravel("342", "");
		//T1.DelTravel("", "222");
		//T1.DelTravel("ccc", "333");
		int i = true;
		char s[SIZE];
		do
		{
			cin.getline(s, SIZE);
			T2.AddAddress(s);
			cout << T2 << endl << endl;
			cin >> i;
			cin.clear();
			while (cin.get() != '\n');
		} while (i);
		i = 1;
		do
		{
			cin.getline(s, SIZE);
			T2.DelAddress(s);
			cout << T2 << endl << endl;
			cin >> i;
			cin.clear();
			while (cin.get() != '\n');
		} while (i);
		/*cout << A << endl << B << endl << T1 << endl << T2 << endl;*/
		//cout << A.GetName() << endl;
		//cout << A.GetSurName() << endl;
		//cout << A.GetMiddleName() << endl << endl << endl;
		//cout << B.GetName() << endl;
		//cout << B.GetSurName() << endl;
		//cout << B.GetMiddleName() << endl << endl << endl;
		//cout << T1.GetName() << endl;
		//cout << T1.GetSurName() << endl;
		//cout << T1.GetMiddleName() << endl << endl << endl;
		//cout << T2.GetName() << endl;
		//cout << T2.GetSurName() << endl;
		//cout << T2.GetMiddleName() << endl << endl << endl;
		//cout << A.GetYear() << endl;
		//cout << B.GetYear() << endl;
		//cout << T1.GetYear() << endl;
		//cout << T2.GetYear() << endl << endl << endl;
		//cout << B.GetLicenseNum() << endl;
		//cout << B.GetTaxPayments()[0].PayDate << endl;
		//cout << B.GetTaxPayments()[0].Sum << endl << endl;
		//cout << T2.GetLicenseNum() << endl;
		//cout << T2.GetTaxPayments()[0].PayDate << endl;
		//cout << T2.GetTaxPayments()[0].Sum << endl << endl;
		//cout << T1.GetPassportID() << endl;
		//cout << T1.GetTravels()[0].Date << endl;
		//cout << T1.GetTravels()[0].Country << endl << endl;
		//cout << T2.GetPassportID() << endl;
		//cout << T2.GetTravels()[0].Date << endl;
		//cout << T2.GetTravels()[0].Country << endl << endl;
		//cout << T2.GetAddress()[0] << endl;
	}
	system("pause");
	return 0;
}