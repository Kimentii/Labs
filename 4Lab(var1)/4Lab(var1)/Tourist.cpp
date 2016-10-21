#include "Tourist.h"
Tourist::Tourist(const char* n, const char* sn, const char* mn, int y, int p) : Human(n, sn, mn, y), m_PassportID(p)
{
	for (int i = 0; i < NUM; i++)
	{
		m_Travels[i].Date = 0;
		strcpy(m_Travels[i].Country, "");
	}
	cout << "Tourist constructor" << endl;
}
int Tourist::GetPassportID()
{
	return m_PassportID;
}
const Travel* const Tourist::GetTravels()
{
	return m_Travels;
}
ostream& operator << (ostream& os, const Tourist& aT)
{
	os << dynamic_cast<const Human&>(aT);
	os << "Passport ID: " << aT.m_PassportID << endl;
	os << "Travels:" << endl;
	for (int i = 0; i < NUM; i++)
	{
		os << "Country: " << aT.m_Travels[i].Country << endl;
		os << "Date: " << aT.m_Travels[i].Date << endl;
	}
	return os;
}