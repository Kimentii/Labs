#pragma once
#include "Human.h"
struct TaxPayment
{
	char PayDate[SIZE];
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
	void SetLicenseNum(int num);
	bool AddPayment(const char* d, int s);
	bool DelPayment(const char* d);
	friend ostream& operator << (ostream& os, const Businessman& aB);
};