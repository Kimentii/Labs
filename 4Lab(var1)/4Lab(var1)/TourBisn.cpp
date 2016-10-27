#include "TourBisn.h"
TourBisn::TourBisn(const char* n, const char* sn, const char* mn, int y, int l, int p, int na) : Human(n, sn, mn, y)
{																			//�����������
	Businessman::m_LicenseNum = l;
	Tourist::m_PassportID = p;
	m_NumAddress = na;
	if (na > 0)																//���� ������� ���������� ��������
	{																		//���������� �������, ��
		m_Address = new char*[na];											//��������� ������ ��� ���
		for (int i = 0; i < na; i++)
		{
			m_Address[i] = new char[SIZE];
			strcpy(m_Address[i], "");
		}
	}
	else
	{
		m_Address = nullptr;
	}
	cout << "TourBisn constructor" << endl;
}
TourBisn::TourBisn(const TourBisn& aTurBis)									//����������� �����������
{
	strcpy(m_Name, aTurBis.m_Name);											//����������� ���������� ������
	strcpy(m_SurName, aTurBis.m_SurName);
	strcpy(m_MiddleName, aTurBis.m_MiddleName);
	m_NumAddress = aTurBis.m_NumAddress;
	m_LicenseNum = aTurBis.m_LicenseNum;
	m_PassportID = aTurBis.m_PassportID;
	m_YearOfBirth = aTurBis.m_YearOfBirth;
	for (int i = 0; i < NUM; i++)											//����������� ����������� � �������
	{
		strcpy(m_Travels[i].Country, aTurBis.m_Travels[i].Country);
		strcpy(m_Travels[i].Date, aTurBis.m_Travels[i].Date);
		strcpy(m_Payments[i].PayDate, aTurBis.m_Payments[i].PayDate);
		m_Payments[i].Sum = aTurBis.m_Payments[i].Sum;
	}
	if (aTurBis.m_NumAddress > 0)											//������������� ������������ ������
	{
		m_Address = new char*[aTurBis.m_NumAddress];
		for (int i = 0; i < aTurBis.m_NumAddress; i++)
		{
			m_Address[i] = new char[SIZE];
			strcpy(m_Address[i], aTurBis.m_Address[i]);
		}
	}
}
TourBisn::~TourBisn()														//����������
{
	for (int i = 0; i < m_NumAddress; i++)
	{
		delete[] m_Address[i];
	}
	delete[] m_Address;
	m_NumAddress = 0;
	cout << "TourBisn destuctor" << endl;
}
const char** const TourBisn::GetAddress()									//���������� ������ �������
{
	return const_cast<const char** const>(m_Address);
}
int TourBisn::GetNumAddress()
{
	return 	m_NumAddress;
}
void TourBisn::AddAddress(const char* a)									//���������� ������
{
	if (m_NumAddress > 0)													//���� ���������� ������� �����
	{
		for (int i = 0; i < m_NumAddress; i++)								//����� ������ �������
		{
			if (!strlen(m_Address[i]))
			{
				strcpy(m_Address[i], a);
				return;
			}
		}
		char** buf = new char*[m_NumAddress + 1];							//����� ������������� ������� �����
		buf[m_NumAddress] = new char[SIZE];
		for (int i = 0; i < m_NumAddress; i++)
		{
			buf[i] = m_Address[i];
		}
		strcpy(buf[m_NumAddress], a);										//� ���������� ������ ������
		m_NumAddress++;
		delete[] m_Address;
		m_Address = buf;
	}
	else																	//�������� ������ ������
	{
		m_NumAddress = 1;
		m_Address = new char*[1];
		m_Address[0] = new char[SIZE];
		strcpy(m_Address[0], a);
	}
}
bool TourBisn::DelAddress(const char* a)									//�������� ������
{
	bool x = false;
	if (m_NumAddress > 0)													//���� ������ ����������
	{
		for (int i = 0; i < m_NumAddress; i++)								//����� ������� ������
		{
			if (!strcmp(m_Address[i], a))									//��������� ������� ������
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
//TourBisn TourBisn::operator = (const TourBisn& aTB)
//{
//	dynamic_cast<Tourist&>(*this) = dynamic_cast<const Tourist&>(aTB);
//	this->m_NumAddress = 0;
//	this->m_Address = nullptr;
//	return (*this);
//}
ostream& operator << (ostream& os, const TourBisn& aTB)						//���������� ������
{
	os << dynamic_cast<const Human&>(aTB);									//���������� � ������ Human � �����
	os << "License number: " << aTB.m_LicenseNum << endl;
	os << "Passport ID: " << aTB.m_PassportID << endl;
	os << "His payments: " << endl;
	for (int i = 0; i < NUM; i++)											//����� ��������
	{
		os << "Date: " << aTB.m_Payments[i].PayDate << endl;
		os << "Amount of money: " << aTB.m_Payments[i].Sum << endl;
	}
	os << "Travels:" << endl;
	for (int i = 0; i < NUM; i++)											//����� �����������
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
istream& operator >> (istream& is, TourBisn& aTurBis)						//���������� �����
{
	is >> dynamic_cast<Human&>(aTurBis);									//���������� � ������ Human � ����
	is >> aTurBis.m_LicenseNum;
	is >> aTurBis.m_PassportID;
	for (int i = 0; i < NUM; i++)											//���� ��������
	{
		is >> aTurBis.m_Payments[i].PayDate;
		is >> aTurBis.m_Payments[i].Sum;
	}
	for (int i = 0; i < NUM; i++)											//���� �����������
	{
		is >> aTurBis.m_Travels[i].Date;
		is >> aTurBis.m_Travels[i].Country;
	}
	return is;
}