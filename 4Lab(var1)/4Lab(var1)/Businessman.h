#pragma once
#include "Human.h"
struct TaxPayment
{
	int PayDate;
	int Sum;
};
class Businessman : virtual public Human
{
protected:
	TaxPayment m_Payments[NUM];
	int m_LicenseNum;
public:
	Businessman(const char* n = "", const char* sn = "", const char* mn = "", int y = 0, int l = 0);
	int GetLicenseNum();
	const TaxPayment* const GetTaxPayments();
	friend ostream& operator << (ostream& os, const Businessman& aB);
};