#include "Tourist.h"
Tourist::Tourist(const char* n, const char* sn, const char* mn, int y, int p) : Human(n, sn, mn, y), m_PassportID(p)
{
	for (int i = 0; i < NUM; i++)
	{
		strcpy(m_Travels[i].Date, "");
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
void Tourist::SetPassportID(int p)
{
	m_PassportID = p;
}
bool Tourist::AddTravel(const char* c, const char* d)
{
	int i;
	for (i = 0; i < NUM; i++)
	{
		if (!strlen(m_Travels[i].Date)) break;
	}
	if (i < NUM)
	{
		strcpy(m_Travels[i].Date, d);
		strcpy(m_Travels[i].Country, c);
		return true;
	}
	else return false;
}
bool Tourist::DelTravel(const char* c, const char* d)
{
	bool x = false;
	int i;
	if (strlen(c) && strlen(d))
	{
		for (i = 0; i < NUM; i++)
		{
			if (!strcmp(m_Travels[i].Country, c) && !strcmp(m_Travels[i].Date, d))
			{
				strcpy(m_Travels[i].Country, "");
				strcpy(m_Travels[i].Date, "");
				x = true;
			}
		}
	}
	else
	{
		if (strlen(c))
		{
			for (i = 0; i < NUM; i++)
			{
				if (!strcmp(m_Travels[i].Country, c))
				{
					strcpy(m_Travels[i].Country, "");
					strcpy(m_Travels[i].Date, "");
					x = true;
				}
			}
		}
		else
		{
			for (i = 0; i < NUM; i++)
			{
				if (!strcmp(m_Travels[i].Date, d))
				{
					strcpy(m_Travels[i].Country, "");
					strcpy(m_Travels[i].Date, "");
					x = true;
				}
			}
		}
	}
	return x;
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