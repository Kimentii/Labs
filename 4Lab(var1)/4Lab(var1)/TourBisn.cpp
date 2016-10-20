#include "TourBisn.h"
TourBisn::TourBisn(const char* n, const char* sn, const char* mn, int y, int l, int p) : Human(n, sn, mn, y)
{
	Businessman::m_LicenseNum = l;
	Tourist::m_PassportID = p;
	for (int i = 0; i < NUM; i++)
	{
		m_Address[i] = 0;
	}
	cout << "TourBisn constructor" << endl;
}
ostream& operator << (ostream& os, const TourBisn& aTB)
{
	os << dynamic_cast<const Human&>(aTB);
	os << "License number: " << aTB.m_LicenseNum << endl;
	os << "Passport ID: " << aTB.m_PassportID << endl;
	os << "His payments: " << endl;
	for (int i = 0; i < NUM; i++)
	{
		os << "Date: " << aTB.m_Payments[i].PayDate << endl;
		os << "Amount of money: " << aTB.m_Payments[i].Sum << endl;
	}
	os << "Travels:" << endl;
	for (int i = 0; i < NUM; i++)
	{
		os << "Country: " << aTB.m_Travels[i].Country << endl;
		os << "Date: " << aTB.m_Travels[i].Date << endl;
	}
	return os;
}