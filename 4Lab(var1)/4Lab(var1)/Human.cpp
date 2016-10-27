#include "Human.h"
Human::Human(const char* n, const char* sn, const char* mn, int y) : m_YearOfBirth(y)
{																	//�����������
	strcpy(m_Name, n);
	strcpy(m_SurName, sn);
	strcpy(m_MiddleName, mn);
	cout << "Human constructor" << endl;
}
const char* const Human::GetName()									//����������� �����
{
	return m_Name;
}
const char* const Human::GetSurName()								//����������� �������
{
	return m_SurName;
}
const char* const Human::GetMiddleName()							//����������� ��������
{
	return m_MiddleName;
}
int Human::GetYear()												//����������� ���� ��������
{
	return m_YearOfBirth;
}
void Human::SetName(const char* n)									//��������� �����
{
	strcpy(m_Name, n);
}
void Human::SetSurName(const char* sn)								//��������� �������
{
	strcpy(m_SurName, sn);
}
void Human::SetMiddleName(const char* mn)							//��������� ��������
{
	strcpy(m_MiddleName, mn);
}
void Human::SetYearOfBirth(int y)									//��������� ���� ��������
{
	m_YearOfBirth = y;
}
ostream& operator << (ostream& os,const Human& aHum)				//���������� ������
{
	os << setw(20) << "Name" << setw(20) <<"Surname" << setw(20) << "Middle name" << endl;
	os << setw(20) << aHum.m_SurName;
	os << setw(20) << aHum.m_MiddleName;
	os << setw(20) << aHum.m_YearOfBirth;
	os << endl;
	return os;
}
istream& operator >> (istream& is, Human& aHum)						//���������� �����
{
	cout << "Enter name: ";
	is >> aHum.m_Name;
	cout << "Enter Surname: ";
	is >> aHum.m_SurName;
	cout << "Enter middle name: ";
	is >> aHum.m_MiddleName;
	cout << "Enter year of birth: ";
	is >> aHum.m_YearOfBirth;
	return is;
}