#include "Businessman.h"
Businessman::Businessman(const char* n, const char* sn, const char* mn, int y, int l) : Human(n, sn, mn, y), m_LicenseNum(l)
{																			//�����������
	for (int i = 0; i < NUM; i++)											//��������� �����
	{
		strcpy(m_Payments[i].PayDate, "");
		m_Payments[i].Sum = 0;
	}
	cout << "Businessman constuctor" << endl;
}
int Businessman::GetLicenseNum()											//����������� ������ ��������
{
	return m_LicenseNum;
}
const TaxPayment* const Businessman::GetTaxPayments()						//����������� ������� ��������
{
	return m_Payments;
}
void Businessman::SetLicenseNum(int num)									//��������� ������ ��������
{
	m_LicenseNum = num;
}
bool Businessman::AddPayment(const char* d, int s)							//���������� �������
{
	int i;
	for (i = 0; i < NUM; i++)
	{
		if (m_Payments[i].Sum <= 0) break;									//���� ���� ��������� �����
	}
	if (i < NUM)															//�� ��������� ���� ������
	{
		strcpy(m_Payments[i].PayDate, d);
		m_Payments[i].Sum = s;
		return true;
	}
	else return false;
}
bool Businessman::DelPayment(const char* d)									//�������� �������
{
	int i;
	bool x = false;
	for (i = 0; i < NUM; i++)												//����� �� ����
	{
		if (!strcmp(m_Payments[i].PayDate, d))
		{
			strcpy(m_Payments[i].PayDate, "");								//��������� �������� ������
			m_Payments[i].Sum = 0;
			x = true;
		}
	}
	return x;
}
ostream& operator << (ostream& os, const Businessman& aB)					//���������� ������
{
	os << dynamic_cast<const Human&>(aB);
	os << setw(20) << "Date" << setw(20) << "Sum" << endl;
	for (int i = 0; i < NUM; i++)
	{
		os << '[' << i << "]: ";
		os << setw(15) << aB.m_Payments[i].PayDate;
		os << setw(20) << aB.m_Payments[i].Sum;
		os << endl;
	}
	os << "License number: ";
	os << aB.m_LicenseNum << endl;
	return os;
}
istream& operator >> (istream& is, Businessman& aBis)						//���������� �����
{
	is >> dynamic_cast<Human&>(aBis);										//���������� � �������� ������ � ����
	cout << "Enter license number: ";
	is >> aBis.m_LicenseNum;
	for (int i = 0; i < NUM; i++)
	{
		cout << "Enter date: ";
		is >> aBis.m_Payments[i].PayDate;
		cout << "Enter sum: ";
		is >> aBis.m_Payments[i].Sum;
	}
	return is;
}