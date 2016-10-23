#include "TourBisn.h"
TourBisn::TourBisn(const char* n, const char* sn, const char* mn, int y, int l, int p, int na) : Human(n, sn, mn, y)
{
	Businessman::m_LicenseNum = l;
	Tourist::m_PassportID = p;
	m_NumAddress = na;
	if (na > 0)
	{
		m_Address = new char*[na];
		for (int i = 0; i < na; i++)
		{
			m_Address[i] = new char[SIZE];
			strcpy(m_Address[i], "");
		}
	}
	cout << "TourBisn constructor" << endl;
}
TourBisn::~TourBisn()
{
	for (int i = 0; i < m_NumAddress; i++)
	{
		delete[] m_Address[i];
	}
	delete[] m_Address;
	m_NumAddress = 0;
	cout << "TourBisn destuctor" << endl;
}
const char** const TourBisn::GetAddress()
{
	return const_cast<const char** const>(m_Address);
}
int TourBisn::GetNumAddress()
{
	return 	m_NumAddress;
}
void TourBisn::AddAddress(const char* a)
{
	if (m_NumAddress > 0)
	{
		for (int i = 0; i < m_NumAddress; i++)
		{
			if (!strlen(m_Address[i]))
			{
				strcpy(m_Address[i], a);
				return;
			}
		}
		char** buf = new char*[m_NumAddress + 1];
		buf[m_NumAddress] = new char[SIZE];
		for (int i = 0; i < m_NumAddress; i++)
		{
			buf[i] = m_Address[i];
		}
		strcpy(buf[m_NumAddress], a);
		m_NumAddress++;
		delete[] m_Address;
		m_Address = buf;
	}
	else
	{
		m_NumAddress = 1;
		m_Address = new char*[1];
		m_Address[0] = new char[SIZE];
		strcpy(m_Address[0], a);
	}
}
bool TourBisn::DelAddress(const char* a)
{
	bool x = false;
	if (m_NumAddress > 0)
	{
		for (int i = 0; i < m_NumAddress; i++)
		{
			if (!strcmp(m_Address[i], a))
			{
				strcpy(m_Address[i], "");
				x = true;
			}
		}
	}
	else
	{
		return false;
	}
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
	for (int i = 0; i < aTB.m_NumAddress; i++)
	{
		os << "[" << i+1 << "]: " << aTB.m_Address[i] << endl;
	}
	return os;
}