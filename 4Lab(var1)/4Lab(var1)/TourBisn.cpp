#include "TourBisn.h"
TourBisn::TourBisn(const char* n, const char* sn, const char* mn, int y, int l, int p) : Human(n, sn, mn, y)
{
	Businessman::m_LicenseNum = l;
	Tourist::m_PassportID = p;
	m_Address = new char*[NUM];
	for (int i = 0; i < NUM; i++)
	{
		m_Address[i] = new char[80];
		strcpy(m_Address[i], "");
	}
	cout << "TourBisn constructor" << endl;
}
TourBisn::~TourBisn()
{
	for (int i = 0; i < NUM; i++)
	{
		delete[] m_Address[i];
	}
	delete[] m_Address;
	cout << "TourBisn destuctor" << endl;
}
const char** const TourBisn::GetAddress()
{
	return const_cast<const char** const>(m_Address);
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
	os << "Address: " << endl;
	for (int i = 0; i < NUM; i++)
	{
		os << "[i+1]: " << aTB.m_Address[i];
	}
	return os;
}