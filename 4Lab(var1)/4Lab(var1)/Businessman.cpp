#include "Businessman.h"
Businessman::Businessman(const char* n, const char* sn, const char* mn, int y, int l) : Human(n, sn, mn, y), m_LicenseNum(l)
{
	for (int i = 0; i < NUM; i++)
	{
		strcpy(m_Payments[i].PayDate, "");
		m_Payments[i].Sum = 0;
	}
	cout << "Businessman constuctor" << endl;
}
int Businessman::GetLicenseNum()
{
	return m_LicenseNum;
}
const TaxPayment* const Businessman::GetTaxPayments()
{
	return m_Payments;
}
void Businessman::SetLicenseNum(int num)
{
	m_LicenseNum = num;
}
bool Businessman::AddPayment(const char* d, int s)
{
	int i;
	for (i = 0; i < NUM; i++)
	{
		if (m_Payments[i].Sum <= 0) break;
	}
	if (i < NUM)
	{
		strcpy(m_Payments[i].PayDate, d);
		m_Payments[i].Sum = s;
		return true;
	}
	else return false;
}
bool Businessman::DelPayment(const char* d)
{
	int i;
	bool x = false;
	for (i = 0; i < NUM; i++)
	{
		if (!strcmp(m_Payments[i].PayDate, d))
		{
			strcpy(m_Payments[i].PayDate, "");
			m_Payments[i].Sum = 0;
			x = true;
		}
	}
	return x;
}
ostream& operator << (ostream& os, const Businessman& aB)
{
	os << dynamic_cast<const Human&>(aB);
	os << "License number: " << aB.m_LicenseNum << endl;
	os << "His payments: " << endl;
	for (int i = 0; i < NUM; i++)
	{
		os << "Date: " << aB.m_Payments[i].PayDate << endl;
		os << "Amount of money: " << aB.m_Payments[i].Sum << endl;
	}
	return os;
}