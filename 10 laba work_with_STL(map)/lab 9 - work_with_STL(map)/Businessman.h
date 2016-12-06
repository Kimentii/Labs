#pragma once
#include "Human.h"
struct TaxPayment																//��������� ������ �������
{
	char PayDate[SIZE];
	int Sum;
};
class Businessman : virtual public Human
{
protected:
	TaxPayment m_Payments[NUM];													//������ ��������(�������)
public:
	Businessman(const char* n = "", const char* sn = "", const char* mn = "", int y = 0);
	const TaxPayment* const GetTaxPayments();									//����������� ��������� �� ������ ��������
	bool AddPayment(const char* d, int s);										//���������� �������
	bool DelPayment(const char* d);												//��������� �������
	friend ostream& operator << (ostream& os, const Businessman& aB);			//���������� �����
	friend istream& operator >> (istream& is, Businessman& aBis);				//���������� ������
};