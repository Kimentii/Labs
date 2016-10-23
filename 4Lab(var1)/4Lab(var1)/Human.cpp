#include "Human.h"
Human::Human(const char* n, const char* sn, const char* mn, int y) : m_YearOfBirth(y)
{
	strcpy(m_Name, n);
	strcpy(m_SurName, sn);
	strcpy(m_MiddleName, mn);
	cout << "Human constructor" << endl;
}
const char* const Human::GetName()
{
	return m_Name;
}
const char* const Human::GetSurName()
{
	return m_SurName;
}
const char* const Human::GetMiddleName()
{
	return m_MiddleName;
}
int Human::GetYear()
{
	return m_YearOfBirth;
}
void Human::SetName(const char* n)
{
	strcpy(m_Name, n);
}
void Human::SetSurName(const char* sn)
{
	strcpy(m_SurName, sn);
}
void Human::SetMiddleName(const char* mn)
{
	strcpy(m_MiddleName, mn);
}
void Human::SetYearOfBirth(int y)
{
	m_YearOfBirth = y;
}
ostream& operator << (ostream& os,const Human& aHum)
{
	os << "Name: " << aHum.m_Name << endl;
	os << "Surame: " << aHum.m_SurName << endl;
	os << "Middle name: " << aHum.m_MiddleName << endl;
	os << "Year of birth: " << aHum.m_YearOfBirth << endl;
	return os;
}