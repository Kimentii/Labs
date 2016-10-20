#include "Businessman.h"
Businessman::Businessman(const char* n, const char* sn, const char* mn, int y, int l) : Human(n, sn, mn, y), m_LicenseNum(l)
{
	for (int i = 0; i < NUM; i++)
	{
		m_Payments[i].PayDate = 0;
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