#include "Businessman.h"
#include "Tourist.h"
#include "TourBisn.h"
int main()
{
	{
		Human A("Name1", "surname", "middle name", 1998);
		Businessman B("Name2", "surname2", "middle name2", 1999, 2222);
		Tourist T1("Name3", "surname3", "middle name3", 2000, 3333);
		TourBisn T2("Name4", "surname4", "middle name4", 4440, 4441, 4442);
		cout << A << endl << B << endl << T1 << endl << T2 << endl;
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
		cout << T2.GetAddress()[0] << endl;
	}
	system("pause");
	return 0;
}